import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Users")

    TableView {
        id: tableView
        model: table_model
        property var columnWidths: [60, 350, 150]
        columnWidthProvider: function (column) { return columnWidths[column] }
        rowHeightProvider: function (column) { return 30; }
        anchors.fill: parent
        topMargin: columnHead.implicitHeight

        ScrollBar.vertical: ScrollBar{}
        clip: true

        Row { //Headers
            id: columnHead
            y: tableView.contentY
            z: 1
            Repeater {
                model: ["ID", "Name", "Phone number"]
                Label {
                    width: tableView.columnWidthProvider(index)
                    height: 30
                    text: modelData
                    font.pixelSize: 15
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    background: Rectangle {
                        border.width: 1
                        color: "#eeeeee"
                    }
                }
            }
        }

        delegate: Rectangle {
            border.width: 1
            Text {
                text: display
                anchors.fill: parent
                anchors.margins: 10
                color: 'black'
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
