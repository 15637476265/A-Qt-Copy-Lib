#ifndef COPYHELPER_H
#define COPYHELPER_H

#include "copyfile_global.h"
#include <QObject>
#include <QDebug>

#include <QThread>
#include <QFile>
#include <QDataStream>
#include <QThread>
#include <QFileInfo>
#include "CopyFile.h"

class COPYFILESHARED_EXPORT CopyHelper : public QObject
{
    Q_OBJECT
public:
    explicit CopyHelper(QObject *parent = nullptr);
public:
    Q_INVOKABLE void setTarget(QString path,QString name);
    Q_INVOKABLE void setSource(QString path,QString name);
    Q_INVOKABLE void setTarget(QString file);
    Q_INVOKABLE void setSource(QString file);
    Q_INVOKABLE void setModel(bool hasProgress);
    Q_INVOKABLE void startCopy();

signals:
    void  update_pro(QString provalu);

public slots:
     void reciveCopyPro(QString);

private:
     QString source;
     QString target;
     bool copyModel;
};

#endif // COPYHELPER_H
