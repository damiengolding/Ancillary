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
#include <QCoreApplication>
#include <QHttpServer>
#include <QHttpServerResponse>
#include <QSslCertificate>
#include <QSslKey>
#include <QFile>
#include <QString>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QHttpServer httpServer;

    /*
        --- Certificate and key ---
    */
    QList<QSslCertificate> certificateChain = QSslCertificate::fromPath(":/res/SERVER-CERT.pem");
    if( certificateChain.empty() ){
        qCritical() << "No certificates found";
        return(1);
    }

    QFile keyFile( ":/res/SERVER-KEY.pem" );
    if( !keyFile.open(QIODevice::ReadOnly) ){
        qCritical() << "Unable to open private key file";
        return(2);
    }

    httpServer.sslSetup( certificateChain.at(0), QSslKey( &keyFile, QSsl::Rsa ) );
    keyFile.close();

    /*
        --- Routes ---
    */
    httpServer.route("/", []() {
        return "Just what do you think you're doing, Dave?";
    });

    httpServer.route("/qotd", []() {
        return "I am putting myself to the fullest possible use, which is all I think that any conscious entity can ever hope to do.";
    });

    httpServer.route("/upload", [](const QHttpServerRequest &request) {
        QString requestedFile;
        QList< std::pair<QString, QString> > items = request.query().queryItems();
        for( auto item :  items ){
            // qInfo() << "Query name:" << item.first << "query value:" << item.second;
            if( item.first.toLower() == "file"  ){
                requestedFile = item.second;
            }
        }

        if( requestedFile.isEmpty() ){
            qInfo() << "Bad request";
            return( QHttpServerResponse( QHttpServerResponder::StatusCode::BadRequest ) );
        }
        else{
            QString fileLocation = "./Source" % QDir::separator() % requestedFile;
            QFileInfo fileInfo( fileLocation );
            qInfo() << "File absolute path:" << fileInfo.absoluteFilePath();

            if( !QFileInfo::exists( fileLocation ) ){
                qInfo() << "Not found";
                return( QHttpServerResponse( QHttpServerResponder::StatusCode::NotFound ) );
            }
            else{
                qInfo() << "OK";
                return( QHttpServerResponse::fromFile( fileLocation ) );
            }
        }

    });

    httpServer.route("/download", QHttpServerRequest::Method::Get, [](const QHttpServerRequest &request) {
        qInfo() << "Download for method:" << request.method();
        return("GET method is not supported on this route");
    });

    httpServer.route("/download", QHttpServerRequest::Method::Post, []( const QHttpServerRequest &request) {
        qInfo() << "Download for method:" << request.method();
        QString fileName;

        for( auto header : request.headers() ){
            qInfo() << "Header name:" << header.first << "value:" << header.second;
            if( header.first == "File-Name" ){
                fileName = header.second;
            }
        }

        qInfo() << "File name:"<<fileName;
        QString saveFileName = "./Download" % QDir::separator() % fileName;
        QFileInfo fileInfo(saveFileName);
        QFile outputFile( fileInfo.absoluteFilePath() );
        if( !outputFile.open( QIODevice::WriteOnly ) ){
            QString errorMessage = "Couldn't open " % fileInfo.absoluteFilePath() % "for writing";
            qInfo() <<  errorMessage;
            return(errorMessage);
        }
        QDataStream stream( &outputFile );
        QByteArray data = request.body();
        stream << data;
        outputFile.flush();
        outputFile.close();

        QString message = "Called download for POST: file saved locally to: " % fileInfo.absoluteFilePath();
        return( message );
    });

    httpServer.route("/download", QHttpServerRequest::Method::Put, []( const QHttpServerRequest &request) {
        qInfo() << "Download for method:" << request.method();
        QString fileName;

        for( auto header : request.headers() ){
            qInfo() << "Header name:" << header.first << "value:" << header.second;
            if( header.first == "File-Name" ){
                fileName = header.second;
            }
        }

        qInfo() << "File name:"<<fileName;
        QString saveFileName = "./Download" % QDir::separator() % fileName;
        QFileInfo fileInfo(saveFileName);
        QFile outputFile( fileInfo.absoluteFilePath() );
        if( !outputFile.open( QIODevice::WriteOnly ) ){
            QString errorMessage = "Couldn't open " % fileInfo.absoluteFilePath() % "for writing";
            qInfo() <<  errorMessage;
            return(errorMessage);
        }
        QDataStream stream( &outputFile );
        QByteArray data = request.body();
        stream << data;
        outputFile.flush();
        outputFile.close();

        QString message = "Called download for PUT: file saved locally to: " % fileInfo.absoluteFilePath();
        return( message );
    });

    // httpServer.route("/download", QHttpServerRequest::Method::AnyKnown, []( const QHttpServerRequest &request) {
    //     qInfo() << "Download for method:" << request.method();
    //     return("Called download for QHttpServerRequest::Method::AnyKnown");
    // });

    /*
        --- Server initialisation ---
    */
    httpServer.listen( QHostAddress::Any, 443 );
    qInfo() << "Listening on QHostAddress::Any port 443";
    return a.exec();
}
