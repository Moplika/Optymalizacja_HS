import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

Item {
    id: item1
    width: 720
    height: 400
    property alias btn_showHM: btn_showHM
    property alias text_result: text_result

    Text {
        id: text_result
        text: qsTr("Maybe one day the result will be here")
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 344
        anchors.bottomMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 12
    }

    Button {
        id: btn_showHM
        x: 8
        y: 304
        text: qsTr("Pokaż końcową pamięć harmonii")
    }
}
