import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtDataVisualization 1.2

Item {
    property double x1Min: -1
    property double x1Max: 1
    property double x2Min: -1
    property double x2Max: 1

    property alias surfaceGraph: surfaceGraph

//    anchors.fill: parent;
    width: parent.width;
    height: parent.height;

    ListModel {
        id: dataModel
//        ListElement{ x1: ""; x2: ""; y: ""; }

    }

    ValueAxis3D {
        id: x1Axis

        min: x1Min
        max: x1Max
        title: "x1"
    }
    ValueAxis3D {
        id: x2Axis

        min: x2Min
        max: x2Max
        title: "x2"
    }
    ValueAxis3D {
        id: yAxis
        autoAdjustRange: true
        title: "f(x)"
    }

    ColorGradient {
        id: graphGradient;

        ColorGradientStop {
            position: 0.0;
            color: "red";
        }
        ColorGradientStop {
            position: 0.3;
            color: "yellow";
        }
        ColorGradientStop {
            position: 1;
            color: "green";
        }
    }

    Surface3D {
        id: surfaceGraph
        anchors.fill: parent;
        width: parent.width;
        height: parent.height;

        axisX: x1Axis;
        axisZ: x2Axis;
        axisY: yAxis;

        orthoProjection: true
        scene.activeCamera.cameraPreset: Camera3D.CameraPresetDirectlyAbove
        flipHorizontalGrid: true

        theme: Theme3D {
            type: Theme3D.ThemeQt;
            colorStyle: Theme3D.ColorStyleObjectGradient
            baseGradients: [graphGradient]
        }

        Surface3DSeries {
            id: firstSeries
            itemLabelFormat: "x1 = @xLabel, x2 = @zLabel: y(x) = @yLabel";

            ItemModelSurfaceDataProxy {
                id: dataProxy;
                itemModel:  dataModel;
                rowRole: "x1";
                columnRole: "x2";
                yPosRole: "y";

            }
        }
    }

    function addData(values) {
        var params = {
            x1: values[0],
            x2: values[1],
            y: values[2]
        };
        dataModel.append(params);
    }

    // Wyrzucić ten guzik, przepiąć w inne miejsce
    Button {
        x: 0;
        y: 500;
        height: 50;
        text: "Click"
        onClicked: {
            uiHandler.drawSurfaceGraph(-1,1,-1,1);
        }
    }

    Connections {
        target: uiHandler;
        onDrawSurfaceGraphPoint: {
            addData(values);
        }
        onDrawingFinished: {
            dataProxy.itemModel = dataModel;
        }
    }
}


