// This is just POC
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

MyNetworkRequest::MyNetworkRequest() {}

void MyNetworkRequest::sendRequest(const QString& url, const QString& data) {
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = manager.post(request, data.toUtf8());

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Handle the successful response
            emit requestFinished(reply->readAll());
        } else {
            // Handle the error
            emit requestError(reply->errorString());
        }

        reply->deleteLater();
    });
}



