import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Page2Form {
    property int myVariableCount: 0
    property var myValues: ["0.5", "1", "2", "3", "4", "2", "3", "4", "2", "3", "4" ]
    //property var values: ["Lp","f(x)","x1","x2","x3", "x4" ]

    id: page2;

    SolutionNoIterations {
        anchors.fill: parent;
    }

//    OptimalSolutionView {
//        id: optimalSolutionView
//        width: parent.width;
//        anchors.horizontalCenter: parent.horizontalCenter;
//        visible: false;

//        variableCount: myVariableCount;
//        values: myValues;
//    }

//    HarmonyMemoryDialog {
//        id: harmonyMemoryDialog

//    }

//    btn_showHM.onClicked: {
//        harmonyMemoryDialog.open();
//        //harmonyMemoryDialog.harmonyMemoryView.drawHarmonyMemory();
//    }

//    Connections {
//        target: uiHandler;
//        onShowResult: {
//            console.log("Signal: onShowResult");
//            console.log("N:", N);//, "values:", result);
//            optimalSolutionView.variableCount = N;
//            optimalSolutionView.values = result;
//            optimalSolutionView.visible = true;

//        }
//    }

}
