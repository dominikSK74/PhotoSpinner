import QtQuick

Rectangle {
    id: root
    width: 45
    height: 45
    radius: 6
    color: controlColor

    property string iconsrc: ""
    property color normalColor: "#448aff"
    property color hoverColor: "#5e9cff"
    property color pressedColor: "#2a6cd6"
    property color textColor: "#ffffff"

    readonly property color controlColor: mouseArea.pressed ? pressedColor : mouseArea.containsMouse ? hoverColor: normalColor

    signal clicked();

    Image {
        anchors.centerIn: parent
        source: iconsrc
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true


        onClicked: {
            root.clicked()
        }
    }
}
