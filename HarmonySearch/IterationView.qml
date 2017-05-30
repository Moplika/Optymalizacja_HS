import QtQuick 2.4

IterationViewForm {
    property int varCount: 0
    property int maxIterations: 0

    property bool isShowingWaitScreen: false;

    anchors.fill: parent;

    btn_nextIter.onClicked: {
        uiHandler.nextIteration();
    }

    btn_showResult.onClicked: {
        page2.state = "base state";
    }

    btn_end.onClicked: {
        isShowingWaitScreen = true;
        iterationViewPage.state = "CalculationState";
        delay(100);
    }

    Connections {
        target: uiHandler;
        onShowIteration : {
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
                isShowingWaitScreen = false;
                iterationViewPage.state = "";
                btn_nextIter.visible = false;
                btn_showResult.visible = true;
                btn_end.enabled = false;
            }
        }
        onStartShowingIterations: {
            btn_nextIter.visible = true;
            btn_showResult.visible = false;

            varCount = uiHandler.getN();
            maxIterations = uiHandler.getNI();

            btn_end.enabled = true;
        }
    }

    Timer {
        id: delayTimer
        onTriggered: {
            uiHandler.finishIterating();
        }
    }

    function delay(delayTime) {
        delayTimer.interval = delayTime;
        delayTimer.repeat = false;
        delayTimer.start();
    }
}
