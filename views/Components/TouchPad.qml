import QtQuick

// On-screen d-pad for touch-only screens (the Peloton tablet has no keyboard, and a gamepad is
// optional). Each button taps the key a gamepad's matching button would synthesize, through
// inputManager.tapKey, so views stay keyboard-driven and need nothing touch-specific.
// Holding an arrow repeats it, like a held d-pad.
//
// Sits in the right-hand margin every view leaves free (views keep their content within the
// middle 75% of the width). Shown only where it is needed: see Main.qml.
Item {
    id: pad

    // Sized to fit the right-hand gutter at 16:9 (about 12% of the width); 70 px buttons on
    // the bike's 1080p screen, about 17 mm across.
    readonly property real cell: root.sh * 0.065
    readonly property real gap: root.sh * 0.008

    width: cell * 3 + gap * 2
    height: cell * 4 + gap * 3

    component PadButton: Rectangle {
        id: btn
        property string label
        property int key
        property bool repeats: false

        width: pad.cell
        height: pad.cell
        radius: pad.cell * 0.12
        color: area.pressed ? root.accentColor : root.surfaceColor
        opacity: area.pressed ? 0.95 : 0.55
        border.color: root.secondaryColor
        border.width: Math.max(1, root.sh * 0.002)

        Text {
            anchors.centerIn: parent
            text: btn.label
            color: area.pressed ? root.surfaceColor : root.primaryColor
            font.family: root.globalFont
            font.pixelSize: btn.label.length > 2 ? pad.cell * 0.28 : pad.cell * 0.42
        }

        MouseArea {
            id: area
            anchors.fill: parent
            onPressed: {
                inputManager.tapKey(btn.key)
                if (btn.repeats) repeatDelay.start()
            }
            onReleased: { repeatDelay.stop(); repeatTick.stop() }
            onCanceled: { repeatDelay.stop(); repeatTick.stop() }
        }
        // Same feel as InputManager's held-direction repeat.
        Timer { id: repeatDelay; interval: 400; onTriggered: repeatTick.start() }
        Timer { id: repeatTick; interval: 100; repeat: true; onTriggered: inputManager.tapKey(btn.key) }
    }

    Grid {
        columns: 3
        spacing: pad.gap

        PadButton { label: "BACK"; key: Qt.Key_Escape }
        PadButton { label: "▲"; key: Qt.Key_Up; repeats: true }
        PadButton { label: "▶❚❚"; key: Qt.Key_Space }

        PadButton { label: "◄"; key: Qt.Key_Left; repeats: true }
        PadButton { label: "OK"; key: Qt.Key_Return }
        PadButton { label: "►"; key: Qt.Key_Right; repeats: true }

        Item { width: pad.cell; height: pad.cell }
        PadButton { label: "▼"; key: Qt.Key_Down; repeats: true }
        Item { width: pad.cell; height: pad.cell }
    }
}
