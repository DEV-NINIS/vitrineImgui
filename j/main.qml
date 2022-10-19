import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQml 2.3
import QtPositioning 5.11

ApplicationWindow {
    id: window
    width: 480
    height: 900
    visible: true
    title: qsTr("Stack")

    property int distanceBegin: sliderDistance.first.value
    property int distanceEnd: sliderDistance.second.value
    property double widhtslider: drawer.widht *0.8
    property double  heightSlider: drawer.height * 0.03

    header: ToolBar {
        id: toolbar
        contentHeight: parent.height / 10
        background: Rectangle { color: "#1f1f1f"}
        Rectangle {
            id: rectangle2

            width: parent.width / 3
            height: toolbar.height
        anchors.left: parent.left
        radius: 25

        color: "#ececec"
        border.width: 5
        border.color: "#1f1f1f"
        Text {
            id: textrect2
            text: qsTr("Filters")
            anchors.centerIn: parent
            color: "#1f1f1f"
            font.pixelSize: 20



        }

        Behavior on width {
                NumberAnimation { duration: 300 }
            }
        Behavior on radius {
                NumberAnimation { duration: 300 }
            }



        ParallelAnimation {
            id: changeColRect2ToBlack
            PropertyAnimation {id: animateColorToBlackRect2; target: rectangle2; properties: "color"; to:"#1f1f1f"; duration: 300}
            PropertyAnimation {id: animateColorTextToWhiteRect2; target: textrect2; properties: "color"; to: "#ececec"; duration: 300}
            PropertyAnimation {id: animateColorTextToBlackRect1; target: textrect1; properties: "color"; to: "#1f1f1f"; duration: 300}
            PropertyAnimation {id: animateColorToWhiteRect1; target: rectangle1; properties: "color"; to: "#ececec" ;duration: 300}





        }



        MouseArea {
                anchors.fill: rectangle2
                onClicked: {

                    changeColRect2ToBlack.start()

                    rectangle2.width = parent.parent.width - parent.parent.width/3
                    rectangle1.width = parent.parent.width/3
                    rectangle1.radius = 25
                rectangle2.radius = 0

                    drawer.open()



                    }


                     }


             }




        Rectangle {
            id: rectangle1

            width: parent.width - parent.parent.width/3
            height: parent.height

            border.width: 5
            color: "#1f1f1f"

            border.color: "#1f1f1f"

            anchors.right: parent.right
            Text {
                id: textrect1
                text: qsTr("Map")
                anchors.centerIn: parent
                font.pixelSize: 20
                color:  Qt.rgba(10, 10, 10)



            }
            Behavior on width {
                    NumberAnimation { duration: 300 }
                }
            Behavior on radius {
                    NumberAnimation { duration: 300 }
                }



            ParallelAnimation {
                id: changeColRect2ToWhite
                PropertyAnimation {id: animateColorToWhiteRect2; target: rectangle2; properties: "color"; to: "#ececec"; duration: 300}
                PropertyAnimation {id: animateColorTextToBlackRect2; target: textrect2; properties: "color"; to: "#1f1f1f"; duration: 300}
                PropertyAnimation {id: animateColorTextToWhiteRect1; target: textrect1; properties: "color"; to: "#ececec"; duration: 300}
                PropertyAnimation {id: animateColorToBlackRect1; target: rectangle1; properties: "color"; to: "#1f1f1f"; duration: 300}



            }



            MouseArea {
                    anchors.fill: rectangle1

                    onClicked: {
                        changeColRect2ToWhite.start()

                           rectangle1.width = parent.parent.width - parent.parent.width/3
                            rectangle1.radius = 0
                        rectangle2.radius = 25
                           rectangle2.width = parent.parent.width/3

                            stackView1.pop()
                            drawer.close()
                            stackView1.push(Qt.resolvedUrl("Page1Form.ui.qml"))


                           }




                    }
                 }

        Drawer {
        id: drawer
        y: header.height
        width: rectangle2.width
        height: window.height - header.height

        Slider{
            id: sliderDistance
            width: drawer.width*0.8
            height: drawer.height/50
            y: drawer.height / 20
            from: 1
            to: 500

            background: Rectangle {

                color: "#1f1f1f"



                radius: 15
            }
            handle: Rectangle {
                id: handle1
             width: sliderDistance.height * 1
                  height: sliderDistance.height * 1

                  gradient: Gradient {
                      GradientStop {
                          position: 0.00;
                          color: "white";
                      }

                      GradientStop {
                          position: 1.00;
                          color: "gray";
                      }
                  }

                  radius: width*0.5
             x: parent.visualPosition * (parent.availableWidth - handle1.width / 2)
            }
        }




}





    }





    StackView {
        id: stackView1
        initialItem: "Page1Form.ui.qml"
        anchors.fill: parent


    }


}






