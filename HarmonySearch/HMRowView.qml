import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {
    property int viewVariableCount: 4
    //property var values: [1, 0.5, 1, 2, 3, 4 ]
    property var viewValues: [1, 0.5, 1, 2, 3, 4 ]

    RowLayout {
        id: rowLayout
        x: 10
        y: 10
        width: parent.width
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter

        Repeater {
            model: viewVariableCount + 1

            RowLayout {
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / (viewVariableCount + 2)
                ToolSeparator {
                }

                Text {
                    //text: qsTr("x" + (index + 1))
                    text: qsTr("" + viewValues[index])
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
