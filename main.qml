import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12
import tungpt.BackEnd 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property bool isSignedIn: false

    BackEnd{
        id: myBackEnd
        onLoginSucess: {
            console.log("Backend loginSucess!!!")
            root.isSignedIn = true
        }
        onLoginFail: {
            console.log("Backend loginFail!!!")
            root.isSignedIn = false
        }
    }

    Column{
        visible: !isSignedIn
        anchors.centerIn: parent
        spacing: 10
        TextField{
            id: userNameInput
            placeholderText: "User Name"
            width: parent.width
        }
        TextField{
            id: passwordInput
            placeholderText: "Pass Word"
            echoMode: TextInput.Password
            width: parent.width
        }
        Button{
            id: singInButton
            text: "Sign In"
            width: 200
            height: 80
            onClicked: {
                // root.isSignedIn = true
                myBackEnd.login(userNameInput.text, passwordInput.text)
                console.log("Button Sign In is clicked")
            }
        }
        Label{
            text: myBackEnd.status
        }
    }
    Column{
        visible: isSignedIn
        anchors.centerIn: parent
        spacing: 10
        Label{
            text: "Sign in sucess!!!"
            width: parent.width
        }
        Button{
            id: signOutButton
            width: 200
            height: 80
            text: "Sign Out"
            onClicked: {
                root.isSignedIn = false
                console.log("Button Sign Out is clicked")
            }
        }
    }
}
