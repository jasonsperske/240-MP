import QtQuick
import Components

// Ride Check: the bike's live readings, the exercise settings (also under Settings > Modules),
// and the shape of the chosen workout over a 30-minute video. Exercise mode itself runs in the
// player; this screen is for checking the bike works and picking a ride.
FocusScope {
    id: checkRoot

    property var navParams: ({})
    property var navListState: navParams.navListState || ({})

    signal navigateTo(string path, var params, var listState)
    signal goBack()

    focus: true

    readonly property var workouts: ["Steady", "Intervals", "Hills", "Spin Class"]
    readonly property var difficulties: ["Easy", "Moderate", "Hard", "Expert"]
    readonly property int previewMinutes: 30

    // Rows: 0 exercise mode, 1 workout, 2 difficulty, 3 bike diagnostics
    property int focusRow: 0
    property bool exerciseOn: true
    property string workout: "Steady"
    property string difficulty: "Moderate"
    property var preview: ({})
    readonly property int segmentCount: preview.segments ? preview.segments.length : 0

    function toggleValue(v, fallback) {
        if (v === undefined || v === null || v === "") return fallback
        return v === true || v === "ON" || v === "true"
    }

    function refreshPreview() {
        preview = exerciseBackend.previewProgram(workout, difficulty, previewMinutes)
    }

    function cycle(list, current, direction) {
        var i = list.indexOf(current)
        if (i < 0) i = 0
        return list[(i + direction + list.length) % list.length]
    }

    function change(direction) {
        if (focusRow === 0) {
            exerciseOn = !exerciseOn
            appCore.save_setting(moduleRoot.moduleId, "exercise_mode", exerciseOn)
        } else if (focusRow === 1) {
            workout = cycle(workouts, workout, direction)
            appCore.save_setting(moduleRoot.moduleId, "workout", workout)
            refreshPreview()
        } else if (focusRow === 2) {
            difficulty = cycle(difficulties, difficulty, direction)
            appCore.save_setting(moduleRoot.moduleId, "difficulty", difficulty)
            refreshPreview()
        }
    }

    Component.onCompleted: {
        exerciseOn = toggleValue(appCore.get_setting(moduleRoot.moduleId, "exercise_mode"), true)
        workout = appCore.get_setting(moduleRoot.moduleId, "workout") || "Steady"
        difficulty = appCore.get_setting(moduleRoot.moduleId, "difficulty") || "Moderate"
        if (navListState.focusRow !== undefined) focusRow = navListState.focusRow
        refreshPreview()
        exerciseBackend.startMonitoring()
    }
    Component.onDestruction: exerciseBackend.stopMonitoring()

    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_Escape || event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
            goBack()
        } else if (event.key === Qt.Key_Up) {
            focusRow = (focusRow + 3) % 4
        } else if (event.key === Qt.Key_Down) {
            focusRow = (focusRow + 1) % 4
        } else if (event.key === Qt.Key_Left) {
            change(-1)
        } else if (event.key === Qt.Key_Right) {
            change(1)
        } else if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
            if (focusRow === 3) exerciseBackend.openDiagnostics()
            else change(1)
        } else {
            return
        }
        event.accepted = true
    }

    AppBar {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: root.sh * 0.125
        anchors.leftMargin: root.sw * 0.125
        iconSource: moduleRoot.moduleIcon
        title: moduleRoot.moduleName
    }

    Item {
        id: body
        anchors.top: parent.top
        anchors.topMargin: root.sh * 0.23
        anchors.horizontalCenter: parent.horizontalCenter
        width: root.sw * 0.76875
        height: root.sh * 0.6

        // ── The bike, live ──────────────────────────────────────────────────────────────
        Text {
            id: bikeLabel
            text: "Bike:"
            color: root.secondaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0291667
            leftPadding: root.sw * 0.009375
        }
        Text {
            id: bikeState
            anchors.left: bikeLabel.right
            anchors.right: parent.right
            anchors.baseline: bikeLabel.baseline
            text: exerciseBackend.absent ? "No Peloton sensor service on this device"
                : exerciseBackend.live ? "Connected"
                : exerciseBackend.state
            elide: Text.ElideRight
            color: exerciseBackend.live ? root.accentColor : root.tertiaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0291667
            leftPadding: root.sw * 0.009375
        }

        Row {
            id: readings
            anchors.top: bikeLabel.bottom
            anchors.topMargin: root.sh * 0.0145833
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: root.sw * 0.06

            Repeater {
                model: [
                    { label: "Cadence", value: exerciseBackend.rpm, unit: "RPM" },
                    { label: "Resistance", value: exerciseBackend.resistance, unit: "%" },
                    { label: "Output", value: exerciseBackend.watts, unit: "W" }
                ]
                Column {
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: exerciseBackend.live ? modelData.value : "--"
                        color: root.primaryColor
                        font.family: root.globalFont
                        font.pixelSize: root.sh * 0.0833333
                    }
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: modelData.label + " " + modelData.unit
                        color: root.tertiaryColor
                        font.family: root.globalFont
                        font.capitalization: Font.AllUppercase
                        font.pixelSize: root.sh * 0.025
                    }
                }
            }
        }

        // ── Settings rows ───────────────────────────────────────────────────────────────
        Column {
            id: rows
            anchors.top: readings.bottom
            anchors.topMargin: root.sh * 0.025
            anchors.left: parent.left
            anchors.right: parent.right

            Repeater {
                model: [
                    { label: "Exercise Mode", value: checkRoot.exerciseOn ? "ON" : "OFF", arrows: true },
                    { label: "Workout", value: checkRoot.workout, arrows: true },
                    { label: "Difficulty", value: checkRoot.difficulty, arrows: true },
                    { label: "Bike Diagnostics", value: "", arrows: false }
                ]
                Item {
                    width: rows.width
                    height: root.sh * 0.0583333
                    readonly property bool focused: checkRoot.focusRow === index

                    Rectangle {
                        anchors.fill: parent
                        color: parent.focused ? root.accentColor : "transparent"
                    }
                    Text {
                        text: modelData.label
                        color: parent.focused ? root.surfaceColor : root.primaryColor
                        font.family: root.globalFont
                        font.capitalization: Font.AllUppercase
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: root.sw * 0.009375
                        font.pixelSize: root.sh * 0.0416667
                    }
                    Text {
                        text: modelData.arrows ? "◄ " + modelData.value + " ►" : ""
                        color: parent.focused ? root.surfaceColor : root.primaryColor
                        font.family: root.globalFont
                        font.capitalization: Font.AllUppercase
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: root.sw * 0.009375
                        font.pixelSize: root.sh * 0.0416667
                    }
                }
            }
        }

        // ── The workout's shape over a 30-minute video ──────────────────────────────────
        Text {
            id: previewLabel
            anchors.top: rows.bottom
            anchors.topMargin: root.sh * 0.025
            text: checkRoot.exerciseOn
                ? "A " + checkRoot.previewMinutes + " min video: " + segmentCount + (segmentCount === 1 ? " segment" : " segments")
                : "Exercise mode is off: videos play without the bike"
            color: root.secondaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.0291667
            leftPadding: root.sw * 0.009375
        }

        // One bar per segment: height is the target resistance, the label under it the target cadence.
        Item {
            id: profile
            anchors.top: previewLabel.bottom
            anchors.topMargin: root.sh * 0.0145833
            anchors.left: parent.left
            anchors.right: parent.right
            height: root.sh * 0.09
            opacity: checkRoot.exerciseOn ? 1.0 : 0.3
            readonly property real lengthMs: preview.lengthMs || 1

            Repeater {
                model: preview.segments || []
                Rectangle {
                    x: modelData.startMs / profile.lengthMs * profile.width
                    width: Math.max(1, (modelData.endMs - modelData.startMs) / profile.lengthMs * profile.width - 2)
                    height: profile.height * (0.2 + 0.8 * modelData.resistance / 100)
                    anchors.bottom: parent.bottom
                    color: modelData.label === "SPRINT" ? root.accentColor
                         : modelData.label === "RECOVER" || modelData.label === "WARM UP" || modelData.label === "COOL DOWN" ? root.tertiaryColor
                         : root.secondaryColor
                }
            }
        }
        Text {
            anchors.top: profile.bottom
            anchors.topMargin: root.sh * 0.008
            anchors.left: parent.left
            text: {
                var s = preview.segments || []
                if (s.length === 0) return ""
                var lo = 999, hi = 0, rlo = 999, rhi = 0
                for (var i = 0; i < s.length; i++) {
                    lo = Math.min(lo, s[i].rpm); hi = Math.max(hi, s[i].rpm)
                    rlo = Math.min(rlo, s[i].resistance); rhi = Math.max(rhi, s[i].resistance)
                }
                return (lo === hi ? lo : lo + "-" + hi) + " RPM   RESISTANCE " + (rlo === rhi ? rlo : rlo + "-" + rhi)
            }
            color: root.tertiaryColor
            font.family: root.globalFont
            font.capitalization: Font.AllUppercase
            font.pixelSize: root.sh * 0.025
            leftPadding: root.sw * 0.009375
        }
    }

    Text {
        id: footer
        text: root.hints.back + ":BACK " + root.hints.navigate + ":NAVIGATE " + root.hints.change + ":CHANGE " + root.hints.select + ":SELECT"
        color: root.tertiaryColor
        font.family: root.globalFont
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: root.sh * 0.1041667
        anchors.leftMargin: root.sw * 0.125
        font.pixelSize: root.sh * 0.0333333
    }
}
