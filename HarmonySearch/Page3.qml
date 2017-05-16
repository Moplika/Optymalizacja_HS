import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Page3Form {

    HarmonyMemoryView {
        id: harmonyMemoryView;
        anchors.fill: parent;
    }

    Connections {
        target: uiHandler;
        onShowResult: {
            harmonyMemoryView.drawHarmonyMemory();
        }
    }
}
