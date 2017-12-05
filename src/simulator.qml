import QtQuick 2.2
import QtCanvas3D 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3

import "lib/simulator.js" as GLCode

Item{
    id:mainview
    width: 1280
    height: 768
    visible: true
    focus: true

    SplitView {
        id: splitView
        x: 0
        y: 0
        width: 950
        height: 768

        Canvas3D {
            id: canvas3d
            width: 950
            height: 768
            visible: true
            focus: true

            // Emitted when one time initializations should happen
            onInitializeGL: {
                GLCode.initializeGL(canvas3d);
            }
            // Emitted each time Canvas3D is ready for a new frame
            onPaintGL: {
                GLCode.paintGL(canvas3d);
            }
            onResizeGL: {
                GLCode.resizeGL(canvas3d);
            }
        }
    }

    SplitView {
        id: splitView1
        x: 950
        y: 0
        width: 330
        height: 768

        Rectangle{
            anchors.fill:parent
            color:"#e8f1fc"

            ColumnLayout{
                id: column
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: column.spacing

                GroupBox {
                    title: "Timer"
                    Layout.fillWidth: true
                    Layout.columnSpan: grid.columns
                    Label{
                        text:"00:00:00"
                    }
                }

                GroupBox {
                    title: "Simulator"
                    Layout.fillWidth: true
                    Layout.columnSpan: grid.columns

                    ColumnLayout{
                        anchors.fill: parent
                        Label{
                            text: "Set PM"
                        }
                        SpinBox {
                            id:setpm ;
                            value: 50;
                            Layout.fillWidth: true;
                            z: 5
                            minimumValue: 0
                            maximumValue: 500
                        }

                        RowLayout {
                            anchors.top:setpm.bottom +20;
                            Button { text: "Start" }
                            Button { text: "pause" }
                            Button { text: "stop" }
                        }
                    }
                }

                GroupBox {
                    title: "Mode"
                    Layout.fillWidth: true
                    Layout.columnSpan: grid.columns

                    ComboBox {
                        editable: true
                        model: ListModel {
                            id: windmode
                            ListElement { text: "heatExchange" }
                            ListElement { text: "internalRecycle" }
                            ListElement { text: "unidirectionalAirflow" }
                        }
                    }
                }
                GroupBox {
                    title: "View"
                    Layout.fillWidth: true
                    ColumnLayout {
                        anchors.fill: parent
                        Slider { id: sliderx; value: 0.5; Layout.fillWidth: true }
                        Slider { id: slidery; value: 0.5; Layout.fillWidth: true }
                        Slider { id: sliderz; value: 0.5; Layout.fillWidth: true }
                    }
                }

                GroupBox {
                    title: "Setting"
                    Layout.fillWidth: true
                    ColumnLayout {
                        anchors.fill: parent
                        CheckBox { text: "wind flow"}
                        CheckBox { text: "structure line"}
                        CheckBox { text: "trace" }
                    }
                }
            }
        }
    }
}
