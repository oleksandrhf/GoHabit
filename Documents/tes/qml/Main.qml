import Felgo 3.0
import QtQuick 2.0
import "model"
import "logic"
import "pages"

import "helper"

/*/////////////////////////////////////
  NOTE:
  Additional integration steps are needed to use Felgo Plugins, for example to add and link required libraries for Android and iOS.
  Please follow the integration steps described in the plugin documentation of your chosen plugins:
  - AdMob: https://felgo.com/doc/plugin-admob/
  - Google Analytics: https://felgo.com/doc/plugin-googleanalytics/
  - Local Notifications: https://felgo.com/doc/plugin-notification/
  - Firebase: https://felgo.com/doc/plugin-firebase/

  To open the documentation of a plugin item in Qt Creator, place your cursor on the item in your QML code and press F1.
  This allows to view the properties, methods and signals of Felgo Plugins directly in Qt Creator.

/////////////////////////////////////*/

App {
    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    // app initialization
    Component.onCompleted: {
        // if device has network connection, clear cache at startup
        // you'll probably implement a more intelligent cache cleanup for your app
        // e.g. to only clear the items that aren't required regularly
        if(isOnline) {
            logic.clearCache()
        }

        // fetch todo list data
        logic.fetchTodos()
        logic.fetchDraftTodos()
    }

    // business logic
    Logic {
        id: logic
    }

    // model
    DataModel {
        id: dataModel
        dispatcher: logic // data model handles actions sent by logic

        // global error handling
        onFetchTodosFailed: nativeUtils.displayMessageBox("Unable to load todos", error, 1)
        onFetchTodoDetailsFailed: nativeUtils.displayMessageBox("Unable to load todo "+id, error, 1)
        onStoreTodoFailed: nativeUtils.displayMessageBox("Failed to store "+viewHelper.formatTitle(todo))
    }

    // helper functions for view
    ViewHelper {
        id: viewHelper
    }

    // view
    Navigation {
        id: navigation

        // only enable if user is logged in
        // login page below overlays navigation then
        enabled: dataModel.userLoggedIn

        // first tab
        NavigationItem {
            title: qsTr("Todo List")
            icon: IconType.list

            NavigationStack {
                splitView: tablet // use side-by-side view on tablets
                initialPage: TodoListPage { }
            }
        }

        // second tab
        NavigationItem {
            title: qsTr("Profile") // use qsTr for strings you want to translate
            icon: IconType.circle

            NavigationStack {
                initialPage: ProfilePage {
                    // handle logout
                    onLogoutClicked: {
                        logic.logout()

                        // jump to main page after logout
                        navigation.currentIndex = 0
                        navigation.currentNavigationItem.navigationStack.popAllExceptFirst()
                    }
                }
            }
        }
    }

    // login page lies on top of previous items and overlays if user is not logged in
    LoginPage {
        visible: opacity > 0
        enabled: visible
        opacity: dataModel.userLoggedIn ? 0 : 1 // hide if user is logged in

        Behavior on opacity { NumberAnimation { duration: 250 } } // page fade in/out
    }


    // This item contains example code for the chosen Felgo Plugins
    // It is hidden by default and will overlay the QML items above if shown
    PluginMainItem {
        id: pluginMainItem
        visible: false // set this to true to show the plugin example

        // properties to keep only one instance of these plugin-pages alive within app
        // when building your own app, move the Plugin Items to Main.qml for global access
        property alias notificationPage: notificationPage
        property alias firebasePage: firebasePage

        LocalNotificationPage {
            id: notificationPage
            visible: false
            onPopped: { notificationPage.parent = pluginMainItem; visible = false }
        }

        FirebasePage {
            id: firebasePage
            visible: false
            onPopped:  { firebasePage.parent = pluginMainItem; visible = false }
        }
    }
}
