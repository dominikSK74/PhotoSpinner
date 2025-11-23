import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root
    visible: true
    visibility: Window.Maximized
    title: qsTr("Dla teściowej")
    minimumHeight: 400
    minimumWidth: 680

    Loader {
        id: screenLoader
        anchors.fill: parent
        source: appController.screen
    }

    Binding {
        target: appController
        property: "screen"
        value: screenLoader.source
    }
}
