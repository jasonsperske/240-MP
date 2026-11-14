import QtQuick

// Plays a video from the share: offers to resume where it was left (per the Resume Playback
// setting), then hands the smb:// address to mpvController, which on Android is the
// PlayerActivity, so exercise mode applies as for any other video. Subtitle files next to the
// video (Movie.srt, Movie.en.srt) are loaded with it.
FocusScope {
    id: playerRoot

    property var navParams: ({})

    signal goBack()

    property string filePath: navParams.filePath || ""
    property string itemTitle: navParams.title || ""
    property var subtitlePaths: navParams.subtitles || []

    property bool overlayVisible: false
    property int choiceIndex: 0
    property var choices: []
    property string errorMsg: ""

    property int lastKnownPositionMs: 0
    property int lastKnownDurationMs: 0

    focus: true

    Keys.onPressed: function(event) {
        if (errorMsg !== "") {
            goBack()
            event.accepted = true
        } else if (overlayVisible) {
            if (event.key === Qt.Key_Escape || event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
                goBack()
            } else if (event.key === Qt.Key_Up) {
                if (choiceIndex > 0) choiceIndex--
            } else if (event.key === Qt.Key_Down) {
                if (choiceIndex < choices.length - 1) choiceIndex++
            } else if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                overlayVisible = false
                play(choices[choiceIndex].startMs)
            } else {
                return
            }
            event.accepted = true
        }
    }

    Connections {
        target: mpvController
        function onPositionChanged(ms) { if (ms > 0) playerRoot.lastKnownPositionMs = ms }
        function onDurationChanged(ms) { if (ms > 0) playerRoot.lastKnownDurationMs = ms }
        function onPlaybackEnded(finalPositionMs, finalDurationMs, reason) {
            var pos = playerRoot.lastKnownPositionMs || finalPositionMs
            var dur = playerRoot.lastKnownDurationMs || finalDurationMs
            if (dur > 0 && pos >= dur * 0.95)
                networkSharesBackend.clearPosition(playerRoot.filePath)
            else if (pos > 5000)
                networkSharesBackend.savePosition(playerRoot.filePath, pos)
            if (reason === "failed") {
                // Stay on screen to say so, even if it failed partway (the position is kept);
                // any key goes back. Diagnostics has the details.
                playerRoot.errorMsg = "Couldn't play this file"
                return
            }
            playerRoot.goBack()
        }
    }

    Component.onCompleted: {
        if (filePath === "") return
        var resume = appCore.get_setting(moduleRoot.moduleId, "resume_playback") || "Ask"
        var saved = resume === "Never" ? {} : networkSharesBackend.getSavedPosition(filePath)
        var savedPos = saved.pos || 0
        if (savedPos <= 0 || resume === "Always") {
            play(savedPos)
            return
        }
        choices = [
            { label: "Resume from " + formatTime(savedPos), startMs: savedPos },
            { label: "Start from the beginning", startMs: 0 }
        ]
        choiceIndex = 0
        overlayVisible = true
    }

    function play(startMs) {
        var subs = networkSharesBackend.mediaUrls(subtitlePaths)
        // 0: turn on the first subtitle file; -1: only forced subtitles in the video itself.
        var subTrack = subs.length > 0 ? 0 : -1
        mpvController.loadAndPlay(networkSharesBackend.mediaUrl(filePath), startMs > 0 ? startMs / 1000.0 : 0.0,
                                  0, subTrack, subs, [], false, -1, 0.0, "", false, "", false, [], 0.0, false)
    }

    function formatTime(ms) {
        var s = Math.floor(ms / 1000), h = Math.floor(s / 3600), m = Math.floor((s % 3600) / 60), sec = s % 60
        function pad(n) { return n < 10 ? "0" + n : "" + n }
        return h > 0 ? h + ":" + pad(m) + ":" + pad(sec) : m + ":" + pad(sec)
    }

    Rectangle {
        anchors.fill: parent
        color: overlayVisible || errorMsg !== "" ? root.surfaceColor : "black"
    }

    Column {
        anchors.centerIn: parent
        spacing: root.sh * 0.05
        visible: errorMsg !== ""
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: errorMsg
            color: root.primaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.05
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: itemTitle
            color: root.tertiaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0333333
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: root.hints.back + ":BACK"
            color: root.tertiaryColor
            font.family: root.globalFont
            font.pixelSize: root.sh * 0.0333333
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: root.sh * 0.05
        visible: overlayVisible
        width: root.sw * 0.76875

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "RESUME PLAYBACK?"
            color: root.secondaryColor
            font.family: root.globalFont
            font.pixelSize: root.sh * 0.0333333
        }
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                model: choices
                Item {
                    width: root.sw * 0.76875
                    height: root.sh * 0.0583333
                    Rectangle {
                        anchors.fill: choiceText
                        color: root.accentColor
                        visible: index === choiceIndex
                    }
                    Text {
                        id: choiceText
                        anchors.centerIn: parent
                        text: modelData.label
                        color: index === choiceIndex ? root.surfaceColor : root.primaryColor
                        font.family: root.globalFont
                        font.capitalization: Font.AllUppercase
                        topPadding: root.sh * 0.0041667
                        leftPadding: root.sw * 0.009375
                        rightPadding: root.sw * 0.009375
                        bottomPadding: root.sh * 0.00625
                        font.pixelSize: root.sh * 0.0416667
                    }
                }
            }
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: root.hints.back + ":BACK " + root.hints.navigate + ":NAVIGATE " + root.hints.select + ":SELECT"
            color: root.tertiaryColor
            font.family: root.globalFont
            font.pixelSize: root.sh * 0.0333333
        }
    }
}
