import QtQuick 2.4

Item {
    width: 800
    height: 600
    property alias calculationInProgressView: calculationInProgressView
    property alias iterationView: iterationView

    IterationView {
        id: iterationView
        anchors.fill: parent
        visible: true
    }

    CalculationInProgressView {
        id: calculationInProgressView
        anchors.fill: parent
        visible: false
    }
    states: [
        State {
            name: "CalculationState"

            PropertyChanges {
                target: calculationInProgressView
                visible: true
            }

            PropertyChanges {
                target: iterationView
                visible: false
            }
        }
    ]
}
