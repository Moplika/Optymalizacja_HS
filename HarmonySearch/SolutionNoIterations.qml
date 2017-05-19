import QtQuick 2.4

SolutionNoIterationsForm {
    property int viewVariableCount: 0
    property var viewValues: ["0.5", "1", "2", "3", "4", "2", "3", "4", "2", "3", "4" ]



    Connections {
        target: uiHandler;
        onShowResult: {
            console.log("Signal: onShowResult");
            value_fx.text = fx;
            solutionView.varCount = N;
            solutionView.values = x;
            solutionView.fillList();

            uiHandler.drawSurfaceGraph(-1,1,-1,1);
        }
    }

    HarmonyMemoryDialog {
        id: hmDialog;
    }

    btn_showHM.onClicked: {
        hmDialog.open();
    }

}
