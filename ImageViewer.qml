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
            source: "qrc:assets/photobackground.png"
            fillMode: Image.Stretch
        }

        Image {
            id: img
            anchors.fill: parent
            source: appController.imagePath
            fillMode: Image.PreserveAspectFit
            smooth: true
            rotation: appController.imgRotation
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
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        radius: 25

        height: 60; width: 420;
        z: 1
        // color: "#00000000"
        color: "#ff8fab"

        // Image {
        //     anchors.fill: parent
        //     source: "qrc:assets/menuBackground.png"
        //     fillMode: Image.Stretch
        // }

        Row {
            anchors.centerIn: parent
            spacing: 30

            Row {
                spacing: 10
                CustomButton {
                    iconsrc: "qrc:assets/delete.svg"
                    onClicked: appController.dropToTrash();
                }

                CustomButton {
                    iconsrc: "qrc:assets/rotateleft.svg"
                    onClicked: appController.rotateLeft();
                }
            }

            Row {
                spacing: 10
                CustomButton {
                    iconsrc: "qrc:assets/left_arrow.svg"
                    onClicked: appController.leftArrow();
                }

                CustomButton {
                    iconsrc: "qrc:assets/right_arrow.svg"
                    onClicked: appController.rightArrow();
                }
            }

            Row {
                spacing: 10
                CustomButton {
                    iconsrc: "qrc:assets/rotateright.svg"
                    onClicked: appController.rotateRight();
                }

                CustomButton {
                    iconsrc: appController.likeIcon
                    onClicked: appController.like();
                }
            }
        }
    }
}
