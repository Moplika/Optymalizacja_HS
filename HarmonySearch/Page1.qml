import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3


Page1Form {
    id: page1

    ParametersView {
        anchors.fill: parent;
    }

//    Connections {
//        target: uiHandler;
//        onCalculationsStarted: {
//            console.log("Signal: onCalculationsStarted");
//            calculationInProgressView.visible = true;
//            parametersView.visible = false;
//        }
//        onCalculationsFinished: {
//            console.log("Signal: onCalculationsFinished");
//            calculationInProgressView.visible = false;
//            parametersView.visible = true;
//        }
//    }

//    ParametersView {
//        id: parametersView;
//        anchors.fill: parent;
//    }

//    CalculationInProgressView  {
//        id: calculationInProgressView;
//        anchors.fill: parent;
//        //        visible: false;
//    }

}
