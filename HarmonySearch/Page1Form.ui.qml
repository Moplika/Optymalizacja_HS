import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs.qml 1.0

Item {
    property alias textField1: textField1
    property alias button1: button1
    width: 800
    height: 600
    property alias btn_constraints: btn_constraints
    property alias text_coverIterations: text_coverIterations
    property alias label_iterations: label_iterations
    property alias btn_calculate: btn_calculate
    property alias btn_restoreDefault: btn_restoreDefault
    property alias textField_iterations: textField_iterations
    property alias checkBox_iterations: checkBox_iterations
    property alias textField_NI: textField_NI
    property alias textField_PAR: textField_PAR
    property alias slider_PAR: slider_PAR
    property alias textField_HMCR: textField_HMCR
    property alias label_equationState: label_equationState
    property alias slider_HMCR: slider_HMCR
    property alias textField_HMSize: textField_HMSize
    property alias btn_check: btn_check
    property alias btn_rules: btn_rules
    property alias textField_equation: textField_equation

    GridLayout {
        id: gridLayout
        x: 10
        y: 10
        rows: 12
        columnSpacing: 10
        rowSpacing: 10
        columns: 10
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent

        Text {
            id: label_Equation
            text: qsTr("Równanie")
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.preferredWidth: 144
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillHeight: false
            Layout.fillWidth: false
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        TextField {
            id: textField_equation
            text: qsTr("Text Field")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 8
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Text {
            id: text_emptySpace
            text: qsTr("")
            Layout.preferredWidth: 144
            Layout.columnSpan: 2
            font.pixelSize: 12
        }

        Text {
            id: label_equationState
            text: qsTr("Stan równania")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.preferredWidth: 144
            Layout.columnSpan: 2
            font.pixelSize: 12
        }

        Button {
            id: btn_rules
            text: qsTr("Zasady wprowadzania")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.preferredWidth: 144
            Layout.fillWidth: false
        }

        Button {
            id: btn_constraints
            text: qsTr("Ograniczenia na x")
            checkable: false
            highlighted: false
            font.strikeout: false
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.fillWidth: false
            Layout.rowSpan: 1
            Layout.preferredWidth: 144
        }

        Button {
            id: btn_check
            text: qsTr("Sprawdź poprawność")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.preferredWidth: 144
        }

        Text {
            id: text_HMSizeDescr
            text: qsTr("Rozmiar pamięci harmonii")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
            Layout.columnSpan: 10
            font.pixelSize: 12
        }

        Text {
            id: label_HMSize
            text: qsTr("Harmony Memory Size")
            wrapMode: Text.WordWrap
            Layout.preferredWidth: 144
            horizontalAlignment: Text.AlignHCenter
            Layout.fillHeight: false
            verticalAlignment: Text.AlignVCenter
            Layout.rowSpan: 1
            font.pixelSize: 12
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillWidth: false
            Layout.columnSpan: 2
        }

        TextField {
            id: textField_HMSize
            text: qsTr("10")
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillWidth: true
            Layout.columnSpan: 8
        }

        Text {
            id: text_HMCRDescr
            text: qsTr("Szansa wyboru elementu z pamięci harmonii")
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            Layout.columnSpan: 10
            Layout.fillWidth: true
            font.bold: true
        }

        Text {
            id: label_HMCR
            text: qsTr("Harmony Memory Consideration Rate")
            Layout.preferredWidth: 144
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            Layout.fillHeight: false
            verticalAlignment: Text.AlignVCenter
            Layout.rowSpan: 1
            font.pixelSize: 12
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.fillWidth: false
        }

        Slider {
            id: slider_HMCR
            Layout.fillWidth: true
            Layout.columnSpan: 6
            value: 0.5
        }

        TextField {
            id: textField_HMCR
            text: qsTr("0.00")
            Layout.preferredWidth: 144
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.fillWidth: false
        }

        Text {
            id: text_PARDescr
            text: qsTr("TODO: Tutaj wpisać jakiś opis PAR")
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            Layout.columnSpan: 10
            font.bold: true
        }

        Text {
            id: label_PAR
            text: qsTr("Pitch Adjustment Rate")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: false
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillHeight: false
            Layout.rowSpan: 1
            wrapMode: Text.WordWrap
            Layout.preferredWidth: 144
        }

        Slider {
            id: slider_PAR
            Layout.fillWidth: true
            Layout.columnSpan: 6
            value: 0.5
        }

        TextField {
            id: textField_PAR
            text: qsTr("0.00")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: false
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.preferredWidth: 144
        }

        Text {
            id: text_NIDescr
            text: qsTr("Liczba iteracji")
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            Layout.columnSpan: 10
            font.pixelSize: 12
            font.bold: true
        }

        Text {
            id: label_NI
            text: qsTr("Number of Improvisations")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: false
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillHeight: false
            Layout.rowSpan: 1
            wrapMode: Text.WordWrap
            Layout.preferredWidth: 144
        }

        TextField {
            id: textField_NI
            text: qsTr("1000")
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.columnSpan: 8
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
        }

        CheckBox {
            id: checkBox_iterations
            text: qsTr("Pokazywać kolejne iteracje?")
            Layout.fillWidth: true
            Layout.preferredWidth: 216
            Layout.columnSpan: 3
        }

        Text {
            id: text_coverIterations
            text: qsTr("")
            visible: false
            Layout.columnSpan: 7
            font.pixelSize: 12
        }

        Text {
            id: label_iterations
            text: qsTr("Pokazuj co ... iterację")
            Layout.fillHeight: false
            wrapMode: Text.WordWrap
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillWidth: false
            horizontalAlignment: Text.AlignHCenter
            Layout.columnSpan: 5
            Layout.preferredWidth: 144
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
            Layout.rowSpan: 1
        }

        TextField {
            id: textField_iterations
            text: qsTr("1")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillWidth: false
            horizontalAlignment: Text.AlignHCenter
            Layout.columnSpan: 2
            Layout.preferredWidth: 144
        }

        Button {
            id: btn_restoreDefault
            text: "Przywróć domyślne"
            autoExclusive: false
            checked: false
            checkable: false
            highlighted: false
            autoRepeat: false
            Layout.preferredWidth: 144
            Layout.columnSpan: 2
        }

        Text {
            id: text_empty
            text: qsTr("")
            Layout.fillWidth: true
            Layout.columnSpan: 4
            Layout.preferredWidth: 216
            font.pixelSize: 12
        }

        Button {
            id: btn_calculate
            text: qsTr("Licz!")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.preferredWidth: 288
            Layout.columnSpan: 4
        }

    }

    RowLayout {
        visible: false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: textField1
            visible: false
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            text: qsTr("Press Me")
            visible: false
        }
    }
}
