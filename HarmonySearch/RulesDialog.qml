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
        text: "Wszystkie zmienne zawarte we wzorze funkcji celu powinny mieć postać xp. "
              + "Liczba zmiennych jest automatycznie obliczana na podstawie wzoru "
              + "funkcji celu \n"
              + "Wszystkie operacje mnożenia powinny być zapisane z użyciem operatora * (postać a*b) \n"
              + "Program obsługuje następujące funkcje matematyczne: \n"
              + "-> funkcje wielomianowe w postaci xp^n \n"
              + "-> funkcję eksponencjalną w postaci exp(xp) \n"
              + "-> funkcje wykładnicze w postaci a^xp \n"
              + "-> funkcję logarytmiczną o podstawie 2 w postaci log2(xp) \n"
              + "-> funkcję logarytmiczną o podstawie 10 w postaci log10(xp) \n"
              + "-> funkcję logarytmu naturalnego w postaci log(xp) lub ln(xp) \n"
              + "-> pierwiastek kwadratowy w postaci sqrt(xp) \n"
              + "-> pierwiastki wyższego stopnia w postaci root(a, xp) \n"
              + "-> wartość bezwzględnąw postaci abs(xp) \n"
              + "-> funkcje trygonomertyczne: sin(xp), cos(xp), tan(xp), "
              + "asin(xp), acos(xp), atan(xp)";
        font.pointSize: 11;
        wrapMode: Label.Wrap;
    }
}
