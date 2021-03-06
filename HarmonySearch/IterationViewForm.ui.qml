import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Item {
    width: 800
    height: 600
    property alias btn_showResult: btn_showResult
    property alias btn_end: btn_end
    property alias harmonyMemoryView: harmonyMemoryView
    property alias btn_nextIter: btn_nextIter
    property alias text_newYValue: text_newYValue
    property alias solutionView_new: solutionView_new
    property alias solutionView_optimal: solutionView_optimal
    property alias text_optimalYValue: text_optimalYValue
    property alias text_iterationNb: text_iterationNb

    GridLayout {
        id: gridLayout1
        columnSpacing: 8
        rowSpacing: 8
        rows: 12
        columns: 6
        anchors.fill: parent


        Text {
            id: text_iterationNb
            text: qsTr("Iteracja 00000")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.columnSpan: 6
            Layout.preferredWidth: 133
            font.bold: true
            fontSizeMode: Text.VerticalFit
            Layout.fillWidth: true
            font.pixelSize: 28
        }
        Text {
            id: label_hm
            text: qsTr("Widok pamięci harmonii")
            fontSizeMode: Text.VerticalFit
            Layout.preferredWidth: 534
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.columnSpan: 4
            Layout.rowSpan: 1
            font.pixelSize: 14
        }

        Text {
            id: label_solution
            text: qsTr("Aktualne rozwiązania:")
            fontSizeMode: Text.VerticalFit
            font.bold: true
            Layout.fillHeight: true
            Layout.preferredWidth: 266
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            font.pixelSize: 13
        }










        GridLayout {
            id: gridLayout
            width: 100
            height: 100
            Layout.preferredHeight: 350
            rowSpacing: 8
            columnSpacing: 8
            rows: 10
            columns: 4
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 4
            Layout.rowSpan: 10


            HarmonyMemoryView {
                id: harmonyMemoryView
                Layout.preferredHeight: 534
                Layout.preferredWidth: 534
                Layout.rowSpan: 5
                Layout.columnSpan: 4
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: false
                Layout.fillWidth: true
            }

        }
        ColumnLayout {
            id: rightColumn
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.rowSpan: 10
            Layout.columnSpan: 2


            Text {
                id: label_optimal
                text: qsTr("Rozwiązanie optymalne:")
                Layout.preferredHeight: 50
                fontSizeMode: Text.Fit
                Layout.fillHeight: true
                Layout.rowSpan: 2
                Layout.columnSpan: 2
                Layout.fillWidth: true
                verticalAlignment: Text.AlignBottom
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 13
            }

            RowLayout {
                id: rowLayout1
                width: 100
                height: 100
                Layout.columnSpan: 2

                Text {
                    id: label_optimalY
                    text: qsTr("y(x) =")
                    Layout.fillWidth: true
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    fontSizeMode: Text.Fit
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignRight
                    Layout.preferredWidth: 133
                }

                Text {
                    id: text_optimalYValue
                    text: qsTr("00000")
                    Layout.fillWidth: true
                    font.bold: true
                    fontSizeMode: Text.Fit
                    font.pixelSize: 12
                    Layout.preferredWidth: 133
                }


            }

            SolutionView {
                id: solutionView_optimal
                Layout.rowSpan: 3
                Layout.columnSpan: 2
                Layout.preferredHeight: 170
                Layout.preferredWidth: 266
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: label_new
                text: qsTr("Nowe rozwiązanie:")
                Layout.columnSpan: 2
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                font.pixelSize: 14
                Layout.fillHeight: true
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                Layout.rowSpan: 1
            }

            RowLayout {
                id: rowLayout2
                width: 100
                height: 100


                Text {
                    id: label_newY
                    text: qsTr("y(x) = ")
                    Layout.fillWidth: true
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    fontSizeMode: Text.Fit
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignRight
                    Layout.preferredWidth: 133
                }

                Text {
                    id: text_newYValue
                    text: qsTr("00000")
                    Layout.fillWidth: true
                    font.bold: true
                    fontSizeMode: Text.Fit
                    font.pixelSize: 12
                    Layout.preferredWidth: 133
                }
            }

            SolutionView {
                id: solutionView_new
                Layout.rowSpan: 3
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 266
                Layout.preferredHeight: 170
            }






        }
        Button {
            id: btn_end
            text: qsTr("Wylicz końcowy wynik")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.columnSpan: 4
            Layout.fillHeight: false
            Layout.fillWidth: true
        }
        Button {
            id: btn_nextIter
            text: qsTr("Pokaż kolejną iterację")
            visible: true
            Layout.columnSpan: 2
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: true
        }

        Button {
            id: btn_showResult
            text: qsTr("Przejdź do widoku rozwiązania")
            visible: false
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.columnSpan: 2
            Layout.fillWidth: true
        }
    }
}
