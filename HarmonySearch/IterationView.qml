import QtQuick 2.4

IterationViewForm {
    property int varCount: 0
    property int maxIterations: 0

    anchors.fill: parent;

    btn_nextIter.onClicked: {
        console.log("Let's show next iteration")
        uiHandler.nextIteration();
    }

    Connections {
        target: uiHandler;
        onShowIteration : {
            console.log("Signal: onShowIteration")
            varCount = uiHandler.getN();
            maxIterations = uiHandler.getNI();

            text_iterationNb.text = "Iteracja " + iterationNo;

            text_optimalYValue.text = optimalFx;
            solutionView_optimal.varCount = varCount;
            solutionView_optimal.values = optimalX;
            solutionView_optimal.fillList();

            text_newYValue.text = currentFx;
            solutionView_new.varCount = varCount;
            solutionView_new.values = currentX;
            solutionView_new.fillList();

            harmonyMemoryView.drawHarmonyMemory();

            if(iterationNo === maxIterations)
            {
                btn_nextIter.text = "Wyszukiwanie zakończone";
                btn_nextIter.enabled = false;
            }
        }
        onStartShowingIterations: {
            btn_nextIter.text = "Wyświetl następną iterację";
            btn_nextIter.enabled = true;
        }
    }
}
