import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 180
    height: 80

    GridView {
        id: gridView1
        x: 0
        y: 0
        width: 180
        height: 80
        layoutDirection: Qt.LeftToRight
        cellHeight: 40
        cellWidth: 60
        delegate: Item {
            x: 6
            height: 50
            Column {
                Button {

                }
            }
        }
        model: ListModel {
            ListElement {
                buttonText: "存档"
            }

            ListElement {
                buttonText: "读档"
            }

            ListElement {
                buttonText: "设置"
            }

            ListElement {
                buttonText: "帮助"
            }

            ListElement {
                buttonText: "关于"
            }

            ListElement {
                buttonText: "退出"
            }
        }


    }
}
