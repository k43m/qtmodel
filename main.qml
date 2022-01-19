import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView{
        model:alertModel
        anchors.fill: parent
        spacing:2
        header:Text{text:"ALERTS"}
        delegate:
            Rectangle{
            width: 100
            height: 20
            border.color: "black"
            border.width: 2
            radius: 8
            Row{
                width: parent.width*0.9
                height: parent.height*0.9
                anchors.centerIn: parent
                Text {
                    id: name
                    height: parent.height
                    width: parent.width/4
                    text: model.alertId
                }
                Text {
                    id: date
                    height: parent.height
                    width: parent.width/4
                    text: model.detectionTime
                }
            }
        }
    }

}
