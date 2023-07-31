import QtQuick
import QtQuick.Window
import ToDo 1.0

Window {
    width: 340
    height: 480
    visible: true
    title: qsTr("Hello World")
    Item{
        id:mainListView
        width: parent.width
        height: 300
//        anchors{top: editArea.bottom}
        anchors{top: parent.top; bottom: parent.bottom}
//        ListModel{
//            id:modelList
//        }
        MouseArea{
            anchors.fill: parent
            onClicked: console.log(ToDoModel)
        }

        ListView{
            width: parent.width
            height: parent.height
            spacing: 5
            model: ToDoModel {
            list: ToDoList
            }
            delegate: Rectangle{
                width: mainListView.width
                height: 30
                color:'grey'
                Text{
                    text: toDo
                    color: "black"
                }
                Rectangle{
                    width: 20
                    height: 20
                    color:"red"
                    anchors{right: parent.right; verticalCenter: parent.verticalCenter}
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {modelList.remove(index)}
                    }
                }
            }

        }
    }
//    Rectangle{
//        id: editArea
//        width:parent.width
//        height:30
//        color:"blue"
//        TextEdit{
//            id:textEdit
//            anchors {verticalCenter: parent.verticalCenter;}
//            padding: 10
//            width: parent.width
//            height: 30

//        }
//        Rectangle{
//            width: 20
//            height: 20
//            color:"red"
//            anchors{right: parent.right; verticalCenter: parent.verticalCenter}
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {modelList.append({"toDo":textEdit.text}); console.log(modelList.count)}
//            }
//        }
//    }
}
