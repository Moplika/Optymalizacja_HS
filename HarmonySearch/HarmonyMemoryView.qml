import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {

    HarmonyMemoryListView {
        id: harmonyMemoryListView
        anchors.fill: parent

        varCount: 0
        listValues: []
    }

    Button {
        id: btn_test
        x: 0
        y: 500
        width: parent.width
        height: 50
        text: "Click!"
        onClicked:
        {
            console.log("Btn clicked")
            drawHarmonyMemory();
        }
    }

    function drawHarmonyMemory()
    {
        harmonyMemoryListView.varCount = uiHandler.getN();
        harmonyMemoryListView.listModel.clear();
        harmonyMemoryListView.createHeader();
        uiHandler.printHarmonyMemory();
    }

    Connections {
        target: uiHandler;
        onShowHarmonyMemoryRow: {
            console.log(values);

            harmonyMemoryListView.listIndex = id;
            harmonyMemoryListView.listValues = values;
            harmonyMemoryListView.appendList();
        }
    }
}
