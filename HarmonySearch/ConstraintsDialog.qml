import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Dialog {
    x: (parent.width - width) / 2;
    y: (parent.height - height) / 2;
    width: page1.width / 3 * 2;

    modal: true;
    title: "Ograniczenia zmiennych";
    standardButtons: Dialog.Save | Dialog.Close;

    ColumnLayout {
        anchors.fill: parent

        ConstraintsRow {
            id: rowX1
            index: 1
        }

        ConstraintsRow {
            id: rowX2
            index: 2
        }

        ConstraintsRow {
            id: rowX3
            index: 3
        }

        ConstraintsRow {
            id: rowX4
            index: 4
        }

        ConstraintsRow {
            id: rowX5
            index: 5
        }

        ConstraintsRow {
            id: rowX6
            index: 6
        }

        ConstraintsRow {
            id: rowX7
            index: 7
        }

        ConstraintsRow {
            id: rowX8
            index: 8
        }

        ConstraintsRow {
            id: rowX9
            index: 9
        }

        ConstraintsRow {
            id: rowX10
            index: 10
        }
    }
    onAccepted: {
        console.log("Test test test");
        rowX1.sendConstraints();
        rowX2.sendConstraints();
        rowX3.sendConstraints();
        rowX4.sendConstraints();
        rowX5.sendConstraints();
        rowX6.sendConstraints();
        rowX7.sendConstraints();
        rowX8.sendConstraints();
        rowX9.sendConstraints();
        rowX10.sendConstraints();

        uiHandler.rewriteConstraints();
    }
}
