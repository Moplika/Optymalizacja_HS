import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Dialog {
    //id: rulesDialog;

    x: (parent.width - width) / 2;
    y: (parent.height - height) / 2;
    width: page1.width / 3 * 2;

    modal: true;
    title: "Zasady wprowadzania równań";
    standardButtons: Dialog.Close;

    Label {
        width: parent.width;
        text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc finibus "
              + "in est quis laoreet. Interdum et malesuada fames ac ante ipsum primis "
              + "in faucibus. Curabitur eget justo sollicitudin enim faucibus bibendum. "
              + "Suspendisse potenti. Vestibulum cursus consequat mauris id sollicitudin. \n"
              + "Duis facilisis hendrerit consectetur. Curabitur sapien tortor, efficitur "
              + "id auctor nec, efficitur et nisl. Ut venenatis eros in nunc placerat, "
              + "eu aliquam enim suscipit.";
        wrapMode: Label.Wrap;
    }
}
