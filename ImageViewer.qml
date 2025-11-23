import QtQuick
import QtQuick.Controls

Item {
    Image {
        id: currentImage
        anchors.fill: parent
        source: appController.imagePath
    }

}
