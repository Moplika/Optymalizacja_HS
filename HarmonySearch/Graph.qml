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

    id: mainView;

    width: parent.width;
    height: parent.height;

    anchors.fill: parent;

    Surface3D {
        id: surfaceGraph
        width: mainView.width;
        height: mainView.height;

        axisX: x1Axis;
        axisZ: x2Axis;
        axisY: yAxis;

        theme: graphTheme;

        customItemList: [
        Custom3DItem {
                id: customItem;
                meshFile: ":/mesh/cube.obj";
                textureFile: ":/mesh/texture.png";
                position: Qt.vector3d(0.0, 0.0, 0.5);

            }
        ]

        Surface3DSeries {
            id: mainSeries
            itemLabelFormat: "x1 = @xLabel, x2 = @zLabel: y(x) = @yLabel";
            selectedPoint: invalidSelectionPosition;

            ItemModelSurfaceDataProxy {
                id: mainDataProxy;
                itemModel:  mainDataModel;

                columnRole: "x1";
                rowRole: "x2";
                yPosRole: "y";
            }
        }
    }

    Theme3D {
        id: graphTheme;
        type: Theme3D.ThemeDigia;
        colorStyle: Theme3D.ColorStyleObjectGradient;
        baseGradients: [graphGradient];
        gridEnabled: true;
    }

    ListModel {
        id: mainDataModel
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
            position: 0.2;
            color: "yellow";
        }
        ColorGradientStop {
            position: 0.4;
            color: "green";
        }
        ColorGradientStop {
            position: 0.6;
            color: "deepskyblue";
        }
        ColorGradientStop {
            position: 0.8;
            color: "blue";
        }
        ColorGradientStop {
            position: 1;
            color: "purple";
        }
    }

    Connections {
        target: uiHandler;
        onDrawSurfaceGraphPoint: {
            addData(values);
        }
        onDrawingFinished: {
            drawOptimalSolution();
        }
    }

    function addData(values) {
        var params = {
            x1: values[0],
            x2: values[1],
            y: values[2]
        };
        mainDataModel.append(params);
    }

    function setViewTo3D() {
        surfaceGraph.orthoProjection = false;
        surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetFront;
        surfaceGraph.flipHorizontalGrid = false;
    }

    function setViewToOrto() {
        surfaceGraph.orthoProjection = true;
        surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetDirectlyAbove
        surfaceGraph.flipHorizontalGrid = true;
    }

    function setAxis(values) {
        x1Min = values[0];
        x1Max = values[1];
        x2Min = values[2];
        x2Max = values[3];

        x1Axis.max = x1Max;
        x2Axis.max = x2Max;
        x1Axis.min = x1Min;
        x2Axis.min = x2Min;

    }

    function drawGraph(values) {
        mainDataModel.clear();
        setAxis(values);

        uiHandler.drawSurfaceGraph(values[0], values[1], values[2], values[3]);
    }

    function drawOptimalSolution() {
        var values = uiHandler.getOptimalSolution();

        var yPos;

        if (values[2] > 0) {
            yPos = values[2] + 0.05 * values[2];
        }
        else {
            yPos = values[2] - 0.05 * values[2];
        }

        customItem.position = Qt.vector3d(values[0], yPos, values[1]);

        console.log("Optimal solution: ", values);
    }
}
