import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {

    property string myFont: "Abadi"
    property string myFontColor: "white"

    Rectangle {
        anchors.fill: parent
        color: myFontColor

        Image {
            anchors.fill: parent
            source: "qrc:assets/background.png"
            fillMode: Image.PreserveAspectCrop
        }


        ColumnLayout {
            spacing: 20
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 20
            anchors.topMargin: 30

            Text {
                text: "Wybierz odpowiednie foldery"
                font.pixelSize: 40
                color: myFontColor
                font.family: myFont
                font.bold: true
            }
            RowLayout {
                spacing: 20;


                Button {
                    id: sourceBtn
                    icon.source: "qrc:assets/folder.svg"
                    icon.color: "#e5a4a3"
                    icon.height: 60; icon.width: 60;
                    onClicked: appController.selectSourceFolder();

                    background: Rectangle {
                        radius: 15
                    }

                    Connections {
                        target: appController
                        onChangeSourceIcon: sourceBtn.icon.source = iconPath
                    }
                }

                Text {
                    text: "Wybór folderu ze zdjęciami"
                    font.family: myFont
                    color: myFontColor
                    font.pixelSize: 32
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            Text {
                id: fromPathText
                text: appController.sourceFolder
                font.family: myFont
                color: myFontColor
                font.pixelSize: 32
            }

            RowLayout {
                spacing: 20;


                Button {
                    id: targetBtn
                    icon.source: "qrc:assets/folder.svg"
                    icon.color: "#e5a4a3"
                    icon.height: 60; icon.width: 60;
                    onClicked: appController.selectTargetFolder();

                    background: Rectangle {
                        radius: 15
                    }

                    Connections {
                        target: appController
                        onChangeTargetIcon: targetBtn.icon.source = iconPath
                    }
                }

                Text {
                    text: "Wybór folderu do wywołania"
                    font.family: myFont
                    color: myFontColor
                    font.pixelSize: 32
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            Text {
                id: toPathText
                text: appController.targetFolder
                font.family: myFont
                color: myFontColor
                font.pixelSize: 32
            }

            Button {
                implicitWidth: 400; implicitHeight: 60;
                text: "Przeglądaj"
                font.bold: true
                font.pixelSize: 30
                palette.buttonText: "#e5a4a3"
                background: Rectangle {
                    radius: 15
                }
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 25
                onClicked: appController.browsePictures();
            }
        }
    }
}
