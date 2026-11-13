import QtQuick
import Components

// One folder of the share: subfolders, then videos. Listing goes over the network, so the
// view shows LOADING... until networkSharesBackend answers, and an error with a retry if it
// can't (the NAS asleep, Wi-Fi down, the password changed).
FocusScope {
    id: itemsRoot

    property var navParams: ({})
    property var navListState: navParams.navListState || ({})
    property string folderPath: navParams.folderPath || ""
    property string folderName: navParams.folderName || ""

    signal navigateTo(string path, var params, var listState)
    signal replaceWith(string path, var params)
    signal goBack()

    property int requestId: -1
    property bool loading: true
    property string errorMsg: ""
    property var items: []

    readonly property bool hideExtensions: {
        var v = appCore.get_setting(moduleRoot.moduleId, "hide_extensions")
        return v === true || v === "ON"
    }

    function displayName(item) {
        if (item.isFolder) return item.name + "/"
        if (!hideExtensions) return item.name
        var dot = item.name.lastIndexOf(".")
        return dot > 0 ? item.name.substring(0, dot) : item.name
    }

    function load() {
        loading = true
        errorMsg = ""
        requestId = networkSharesBackend.listFolder(folderPath)
    }

    Connections {
        target: networkSharesBackend
        function onFolderListed(id, path, list, error) {
            if (id !== itemsRoot.requestId) return
            itemsRoot.loading = false
            itemsRoot.errorMsg = error
            itemsRoot.items = list
            if (list.length > 0) {
                var restore = navListState.currentIndex !== undefined ? navListState.currentIndex : 0
                fileList.currentIndex = Math.min(restore, list.length - 1)
                fileList.positionViewAtIndex(fileList.currentIndex, ListView.Contain)
            }
            fileList.forceActiveFocus()
        }
        // Forgotten from Settings while open: back to setup.
        function onAuthStateChanged() {
            if (networkSharesBackend.get_auth_state() !== "authed") itemsRoot.replaceWith("Setup.qml", {})
        }
    }

    Component.onCompleted: load()

    focus: true
    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_Escape || event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
            goBack()
            event.accepted = true
        } else if ((event.key === Qt.Key_Return || event.key === Qt.Key_Enter) && errorMsg !== "") {
            load()
            event.accepted = true
        } else if (event.key === Qt.Key_Left && folderPath === "" && !loading) {
            // From the share's top, Left opens the server setup (to change share or password).
            navigateTo("Setup.qml", { fromBrowser: true }, { currentIndex: fileList.currentIndex })
            event.accepted = true
        }
    }

    AppBar {
        iconSource: moduleRoot.moduleIcon
        title: moduleRoot.moduleName
        subtitle: folderName !== "" ? folderName : (networkSharesBackend.serverSettings().share || "")
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: root.sh * 0.125
        anchors.leftMargin: root.sw * 0.125
    }

    Column {
        anchors.centerIn: parent
        spacing: root.sh * 0.0333333
        visible: loading || errorMsg !== "" || items.length === 0
        width: root.sw * 0.7

        Text {
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            text: loading ? "Loading..." : errorMsg !== "" ? "Can't open this folder" : "No videos here"
            color: root.secondaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.05
        }
        Text {
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            visible: !loading
            text: errorMsg !== "" ? errorMsg : "Only folders and video or audio files are shown"
            color: root.tertiaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0333333
        }
    }

    ListView {
        id: fileList
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: root.sh * 0.25
        anchors.leftMargin: root.sw * 0.115625
        width: root.sw * 0.76875
        height: root.sh * 0.525
        visible: !loading && errorMsg === ""
        model: itemsRoot.items
        clip: true
        focus: true

        Keys.onReturnPressed: function(event) {
            // Hidden while loading or after an error: let the view take Enter (RETRY).
            if (itemsRoot.loading || itemsRoot.errorMsg !== "") { event.accepted = false; return }
            var item = itemsRoot.items[currentIndex]
            if (!item) return
            if (item.isFolder) {
                navigateTo("Items.qml", { folderPath: item.path, folderName: item.name }, { currentIndex: currentIndex })
            } else {
                navigateTo("Player.qml", { filePath: item.path, title: item.name, subtitles: item.subtitles || [] },
                           { currentIndex: currentIndex })
            }
        }
        Keys.onUpPressed: {
            if (count === 0) return
            currentIndex = currentIndex > 0 ? currentIndex - 1 : count - 1
            positionViewAtIndex(currentIndex, ListView.Contain)
        }
        Keys.onDownPressed: {
            if (count === 0) return
            currentIndex = currentIndex < count - 1 ? currentIndex + 1 : 0
            positionViewAtIndex(currentIndex, ListView.Contain)
        }

        delegate: Item {
            width: fileList.width
            height: root.sh * 0.0583333

            Item {
                id: textClip
                width: Math.min(rowText.implicitWidth, fileList.width)
                height: parent.height
                clip: true

                Rectangle {
                    color: root.accentColor
                    anchors.fill: rowText
                    visible: fileList.currentIndex === index
                }
                Text {
                    id: rowText
                    text: itemsRoot.displayName(modelData)
                    color: fileList.currentIndex === index ? root.surfaceColor : root.primaryColor
                    font.family: root.globalFont
                    font.capitalization: Font.AllUppercase
                    anchors.verticalCenter: parent.verticalCenter
                    x: 0
                    topPadding: root.sh * 0.0041667
                    leftPadding: root.sw * 0.009375
                    rightPadding: root.sw * 0.009375
                    bottomPadding: root.sh * 0.00625
                    font.pixelSize: root.sh * 0.05
                }
                SequentialAnimation {
                    running: fileList.currentIndex === index && rowText.implicitWidth > textClip.width
                    loops: Animation.Infinite
                    onRunningChanged: if (!running) rowText.x = 0
                    PauseAnimation { duration: 1500 }
                    NumberAnimation {
                        target: rowText; property: "x"
                        to: textClip.width - rowText.implicitWidth
                        duration: Math.abs(to) * 20
                    }
                    PauseAnimation { duration: 2000 }
                    PropertyAction { target: rowText; property: "x"; value: 0 }
                }
            }
        }
    }

    Text {
        text: errorMsg !== ""
              ? root.hints.back + ":BACK " + root.hints.select + ":RETRY"
              : root.hints.back + ":BACK " + root.hints.navigate + ":NAVIGATE " + root.hints.select + ":SELECT"
                + (folderPath === "" ? " " + root.hints.change + ":SERVER" : "")
        color: root.tertiaryColor
        font.family: root.globalFont
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: root.sh * 0.1041667
        anchors.leftMargin: root.sw * 0.125
        font.pixelSize: root.sh * 0.0333333
    }
}
