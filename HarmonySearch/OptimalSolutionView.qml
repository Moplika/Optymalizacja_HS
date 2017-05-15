import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    property int variableCount: 10
     property var values: [0.5, 1, 2, 3, 4, 2, 3, 4, 2, 3, 4 ]
    //property var values: ["Lp","f(x)","x1","x2","x3", "x4" ]

    ColumnLayout {
        x: 0
        y: 0
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        height: 100
        anchors.horizontalCenterOffset: 0

        Text {
            anchors.horizontalCenter: parent.horizontalCenter;
            text: "Rozwiązanie optymalne: ";
            horizontalAlignment: Text.AlignHCenter;
            font.pixelSize: 16
            font.bold: true
        }

        HMRowView {
            id: headerOptimal
            width: parent.width
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter;
            viewVariableCount: variableCount
            viewValues: ["f(x)", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10"]
        }

        HMRowView {
            id: valuesOptimal
            width: parent.width
            height: 40
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: headerOptimal.bottom
            viewVariableCount: variableCount
            viewValues: values
        }
    }
}
