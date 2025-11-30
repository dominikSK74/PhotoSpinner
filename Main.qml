import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow {
    id: root
    visible: true
    visibility: Window.Maximized
    title: qsTr("PhotoSpinner")
    minimumHeight: 520
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
