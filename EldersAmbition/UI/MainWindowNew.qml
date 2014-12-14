import QtQuick 2.0

Rectangle {
    width: 800
    height: 600

    Image {
        id: background
        x: 0
        y: 0
        width: 800
        height: 600
        fillMode: Image.Stretch
        source: "qrc:/images/assets/Images/background.jpg"

        Text {
            id: textPlace
            x: 99
            y: 40
            width: 80
            height: 20
            color: "#ff9000"
            text: qsTr("Text Edit")
            font.pixelSize: 12
        }

        Text {
            id: textScene
            x: 14
            y: 11
            width: 80
            height: 20
            color: "#000000"
            text: qsTr("Text Edit")
            font.pixelSize: 12
        }

        Text {
            id: text1
            x: 14
            y: 71
            color: "#ff9000"
            text: qsTr("当前属性")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 14
            y: 171
            color: "#ff9000"
            text: qsTr("当前物品")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 14
            y: 314
            color: "#ff9000"
            text: "对手信息"
            font.pixelSize: 12
        }
    }

    MapCanvas {
        id: mapCanvas1
        x: 224
        y: 26
        color: "#00000000"
        radius: 0
        border.width: 0
    }

    ButtonArea {
        id: buttonArea1
        x: 10
        y: 414
        color: "#00000000"
    }

    DialogBox {
        id: dialogBox1
        x: 0
        y: 520
        visible: false
    }
}
