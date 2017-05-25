import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {

    property var listValues: ["1","2","3","4","5"]
    property int varCount: 4
    property int listIndex: 1
    property int highlightedIndex: 0

    property alias listModel: listModel

   Component {
        id: testDelegate

        Item {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            RowLayout {
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 0

                ToolSeparator {
                }

                Text {
                    text: lp
                    horizontalAlignment: Text.AlignHCenter
                    Layout.fillWidth: true
                    Layout.preferredWidth: 50
                    font.pixelSize: 12
                }

                Repeater {
                    model: values
                    RowLayout {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 50

                        ToolSeparator {
                        }

                        Text {
                            text: qsTr("" + value)
                            horizontalAlignment: Text.AlignHCenter
                            Layout.fillWidth: true
                            font.pixelSize: 12
                        }
                    }
                }

                ToolSeparator {
                }
            }
        }
    }

   Component {
       id: highlightBar;
       Rectangle {

           color: "greenyellow"
       }
   }

    ListModel {
        id: listModel;
        ListElement{
            lp: ""
            values: []
        }
    }

    ListView {
        id: listView
        width: parent.width
        height: parent.height * 7 / 8
        anchors.fill: parent;
        model: listModel;
        delegate: testDelegate;
        spacing: 0

        highlight: highlightBar;
        currentIndex: highlightedIndex;
        onCurrentIndexChanged: highlightedIndex = currentIndex;
    }

    function appendList() {
//        console.log("Wywołanie nr " + listIndex);

        var values = [];

        for (var i = 0; i < varCount + 1; i++) {
            values.push({"value": listValues[i]});
        }

        var params = {
            "lp": listIndex.toString(),
            "values": values
        }

        listModel.append(params);

        listIndex += 1;
    }

    function createHeader() {
        var values = [{"value": "f(x)"}];

        for (var i = 1; i < varCount + 1; i++) {
            values.push({"value": "x" + i.toString()});
        }

        var params = {
            "lp": "Lp",
            "values": values
        }
        listModel.append(params);

    }

    function highlightIndex(index) {
        listView.currentIndex = index;
    }
}
