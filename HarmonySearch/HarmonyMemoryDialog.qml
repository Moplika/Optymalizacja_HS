import QtQuick 2.0
import QtQuick.Controls 2.1

Dialog {
    id: harmonyMemoryDialog
    x: (parent.width - width) / 2;
    y: (parent.height - height) / 2;
    width: page2.width / 8 * 7;
    height: page2.height / 8 * 7;

    modal: true;

    title: "Postać pamięci harmonii";
    standardButtons: Dialog.Close;

    HarmonyMemoryView {
        id: harmonyMemoryViewDialog
        anchors.fill:parent;
    }
    onOpened: {
        console.log("Signal: onOpened");
        harmonyMemoryViewDialog.drawHarmonyMemory();
    }
//    Button {
//        id: btn_test;
//        text: "Test";
//        onClicked: harmonyMemoryViewDialog.drawHarmonyMemory();
//    }


}
