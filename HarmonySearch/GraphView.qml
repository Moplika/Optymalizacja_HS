import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtDataVisualization 1.2

Item {
    Graph {
        id: solutionGraph;
        anchors.fill: parent;

        x1Min: -1;
        x1Max: 1;
        x2Min: -1;
        x2Max: 1;
    }

    function setViewTo3D() {
        solutionGraph.setViewTo3D();
    }

    function setViewToOrto() {
        solutionGraph.setViewToOrto();
    }

    function setAxis(values) {
        solutionGraph.setAxis(values);
    }
}


