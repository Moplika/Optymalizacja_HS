import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    width: 800
    height: 600
    property alias text_X2Max: text_X2Max
    property alias text_X2Min: text_X2Min
    property alias text_X1Max: text_X1Max
    property alias text_X1Min: text_X1min
    property alias btn_drawGraph: btn_drawGraph
    property alias btn_orto: btn_orto
    property alias btn_3D: btn_3D
    property alias btn_showHM: btn_showHM
    property alias value_fx: value_fx
    property alias solutionView: solutionView
    property alias graphView: graphView

    RowLayout {
        id: rowLayout
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout_left
            width: 100
            height: 100
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 300

            Item {
                id: item_empty1
                width: 200
                height: 200
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 50
            }

            Text {
                id: label_optimalSolution
                text: qsTr("Rozwiązanie optymalne: ")
                font.strikeout: false
                font.underline: true
                font.bold: true
                Layout.fillWidth: true
                transformOrigin: Item.Center
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 20
            }

            RowLayout {
                id: rowLayout_fx
                width: 100
                height: 100
                spacing: 0
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredWidth: 200
                Layout.fillHeight: false
                Layout.fillWidth: true
                Layout.preferredHeight: 50

                Text {
                    id: label_fx
                    text: qsTr("f(x) = ")
                    Layout.fillWidth: true
                    font.underline: false
                    font.bold: false
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    Layout.preferredWidth: 90
                    font.pixelSize: 20
                }

                Text {
                    id: value_fx
                    text: qsTr("-0.000000")
                    Layout.preferredWidth: 100
                    Layout.fillWidth: true
                    font.pixelSize: 20
                }
            }

            SolutionView {
                id: solutionView
                Layout.preferredHeight: 300
                Layout.preferredWidth: 300
                Layout.fillWidth: true
            }

            Item {
                id: item_empty
                width: 200
                height: 200
                Layout.preferredHeight: 70
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: btn_showHM
                text: qsTr("Wyświetl końcową postać pamięci harmonii")
                Layout.preferredHeight: -1
                Layout.fillHeight: false
                transformOrigin: Item.Center
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }

        ColumnLayout {
            id: columnLayout
            width: 100
            height: 100

            GraphView {
                id: graphView
                Layout.fillHeight: true
                visible: true
                Layout.fillWidth: true
                Layout.preferredHeight: 450
                Layout.preferredWidth: 500
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }

            Rectangle {
                id: empty_space
                width: 200
                height: 200
                color: "#ffffff"
                Layout.preferredHeight: 50
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                id: rowLayout1
                width: 100
                height: 100

                ColumnLayout {
                    id: columnLayout1
                    width: 100
                    height: 100
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Rectangle {
                        id: rectangle
                        width: 200
                        height: 200
                        color: "#ffffff"
                        Layout.preferredHeight: 40
                        Layout.fillWidth: true
                        Layout.fillHeight: false
                    }
                    Button {
                        id: btn_orto
                        text: qsTr("Widok warstwic")
                        Layout.preferredWidth: 150
                        Layout.columnSpan: 3
                        Layout.rowSpan: 3
                        Layout.fillHeight: false
                        Layout.fillWidth: true
                    }
                    Button {
                        id: btn_3D
                        text: qsTr("Widok 3D")
                        Layout.preferredWidth: 150
                        Layout.columnSpan: 3
                        Layout.rowSpan: 3
                        Layout.fillWidth: true
                    }
                }

                GridLayout {
                    id: gridLayout1
                    width: 100
                    height: 100
                    Layout.fillHeight: true
                    Layout.preferredWidth: 350
                    rows: 3
                    columns: 3

                    TextField {
                        id: text_X1min
                        text: qsTr("0.00")
                        font.pointSize: 10
                        horizontalAlignment: Text.AlignHCenter
                        Layout.fillWidth: true
                        Layout.preferredWidth: 150
                        Layout.rowSpan: 1
                    }

                    Text {
                        id: label_X1range
                        text: qsTr("≤ X1 ≤")
                        verticalAlignment: Text.AlignVCenter
                        Layout.fillHeight: false
                        fontSizeMode: Text.HorizontalFit
                        horizontalAlignment: Text.AlignHCenter
                        Layout.fillWidth: true
                        Layout.preferredWidth: 50
                        Layout.rowSpan: 1
                        font.pixelSize: 16
                    }

                    TextField {
                        id: text_X1Max
                        text: qsTr("0.00")
                        font.pointSize: 10
                        horizontalAlignment: Text.AlignHCenter
                        Layout.fillWidth: true
                        Layout.preferredWidth: 150
                        Layout.rowSpan: 1
                    }

                    TextField {
                        id: text_X2Min
                        text: qsTr("0.00")
                        font.pointSize: 10
                        horizontalAlignment: Text.AlignHCenter
                        Layout.preferredWidth: 125
                        Layout.fillWidth: true
                        Layout.rowSpan: 1
                    }

                    Text {
                        id: label_X2Range
                        text: qsTr("≤ X2 ≤")
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        Layout.preferredWidth: 100
                        Layout.fillWidth: true
                        Layout.rowSpan: 1
                        font.pixelSize: 16
                    }
                    TextField {
                        id: text_X2Max
                        text: qsTr("0.00")
                        font.pointSize: 10
                        horizontalAlignment: Text.AlignHCenter
                        Layout.preferredWidth: 125
                        Layout.fillWidth: true
                        Layout.rowSpan: 1
                    }
                    Button {
                        id: btn_drawGraph
                        text: qsTr("Rysuj nowy wykres")
                        Layout.fillWidth: true
                        Layout.rowSpan: 1
                        Layout.columnSpan: 3
                    }
                }
            }
        }
    }
}
