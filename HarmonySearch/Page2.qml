import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Page2Form {
    property int myVariableCount: 0
    property var myValues: ["0.5", "1", "2", "3", "4", "2", "3", "4", "2", "3", "4" ]
    //property var values: ["Lp","f(x)","x1","x2","x3", "x4" ]

    property bool switchFromIterationView: true

    id: page2;

    Connections {
        target: uiHandler;
        onStartShowingIterations: {
            state = "iterationState"
            switchFromIterationView = false;
        }
        onCalculationsStarted: {
            switchFromIterationView = true;
        }

        onShowResult: {
            if (switchFromIterationView) {
                state = ""
            }
        }
    }
}
