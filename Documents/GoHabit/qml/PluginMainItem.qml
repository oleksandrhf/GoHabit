import Felgo 3.0
import QtQuick 2.0
import "helper"
import "pages"

Item {
    anchors.fill: parent

    // app content with plugin list
    NavigationStack {
        id: pluginMainItem

        // initial page contains list if plugins and opens pages for each plugin when selected
        ListPage {
            id: page
            title: qsTr("Felgo Plugins")

            model: ListModel {
                ListElement { type: "Analytics"; name: "Google Analytics"
                    detailText: "App Analytics & Events"; image: "../assets/logo-ga.png" }
            }

            delegate: PluginListItem {
                visible: name !== "GameCenter" || Theme.isIos
                opacity: enabled ? 1.0 : 0.3

                onSelected: {
                    switch (name) {
                    case "Google Analytics":
                        page.navigationStack.push(Qt.resolvedUrl("pages/GoogleAnalyticsPage.qml"))
                        break
                    }
                }
            }

            section.property: "type"
            section.delegate: SimpleSection { }
        }
    }
}
