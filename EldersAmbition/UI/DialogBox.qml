import QtQuick 2.0

Rectangle {
    width: 800
    height: 80
    radius: 15
    opacity: 0.6
    border.width: 4

    Text {
        id: text1
        x: 21
        y: 12
        text: dialogText
        font.pixelSize: 16
    }
}
