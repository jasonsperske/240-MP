import QtQuick
import Components

// Sign in to an SMB share: server, share, username, password (and a domain, rarely needed).
// Up/Down move between fields; typing goes into the focused one. On the tablet, tapping a
// field brings up Android's keyboard. The form sits in the top half of the screen so the
// keyboard doesn't cover it. Connect tries the sign-in and saves only if it works.
FocusScope {
    id: setupRoot
    focus: true

    property var navParams: ({})

    signal navigateTo(string path, var params, var listState)
    signal replaceWith(string path, var params)
    signal goBack()

    readonly property var saved: networkSharesBackend.serverSettings()
    property bool waiting: false
    property string errorMsg: ""

    // Rows 0-4 are the fields below, 5 is Connect.
    property int focusIndex: 0
    readonly property int connectRow: fields.length

    readonly property var fields: [
        { key: "host",     label: "Server",   hint: "nas.local or 192.168.1.20", secret: false },
        { key: "share",    label: "Share",    hint: "Videos", secret: false },
        { key: "username", label: "Username", hint: "", secret: false },
        { key: "password", label: "Password", hint: saved.hasPassword ? "(saved)" : "", secret: true },
        { key: "domain",   label: "Domain",   hint: "(usually blank)", secret: false }
    ]
    property var values: ({
        host: saved.host || "",
        share: saved.share || "",
        username: saved.username || "",
        password: "",
        domain: saved.domain || ""
    })

    function setValue(key, text) {
        var v = Object.assign({}, values)
        v[key] = text
        values = v
    }

    function connect() {
        if (waiting) return
        if (values.host.trim() === "" || values.share.trim() === "") {
            errorMsg = "Enter the server and the share"
            return
        }
        Qt.inputMethod.hide()
        waiting = true
        errorMsg = ""
        networkSharesBackend.connectToShare(values.host, values.share, values.username, values.password, values.domain)
    }

    Connections {
        target: networkSharesBackend
        function onConnectResult(ok, message) {
            setupRoot.waiting = false
            // Opened from the browser: go back to it, and it reloads with the new settings.
            if (ok && setupRoot.navParams.fromBrowser) setupRoot.goBack()
            else if (ok) setupRoot.replaceWith("Items.qml", {})
            else setupRoot.errorMsg = message
        }
    }

    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_Shift || event.key === Qt.Key_Control ||
            event.key === Qt.Key_Alt || event.key === Qt.Key_Meta || event.key === Qt.Key_AltGr)
            return
        if (event.key === Qt.Key_Escape || event.key === Qt.Key_Back) {
            Qt.inputMethod.hide()
            goBack()
        } else if (waiting) {
            // Ignore input while signing in.
        } else if (event.key === Qt.Key_Up) {
            focusIndex = Math.max(0, focusIndex - 1)
        } else if (event.key === Qt.Key_Down) {
            focusIndex = Math.min(connectRow, focusIndex + 1)
        } else if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
            // Enter on a field moves on (the Android keyboard's Done/Next does the same), and
            // on the last field or the button, connects.
            if (focusIndex < connectRow - 1) focusIndex++
            else connect()
        } else {
            return
        }
        event.accepted = true
    }

    AppBar {
        iconSource: moduleRoot.moduleIcon
        title: moduleRoot.moduleName
        subtitle: "Connect to a share"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: root.sh * 0.125
        anchors.leftMargin: root.sw * 0.125
    }

    Column {
        id: form
        anchors.top: parent.top
        anchors.topMargin: root.sh * 0.21
        anchors.horizontalCenter: parent.horizontalCenter
        width: root.sw * 0.6
        spacing: root.sh * 0.008

        Repeater {
            model: setupRoot.fields
            Item {
                width: form.width
                height: root.sh * 0.056
                readonly property bool focused: setupRoot.focusIndex === index

                Text {
                    id: label
                    width: parent.width * 0.3
                    anchors.verticalCenter: parent.verticalCenter
                    text: modelData.label
                    color: parent.focused ? root.accentColor : root.secondaryColor
                    font.family: root.globalFont
                    font.capitalization: Font.AllUppercase
                    font.pixelSize: root.sh * 0.0333333
                }
                Rectangle {
                    anchors.left: label.right
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    height: parent.height
                    color: root.surfaceColor
                    border.color: parent.focused ? root.accentColor : root.tertiaryColor
                    border.width: root.sh * 0.003125

                    TextInput {
                        id: input
                        anchors.fill: parent
                        anchors.leftMargin: root.sh * 0.0145
                        anchors.rightMargin: root.sh * 0.0145
                        verticalAlignment: TextInput.AlignVCenter
                        text: setupRoot.values[modelData.key]
                        echoMode: modelData.secret ? TextInput.Password : TextInput.Normal
                        inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhNoPredictiveText
                                          | (modelData.secret ? Qt.ImhSensitiveData | Qt.ImhHiddenText : 0)
                        color: root.primaryColor
                        font.family: root.globalFont
                        font.pixelSize: root.sh * 0.034
                        clip: true
                        focus: parent.parent.focused
                        onTextChanged: if (text !== setupRoot.values[modelData.key]) setupRoot.setValue(modelData.key, text)
                        // A tap on the field selects its row.
                        onActiveFocusChanged: if (activeFocus) setupRoot.focusIndex = index
                        // Let Up/Down/Enter/Escape reach the form's handler.
                        Keys.onPressed: function(event) { event.accepted = false }

                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            visible: input.text === ""
                            text: modelData.hint
                            color: root.tertiaryColor
                            font.family: root.globalFont
                            font.pixelSize: root.sh * 0.03
                        }
                    }
                }
            }
        }

        Rectangle {
            id: connectButton
            anchors.horizontalCenter: parent.horizontalCenter
            width: root.sw * 0.234375
            height: root.sh * 0.0583333
            readonly property bool focused: setupRoot.focusIndex === setupRoot.connectRow
            color: focused ? root.accentColor : root.surfaceColor
            border.color: focused ? root.accentColor : root.tertiaryColor
            border.width: root.sh * 0.003125

            Text {
                anchors.centerIn: parent
                text: setupRoot.waiting ? "Connecting..." : "Connect"
                color: parent.focused ? root.surfaceColor : root.primaryColor
                font.family: root.globalFont
                font.capitalization: Font.AllUppercase
                font.pixelSize: root.sh * 0.0375
            }
        }

        Text {
            visible: setupRoot.errorMsg !== ""
            width: form.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            text: setupRoot.errorMsg
            color: root.accentColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0333333
        }
    }

    // On the tablet, bring the keyboard up for a field reached with the pad or a remote.
    onFocusIndexChanged: {
        if (Qt.platform.os === "android") {
            if (focusIndex < connectRow) Qt.inputMethod.show()
            else Qt.inputMethod.hide()
        }
    }

    Text {
        text: root.hints.back + ":BACK " + root.hints.navigate + ":NAVIGATE " + root.hints.select + ":NEXT / CONNECT"
        color: root.tertiaryColor
        font.family: root.globalFont
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: root.sh * 0.1041667
        anchors.leftMargin: root.sw * 0.125
        font.pixelSize: root.sh * 0.0333333
    }
}
