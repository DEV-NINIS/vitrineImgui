import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3




Page {
    width: 480
    height: 900

    title: qsTr("Page 1")
    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }
}
