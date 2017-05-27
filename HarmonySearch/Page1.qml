import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Page1Form {
    property bool isCalculating: false

    id: page1

    Connections {
        target: uiHandler;

        onCalculationsFinished: {
            console.log("Signal: onCalculationsFinished");
            state = "base state";
            // Przełącz na widok rozwiązania
            swipeView.incrementCurrentIndex();
        }
        onStartShowingIterations: {
            console.log("Signal: onStartShowingIterations");
            state = "base state";
            // Przełącz na widok rozwiązania
            swipeView.incrementCurrentIndex();
        }
    }
}
