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

            uiHandler.drawSurfaceGraph(-10,10,-10,10);
        }
    }

    HarmonyMemoryDialog {
        id: hmDialog;
    }

    btn_showHM.onClicked: {
        hmDialog.open();
    }

//    btn_graph3D.onClicked: {

//    }

//    btn_graphOrtho.onClicked: {
//        graphView.surfaceGraph.orthoProjection = true;
//        graphView.surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetDirectlyAbove
//        graphView.surfaceGraph.flipHorizontalGrid = true
//    }

}
