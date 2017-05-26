import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    width: 800
    height: 600
    property alias parametersView: parametersView
    property alias calculationInProgressView: calculationInProgressView

    ParametersView {
        id: parametersView
        anchors.fill: parent
    }

    CalculationInProgressView {
        id: calculationInProgressView
        anchors.fill: parent
        visible: false
    }

    state: "";

    states: [
        State {
            name: "CountingState"

            PropertyChanges {
                target: calculationInProgressView
                visible: true
            }

            PropertyChanges {
                target: parametersView
                visible: false
            }
        }
    ]
}
