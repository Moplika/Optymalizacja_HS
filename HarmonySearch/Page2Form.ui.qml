import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 800
    height: 600
    property alias iterationViewPage: iterationViewPage
    property alias solutionNoIterations: solutionNoIterations

    state: ""

    SolutionNoIterations {
        id: solutionNoIterations
        anchors.fill: parent
    }

    IterationViewPage {
        id: iterationViewPage
        anchors.fill: parent
        visible: false
    }
    states: [
        State {
            name: "iterationState"

            PropertyChanges {
                target: solutionNoIterations
                visible: false
            }

            PropertyChanges {
                target: iterationViewPage
                visible: true
            }
        }
    ]
}
