#ifndef COPYFILE_H
#define COPYFILE_H

#include "copyfile_global.h"
#include <QObject>
#include <QFile>
#include <QDataStream>

class COPYFILESHARED_EXPORT CopyFile : public QObject
{
    Q_OBJECT
public:
    explicit CopyFile(QObject *parent = nullptr);
    Q_INVOKABLE void setTarget(QString path,QString name);
    Q_INVOKABLE void setSource(QString path,QString name);
    void startCopy();
    bool copyFileFunction( QString fromFIleName,  QString toFileName);
    bool copyFile(QString from,  QString to);
    void setTarget(QString file);
    void setSource(QString file);
    void setModel(bool hasProgress);
signals:
   void update_process(QString); //进度

private:
   QString source;
   QString target;
   bool copyModel;
};

#endif // COPYFILE_H
