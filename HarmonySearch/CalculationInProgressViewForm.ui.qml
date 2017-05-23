import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    id: mainItem
    width: 800
    height: 600
    property alias mainItem: mainItem
    visible: true

    ColumnLayout {
        id: columnLayout
        width: 800
        height: 250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        BusyIndicator {
            id: busyIndicator
            Layout.preferredHeight: 200
            Layout.preferredWidth: 200
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: text1
            text: qsTr("Trwa liczenie, proszę czekać")
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillHeight: false
            fontSizeMode: Text.Fit
            clip: false
            transformOrigin: Item.Center
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            font.pixelSize: 26
        }
    }
}
