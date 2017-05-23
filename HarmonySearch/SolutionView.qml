import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    property int varCount: 4
    property var values: ["-0.192", "1", "2", "3", "4"]

    id: solutionView
    width: parent.width;
    height: parent.height;
    anchors.horizontalCenter: parent.horizontalCenter;

    Component {
        id: solutionDelegate;

        Item {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            height: 25
            RowLayout {
                anchors.horizontalCenter: parent.horizontalCenter;
                height: 25
                spacing: 0

                Text {
                    text: label
                    Layout.preferredWidth: 100
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    Layout.fillWidth: true
                    font.pixelSize: 14
                }

                Text {
                    text: value
                    Layout.preferredWidth: 100
                    verticalAlignment: Text.AlignVCenter
                    Layout.fillWidth: true
                    font.pixelSize: 14
                }
            }
        }
    }

    ListModel {
        id: solutionListModel;
    }

    ListView {
        id: solutionListView;
        width: parent.width;
        height: parent.height;
        anchors.fill: parent;
        model: solutionListModel;
        delegate: solutionDelegate;
        spacing: 0;
    }

    function fillList() {
        solutionListModel.clear();

        for (var i = 0; i < varCount; i++)
        {
            var params = {
                label: qsTr("x" + (i+1) + " = "),
                value: qsTr("" + values[i])
            };

            solutionListModel.append(params);
        }
    }
}
