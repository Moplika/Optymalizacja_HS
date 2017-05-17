import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Harmony Search")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

//        Page3 {

//        }

        Page1 {

        }

        Page2 {
        }


    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
//        TabButton {
//            text: qsTr("Test page")
//        }
        TabButton {
            text: qsTr("Parametry")
        }
        TabButton {
            text: qsTr("Wynik obliczeń")
        }
    }
}
