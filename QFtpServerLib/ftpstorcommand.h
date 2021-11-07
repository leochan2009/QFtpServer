#ifndef FTPSTORCOMMAND_H
#define FTPSTORCOMMAND_H

#include "ftpcommand.h"

class QFile;

// Implements the STOR and APPE commands. Used to upload files to the ftp
// server.

class FtpStorCommand : public FtpCommand
{
    Q_OBJECT
public:
    explicit FtpStorCommand(QObject *parent, const QString &fileName, bool appendMode = false, qint64 seekTo = 0);
    ~FtpStorCommand();
    void setFileName(QString name) {this->fileName = name;};
    void setAppendMode(bool mode) {this->appendMode = mode;};
    void setSeekTo(qint64 pos){this->seekTo = pos;};
private slots:
    void acceptNextBlock();

signals:
    void newDataArrived(QString filename, QByteArray bytes);
private:
    void startImplementation();

    QString fileName;
    QFile *file;
    bool appendMode;
    qint64 seekTo;
    bool success;
    bool m_onlyStreaming;
};

#endif // FTPSTORCOMMAND_H
