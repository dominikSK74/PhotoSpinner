import QtQuick
import QtQuick.Controls

Item {
    id: root
    // width: 800; height: 600

    property real imgScale: 1.0

    Rectangle {
        anchors.fill: parent
        Image {
            anchors.fill: parent
            source: "qrc:assets/viewerBackground.png"
            fillMode: Image.Stretch
        }

        Image {
            id: img
            anchors.fill: parent
            source: appController.imagePath
            fillMode: Image.PreserveAspectFit
            smooth: true

            scale: imgScale
        }
    }

    WheelHandler {
        onWheel: (event)=> {
            if(event.angleDelta.y > 0 && imgScale < 2.0) { imgScale += 0.1 }
            if(event.angleDelta.y < 0 && imgScale > 0.5){ imgScale -= 0.1; }
        }
    }


    Rectangle {
        id: menuBox
        anchors.bottom: parent.bottom
        width: parent.width; height: 60
        z: 1
        color: "#00000000"

        Image {
            anchors.fill: parent
            source: "qrc:assets/menuBackground.png"
            fillMode: Image.Stretch
        }

        Column {
            spacing: 10
            Button {
                text: "plus"
                onClicked: {
                    imgScale += 0.1
                    console.log(imgScale)
                }
            }

            Button {
                    id: button
                    text: "A Special Button"
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 40
                        color: button.down ? "red" : "green"
                        border.color: "orange"
                        border.width: 1
                        radius: 4
                    }
                }
        }
    }
}
