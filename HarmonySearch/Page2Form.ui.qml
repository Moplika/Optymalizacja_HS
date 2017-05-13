import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    width: 720
    height: 400

    RowLayout {
        id: rowLayout
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        TextField {
            id: textField
            text: qsTr("Text Field")
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillWidth: true
        }

        Text {
            id: text1
            text: qsTr("Text")
            Layout.preferredWidth: 144
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
            font.pixelSize: 12
        }

        TextField {
            id: textField1
            text: qsTr("Text Field")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
    }
}
