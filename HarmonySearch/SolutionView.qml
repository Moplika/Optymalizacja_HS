import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    property int varCount: 4
    property var values: ["-0.192", "1", "2", "3", "4"]

    width: parent.width;
    height: parent.height;
    anchors.horizontalCenter: parent.horizontalCenter;

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter;

        RowLayout {
            height: 40
            spacing: 0

            Text {
                text: qsTr("f(x) = ")
                Layout.preferredWidth: 110
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
                font.pixelSize: 12
            }

            Text {
                text: qsTr("" + values[0])
                Layout.preferredWidth: 90
                verticalAlignment: Text.AlignVCenter
                Layout.fillWidth: true
                font.pixelSize: 12
            }
        }

        Repeater {
            model: varCount

            RowLayout {
                height: 40
                spacing: 0

                Text {
                    text: qsTr("x" + (index + 1) + " = ")
                    Layout.preferredWidth: 110
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    Layout.fillWidth: true
                    font.pixelSize: 12
                }

                Text {
                    text: qsTr("" + values[index+1])
                    Layout.preferredWidth: 90
                    verticalAlignment: Text.AlignVCenter
                    Layout.fillWidth: true
                    font.pixelSize: 12
                }
            }
        }
    }
}
