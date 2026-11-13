import QtQuick
import Components

// Connection diagnostics: checks the share one step at a time (look up the server, open TCP,
// SMB negotiate, sign in, open the share) and shows the network-share log as it fills in, so a
// share that won't connect says where it stops: the name can't be found, nothing answers on the
// port, the password is wrong, the share doesn't exist. The log also holds earlier sign-ins,
// listings and playback failures from this run of the app.
//
// navParams: host, share, username, password, domain to check (from the setup form), or none
// for the saved settings.
FocusScope {
    id: diagRoot
    focus: true

    property var navParams: ({})

    signal navigateTo(string path, var params, var listState)
    signal replaceWith(string path, var params)
    signal goBack()

    property string logText: ""

    function run() {
        networkSharesBackend.runDiagnostics(navParams.host || "", navParams.share || "", navParams.username || "",
                                            navParams.password || "", navParams.domain || "")
        follow = true
        refresh()
    }

    // Stick to the newest line until the rider scrolls up.
    property bool follow: true

    function refresh() {
        var text = networkSharesBackend.diagnosticsLog()
        if (text === logText) return
        logText = text
        if (follow) Qt.callLater(function() { flick.contentY = Math.max(0, flick.contentHeight - flick.height) })
    }

    Component.onCompleted: {
        Qt.inputMethod.hide()
        run()
    }

    Timer {
        interval: 400
        running: true
        repeat: true
        onTriggered: diagRoot.refresh()
    }

    Keys.onPressed: function(event) {
        var step = logView.font.pixelSize * 3
        if (event.key === Qt.Key_Escape || event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
            goBack()
        } else if (event.key === Qt.Key_Up) {
            flick.contentY = Math.max(0, flick.contentY - step)
            follow = false
        } else if (event.key === Qt.Key_Down) {
            flick.contentY = Math.min(Math.max(0, flick.contentHeight - flick.height), flick.contentY + step)
            follow = flick.contentY >= flick.contentHeight - flick.height - 1
        } else if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
            run()
        } else {
            return
        }
        event.accepted = true
    }

    AppBar {
        iconSource: moduleRoot.moduleIcon
        title: moduleRoot.moduleName
        subtitle: "Diagnostics"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: root.sh * 0.125
        anchors.leftMargin: root.sw * 0.125
    }

    Rectangle {
        id: frame
        anchors.top: parent.top
        anchors.topMargin: root.sh * 0.21
        anchors.bottom: parent.bottom
        anchors.bottomMargin: root.sh * 0.16
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: root.sw * 0.125
        anchors.rightMargin: root.sw * 0.125
        color: root.surfaceColor
        border.color: root.tertiaryColor
        border.width: root.sh * 0.003125

        Flickable {
            id: flick
            anchors.fill: parent
            anchors.margins: root.sh * 0.015
            clip: true
            contentWidth: width
            contentHeight: logView.height
            boundsBehavior: Flickable.StopAtBounds
            onMovementEnded: diagRoot.follow = contentY >= contentHeight - height - 1

            Text {
                id: logView
                width: flick.width
                text: diagRoot.logText !== "" ? diagRoot.logText : "Starting..."
                color: root.primaryColor
                font.family: "monospace"
                font.pixelSize: root.sh * 0.024
                wrapMode: Text.WrapAnywhere
            }
        }
    }

    Text {
        text: root.hints.back + ":BACK " + root.hints.navigate + ":SCROLL " + root.hints.select + ":RUN AGAIN"
        color: root.tertiaryColor
        font.family: root.globalFont
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: root.sh * 0.1041667
        anchors.leftMargin: root.sw * 0.125
        font.pixelSize: root.sh * 0.0333333
    }
}
