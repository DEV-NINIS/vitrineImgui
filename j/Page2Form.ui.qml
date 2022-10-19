import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 480
    height: 900

    title: qsTr("Page 1")
    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
