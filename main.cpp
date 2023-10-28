#include <QWebChannel>
#include <QWebEngineView>
#include <QQmlContext>
#include "MyNetworkRequest.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWebEngineView view;
    MyNetworkRequest networkRequest;

    QWebChannel channel;
    channel.registerObject("networkRequest", &networkRequest);

    view.page()->setWebChannel(&channel);

    // Load your HTML/JavaScript file that uses the WebChannel

    view.show();

    return app.exec();
}