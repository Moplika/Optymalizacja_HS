import QtQuick 2.0
import QtQuick.Controls 2.1

Dialog {
    x: (parent.width - width) / 2;
    y: (parent.height - height) / 2;
    width: page2.width / 3 * 2;

    modal: true;
    title: "Zasady sterowania wykresem";

    standardButtons: Dialog.Close;

    Label {
        width: parent.width;
        text: ""
              + "Dostępne są 2 tryby wyświetlania wykresu: tryb 3D i tryb warstwic. "
              + "Przełączanie między trybami odbywa się za pomocą przycisków pod wykresem. \n"
              + "Domyślnie wykres wyrysowany jest dla obszaru objętego ograniczeniami. "
              + "Zakres osi można zmienić w polach tekstowych pod wykresem. Po zmianie tych "
              + "wartości należy nacisnąć przycisk \"Rysuj nowy wykres\". \n "
              + "By obrócić wykres przytrzymać należy prawy przycisk myszy. \n"
              + "Wykres można przybliżać i oddalać za pomocą rolki \n"

        font.pointSize: 11;
        wrapMode: Label.Wrap;
    }
}
