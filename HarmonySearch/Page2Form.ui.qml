import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    width: 720
    height: 400
    property alias text_result: text_result

    Text {
        id: text_result
        text: qsTr("Maybe one day the result will be here")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 12
    }
}
