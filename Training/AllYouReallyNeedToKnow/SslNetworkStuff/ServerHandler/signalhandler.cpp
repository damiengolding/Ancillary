/*
MIT License

Copyright (c) Damien Golding 2024

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "signalhandler.hpp"

SignalHandler::SignalHandler(QObject *parent)
    : QObject{parent}
{

}

SignalHandler::~SignalHandler()
{

}

void SignalHandler::on_socket_disconnected()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Disconnecting:" << socket->objectName();
    socket->deleteLater();
}

void SignalHandler::on_socket_readyRead()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Ready to read:" << socket->objectName();
    qInfo() << "Read from client:" << socket->readAll();

    QByteArray response = "I am putting myself to the fullest possible use, which is all I think that any conscious entity can ever hope to do.";

    socket->write(response);
    socket->waitForBytesWritten();

    socket->close();
    socket->deleteLater();
}

void SignalHandler::on_socket_encrypted()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket now encrypted:" << socket->objectName();
}

void SignalHandler::on_socket_encryptedBytesWritten(qint64 written)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket" << socket->objectName() << "wrote" << written << "encrypted bytes";
}

void SignalHandler::on_socket_modeChanged(QSslSocket::SslMode mode)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket mode changed to" << mode;
}

void SignalHandler::on_socket_peerVerifyError(const QSslError &error)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Peer verify error:" << error.errorString();
}

void SignalHandler::sslErrors(const QList<QSslError> &errors)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "SSL Errors:" << errors;
    socket->ignoreSslErrors( errors );
}

void SignalHandler::on_socket_errorOccurred(QAbstractSocket::SocketError err){
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo() << "Error occurred:"<< metaEnum.valueToKey( err );
    // QList<QSslError> errors = socket->sslHandshakeErrors();
    // socket->ignoreSslErrors( errors );
    // for( auto error : errors  ){
    //     qInfo() << "Error:" << error.errorString();
    // }
}
