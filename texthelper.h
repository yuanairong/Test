#ifndef TEXTHELPER_H
#define TEXTHELPER_H
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>
#include <QDir>
#include <QMessageBox>
#include <QStringList>
#include <QtXml>
#include "global.h"

class TextHelper
{
public:
    TextHelper();
    bool modifyTextStr(QString filePath, QString oriStr, QString newStr);
    QString readTextStr(QString filePath, QString objStr, QString typeFlag);
    QString readXml(QString xmlLine);
    bool modifyXml(QString filePath, QString attr, QString newStr);

    int     readCam(QString camType, QString dtsPath);
    void    writeCam(int preCamId, int curCamId, QString dtsPath);
    int     disableCam(int camId, QString dts);
    int     enableCam(int camId, QString dts);
    bool    writeToText(QString filePath, QString str, QString value, QString split);
    bool    addWallpaperXml(QString filePath, QString newLine);

private:
    QString oriText;
    QString newText;
    QString curPath;


};

#endif // TEXTHELPER_H
