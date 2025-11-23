import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root
    visible: true
    visibility: Window.Maximized
    title: qsTr("Dla teściowej")
    minimumHeight: 720
    minimumWidth: 1280

    PathSelection {
        anchors.fill: parent
    }
}
