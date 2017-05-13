import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

RowLayout {
    //anchors.fill: parent
    spacing: 0

    property int index: 1

    TextField {
        id: text_min;
        horizontalAlignment: Text.AlignHCenter;
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter;
        Layout.fillWidth: true;
    }
    Text {
        text: "≤ x" + index + " ≤";
        font.pixelSize: 20;
        //Layout.preferredWidth: parent.width / 3;
        horizontalAlignment: Text.AlignHCenter;
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter;
        Layout.fillWidth: true;
    }
    TextField {
        id: text_max;
        horizontalAlignment: Text.AlignHCenter;
        Layout.fillWidth: true;
    }

    function sendConstraints() {
       if (text_min.text !== "" && text_max.text !== "" ) {
        uiHandler.readSingleConstraint(index, text_min.text, text_max.text);
        console.log("Constraints for id " + index + " sent!");
       }
    }

}
