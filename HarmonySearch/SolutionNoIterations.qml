import QtQuick 2.4

SolutionNoIterationsForm {
    property int viewVariableCount: 0
    property var viewValues: ["0.5", "1", "2", "3", "4", "2", "3", "4", "2", "3", "4" ]

    property double x1Min: -1
    property double x1Max: 1
    property double x2Min: -1
    property double x2Max: 1

    state: ""

    Connections {
        target: uiHandler;
        onShowResult: {
            console.log("Signal: onShowResult");

            value_fx.text = fx;
            solutionView.varCount = N;
            solutionView.values = x;
            solutionView.fillList();

            if (N === 2) {
                state = "Nequals2";
            }
            else {
                state = "Nnot2";
            }

            x1Min = uiHandler.getMinimum(1);
            x1Max = uiHandler.getMaximum(1);
            x2Min = uiHandler.getMinimum(2);
            x2Max = uiHandler.getMaximum(2);

            text_X1Min.text = x1Min;
            text_X1Max.text = x1Max;
            text_X2Min.text = x2Min;
            text_X2Max.text = x2Max;

            graphView.drawGraph([x1Min, x1Max, x2Min, x2Max]);
            graphView.setViewToOrto();
        }
    }

    HarmonyMemoryDialog {
        id: hmDialog;
    }

    btn_showHM.onClicked: {
        hmDialog.open();
    }

    btn_3D.onClicked: {
        graphView.setViewTo3D();
    }

    btn_orto.onClicked: {
        graphView.setViewToOrto();
    }

    btn_drawGraph.onClicked: {
        x1Min = text_X1Min.text;
        x1Max = text_X1Max.text;
        x2Min = text_X2Min.text;
        x2Max = text_X2Max.text;

        graphView.drawGraph([x1Min, x1Max, x2Min, x2Max]);
    }

    GraphControlDialog {
        id: graphControlDialog;
    }

    btn_rules.onClicked: {
        graphControlDialog.open();
    }
}
