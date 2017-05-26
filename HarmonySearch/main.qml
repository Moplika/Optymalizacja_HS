import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Harmony Search")
    id: mainWindow;

    SwipeView {
        id: swipeView;
        anchors.fill: parent;
        currentIndex: tabBar.currentIndex;
        interactive: false;

        Page1 {

        }

        Page2 {
        }

        Page3 {

        }


    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Parametry")
        }
        TabButton {
            text: qsTr("Wynik obliczeń")
        }
        TabButton {
            text: qsTr("Widok iteracji")
        }
    }
}
