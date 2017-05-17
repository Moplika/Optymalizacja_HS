import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Page3Form {

    property int varCount: 10
    property var values: [1,1,1,1,1,1,1,1,1,1,1,1]

    width: 800
    height: 600

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter

        RowLayout {
            width: columnLayout;
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: qsTr("f(x) = ");
                horizontalAlignment: Text.AlignRight;
                Layout.fillWidth: true;
                Layout.preferredWidth: columnLayout / 2;
            }
            Text {
                text: qsTr("" + values[0])
                Layout.fillWidth: true;
                horizontalAlignment: Text.AlignLeft;
                Layout.preferredWidth: columnLayout / 2;
            }
        }

        Repeater {
            model: varCount;
            anchors.horizontalCenter: parent.horizontalCenter;

            RowLayout {
                width: columnLayout.width;

                Text {
                    text: qsTr("x" + (index + 1) + " = ");
                    horizontalAlignment: Text.AlignRight;
                    Layout.fillWidth: true;
                    Layout.preferredWidth: columnLayout / 2;
                }
                Text {
                    text: qsTr("" + values[index+1])
                    Layout.fillWidth: true;
                    horizontalAlignment: Text.AlignLeft;
                    Layout.preferredWidth: columnLayout / 2;
                }
            }
        }
    }
}
