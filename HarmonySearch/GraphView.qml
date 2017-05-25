import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtDataVisualization 1.2

Item {
//    anchors.fill: parent;

    width: parent.width;
    height: parent.height;

    Graph {
        id: surfaceGraph;
        anchors.fill: parent;
    }

    function setViewTo3D() {
        surfaceGraph.setViewTo3D();
    }

    function setViewToOrto() {
        surfaceGraph.setViewToOrto();
    }

    function drawGraph(values) {
        surfaceGraph.drawGraph(values);
    }
}


