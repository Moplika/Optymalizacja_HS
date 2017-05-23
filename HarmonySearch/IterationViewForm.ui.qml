import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    width: 800
    height: 600
    property alias harmonyMemoryView: harmonyMemoryView
    property alias btn_nextIter: btn_nextIter
    property alias text_newYValue: text_newYValue
    property alias solutionView_new: solutionView_new
    property alias solutionView_optimal: solutionView_optimal
    property alias text_optimalYValue: text_optimalYValue
    property alias text_iterationNb: text_iterationNb

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout
            width: 100
            height: 100
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 534

            HarmonyMemoryView {
                id: harmonyMemoryView
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        GridLayout {
            id: gridLayout
            width: 100
            height: 100
            rowSpacing: 10
            columnSpacing: 0
            columns: 2
            Layout.preferredWidth: 266
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: space_up
                text: qsTr("")
                Layout.preferredHeight: 15
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.rowSpan: 1
                font.pixelSize: 12
            }

            Text {
                id: text_iterationNb
                text: qsTr("Iteracja 00000")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Layout.columnSpan: 2
                Layout.preferredWidth: 133
                font.bold: true
                fontSizeMode: Text.Fit
                Layout.fillWidth: true
                font.pixelSize: 20
            }

            Text {
                id: label_optimalSolution
                text: qsTr("Aktualne rozwiązanie optymalne:")
                wrapMode: Text.WordWrap
                Layout.columnSpan: 2
                font.bold: true
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                font.pixelSize: 14
            }

            Text {
                id: label_optimalY
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
                id: text_optimalYValue
                text: qsTr("00000")
                Layout.fillWidth: true
                font.bold: true
                fontSizeMode: Text.Fit
                font.pixelSize: 12
                Layout.preferredWidth: 133
            }

            SolutionView {
                id: solutionView_optimal
                Layout.columnSpan: 2
                Layout.preferredHeight: 200
                Layout.preferredWidth: 266
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: label_newSolution
                text: qsTr("Aktualnie wygenerowane rozwiązanie:")
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
                Layout.columnSpan: 2
                font.bold: true
                fontSizeMode: Text.Fit
                font.pixelSize: 14
                horizontalAlignment: Text.AlignHCenter
            }

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

            SolutionView {
                id: solutionView_new
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 266
                Layout.preferredHeight: 200
            }

            Button {
                id: btn_nextIter
                text: qsTr("Pokaż kolejną iterację")
                Layout.columnSpan: 2
                Layout.fillHeight: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Layout.fillWidth: true
            }
        }
    }
}
