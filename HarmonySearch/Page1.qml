import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3


Page1Form {
    id: page1

    // Początkowe wartości checkboxa i pól "show iterations"
    checkBox_iterations.checked: false;
    label_iterations.visible: false;
    textField_iterations.visible: false;
    text_coverIterations.visible: true;

    // Początkowe wartości pozostałych pól
    textField_HMSize.text: "10";
    textField_HMCR.text: "0.75";
    slider_HMCR.value: 0.75;
    textField_PAR.text: "0.45";
    slider_PAR.value: 0.45;
    textField_NI.text: "10000";
    textField_iterations.text: "100";

    // Przepisywanie wartości pomiędzy suwakiem a polem tekstowym
    slider_HMCR.onValueChanged: {
        textField_HMCR.text = slider_HMCR.value.toFixed(2);
    }

    slider_PAR.onValueChanged: {
        textField_PAR.text = slider_PAR.value.toFixed(2);
    }

    Connections {
       target: textField_HMCR
       onEditingFinished: {
           slider_HMCR.value = textField_HMCR.text;
       }
    }

    Connections {
       target: textField_PAR
       onEditingFinished: {
           slider_PAR.value = textField_PAR.text;
       }
    }

    // Pokazywanie i ukrywanie części "pokazuj co... iteracji"
    checkBox_iterations.onCheckStateChanged: {
        label_iterations.visible = checkBox_iterations.checked;
        textField_iterations.visible = checkBox_iterations.checked;
        text_coverIterations.visible = !checkBox_iterations.checked;
    }

    // Przywrócenie domyślnych wartości parametrów
    btn_restoreDefault.onClicked: {
        textField_HMSize.text = 10;
        textField_HMCR.text = 0.75;
        slider_HMCR.value = 0.75;
        textField_PAR.text = 0.45;
        slider_PAR.value = 0.45;
        textField_NI.text = 10000;
        checkBox_iterations.checked = false;
        textField_iterations.text = 100;
        label_equationState.text = ""
        label_equationState.color = "black";
    }

    // Wyświetlenie zasad wpisywania równania
    btn_rules.onClicked: {
        rulesDialog.open();
    }

    RulesDialog {
        id: rulesDialog
    }

    // Pokazanie okienka do wprowadzenia ograniczeń
    btn_constraints.onClicked: {
        constraintsDialog.open();
    }
    ConstraintsDialog {
        id: constraintsDialog
    }

    // Pokazywanie stanu ograniczeń
    Connections {
        target: uiHandler;
        onConstraintsOk: {
            label_equationState.text = ""
            label_equationState.color = "black";
            btn_constraints.highlighted = false;
            console.log("Signal: onConstraitnsOk")
        }
        onParametersOk: {
            label_equationState.text = ""
            label_equationState.color = "black";
            console.log("Signal: onParametersOk")
        }
        onEquationOk: {
            label_equationState.text = ""
            label_equationState.color = "black";
            console.log("Signal: onEquationOk")
        }
        onTooManyConstraints: {
            label_equationState.text = "Zbyt dużo ograniczeń!"
            label_equationState.color = "blue";
            console.log("Signal: onTooManyConstraints")
        }
        onNotEnoughConstraints: {
            label_equationState.text = "Zbyt mało ograniczeń!"
            label_equationState.color = "red";
            btn_constraints.highlighted = true;
            console.log("Signal: onNotEnoughConstraints")
        }
        onConstraintsWrong: {
            label_equationState.text = "Błędne ograniczenia!"
            label_equationState.color = "red";
            btn_constraints.highlighted = true;
            console.log("Signal: onConstraintsWrong")
        }
        onParametersWrong: {
            label_equationState.text = "Błędne parametry!"
            label_equationState.color = "red";
            console.log("Signal: onParametersWrong")
        }
        onEquationWrong: {
            label_equationState.text = "Błędnie wprowadzone równanie!"
            label_equationState.color = "red";
            console.log("Signal: onEquationWrong")
        }
    }

    // Przekazywanie wartości do C++
    btn_calculate.onClicked: {
        uiHandler.clearParameters();
        uiHandler.setHMS(textField_HMSize.text);
        uiHandler.setHMCR(slider_HMCR.value.toFixed(2));
        uiHandler.setPAR(slider_PAR.value.toFixed(2));
        uiHandler.setNI(textField_NI.text);
        uiHandler.setShowIterations(checkBox_iterations.checkState);
        uiHandler.setIterationNb(textField_iterations.text);

        uiHandler.startCalculations();
    }

    // Przesyłanie równania
    Connections {
        target: textField_equation;
        onEditingFinished: {
            uiHandler.setEquation(textField_equation.text);
            console.log("Equation set?")
        }

    }
}
