import QtQuick 2.0

Rectangle {
    width: 56
    height: 26
    color: "#00000000"

    Image {
        id: imagenormal
        width: 56
        height: 26
        visible : true
        source: "qrc:/images/assets/Images/buttonNormal.png"
    }

    Image {
        id: imagePressed
        x: 0
        y: 0
        width: 56
        height: 26
        visible : false
        source: "qrc:/images/assets/Images/buttonPressed.png"
    }

    MouseArea {
        id: mouseArea1
        x: 0
        y: 0
        width: 56
        height: 26
        onReleased:{
            imagenormal.visible = true
            imagePressed.visible = false
        }
        onPressed:{
            imagenormal.visible = false;
            imagePressed.visible = true
        }

    }

    Text {
        id: text1
        x: 2
        y: 2
        width: 24
        height: 19
        color: "#ff9000"
        text: buttonText
        verticalAlignment: Text.AlignTop
        style: Text.Raised
        font.pointSize: 9
        horizontalAlignment: Text.AlignLeft
    }
}
