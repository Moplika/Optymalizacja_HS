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

    width: parent.width;
    height: parent.height;

    ColumnLayout {
        width: parent.width;
        height: parent.height;
        Surface3D {
            id: surfaceGraph
//            anchors.fill: parent;
            Layout.preferredWidth: parent.width;
            Layout.fillHeight: true;

            axisX: x1Axis;
            axisZ: x2Axis;
            axisY: yAxis;

            theme: graphTheme;

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

        RowLayout {
            Layout.preferredWidth: parent.width;
            Layout.preferredHeight: 50;

            Button {
                id: btn_graph3DView;
                Layout.fillWidth: true;
                text: "Widok 3D";
                onClicked:  {
                    surfaceGraph.orthoProjection = false;
                    surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetFront;
                    surfaceGraph.flipHorizontalGrid = false;

                }
            }

            Button {
                id: btn_graphOrto;
                Layout.fillWidth: true;
                text: "Widok warstwic";
                onClicked: {
                    surfaceGraph.orthoProjection = true;
                    surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetDirectlyAbove
                    surfaceGraph.flipHorizontalGrid = true;
//                    surfaceGraph.graphTheme.gridEnabled = false;
                }
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

    function addData(values) {
        var params = {
            x1: values[0],
            x2: values[1],
            y: values[2]
        };
        dataModel.append(params);
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


