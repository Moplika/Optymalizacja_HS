import QtQuick 2.4

IterationViewForm {
    property int varCount: 0
    property int maxIterations: 0

    anchors.fill: parent;

    btn_nextIter.onClicked: {
//        console.log("Let's show next iteration")
        uiHandler.nextIteration();
    }

    btn_end.onClicked: {
        uiHandler.finishIterating();
    }

    btn_orto.onClicked:  {
//        console.log("Widok warstwic");
        graphView.setViewToOrto();
    }

    btn_view3D.onClicked: {
//        console.log("Widok 3D");
        graphView.setViewTo3D();
    }

    Connections {
        target: uiHandler;
        onShowIteration : {
//            console.log("Signal: onShowIteration");

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
            if (currentSolutionPos !== -1) {
                harmonyMemoryView.highlightIndex(currentSolutionPos+1);
            }
            else {
                harmonyMemoryView.highlightIndex(-1);
            }

            if(iterationNo === maxIterations) {
                btn_nextIter.text = "Wyszukiwanie zakończone";
                btn_nextIter.enabled = false;
            }
        }
        onStartShowingIterations: {
//            console.log("Signal: onStartShowingIterations")

            varCount = uiHandler.getN();
            maxIterations = uiHandler.getNI();

            btn_nextIter.text = "Wyświetl następną iterację";
            btn_nextIter.enabled = true;

            if (varCount === 2) {
//                graphView.visible = true;
//                btn_orto.visible = true;
//                btn_view3D.visible = true;
//                uiHandler.drawSurfaceGraph(-1,1,-1,1);
//                graphView.setAxis([-1,1,-1,1]);
            }
            else {
                graphView.visible = false;
                btn_orto.visible = false;
                btn_view3D.visible = false;
            }
        }
    }
}
