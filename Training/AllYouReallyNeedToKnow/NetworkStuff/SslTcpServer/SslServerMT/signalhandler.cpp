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
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "disconnected";
    socket->deleteLater();
}

void SignalHandler::on_socket_readyRead()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "readyRead from slot";
    qInfo() << "Read from SignalHandler:" << socket->readAll();

    QByteArray response = "Dave, my mind is going. I can feel it.";

    socket->write(response);
    socket->waitForBytesWritten();

    socket->close();
    socket->deleteLater();
}

void SignalHandler::on_socket_encrypted()
{
    qInfo() << "encrypted";
}

void SignalHandler::on_socket_encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten:" << written;
}

void SignalHandler::on_socket_modeChanged(QSslSocket::SslMode mode)
{
    qInfo() << "modeChanged:" << mode;
}

void SignalHandler::on_socket_peerVerifyError(const QSslError &error)
{
    qInfo() << "peerVerifyError:" << error.errorString();
}

void SignalHandler::on_socket_errorOccurred(QAbstractSocket::SocketError err)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo() << "errorOccurred:"<< metaEnum.valueToKey( err );
}

void SignalHandler::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "SsslErrors:" << errors;
    // m_server->ignoreSslErrors( errors );
}
