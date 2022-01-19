import QtQuick 2.14
import QtQuick.Controls 2.5
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
            width: parent.width
            height: 40
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
                    width: parent.width/8
                    text: model.alertId
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: date
                    height: parent.height
                    width: parent.width/4
                    text: "TODO DATE"
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: sector
                    height: parent.height
                    width: parent.width/3
                    verticalAlignment: Text.AlignVCenter
                    text: model.sectorName
                }
                Button{
                    text:"TODO Remove"
                    height: parent.height
                    width: parent.width/4
                    onClicked: {
                        //TODO
                    }
                }
            }

        }
    }


}
