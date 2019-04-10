#include "CopyHelper.h"

CopyHelper::CopyHelper(QObject *parent) : QObject(parent)
{

}

void CopyHelper::setTarget(QString path, QString name)
{
    target = path + name;
}

void CopyHelper::setSource(QString path, QString name)
{
    source = path + name;
}

void CopyHelper::setTarget(QString file)
{
    if("file:///" == file.left(8))
        file.remove(0,8);
    target = file;
}

void CopyHelper::setSource(QString file)
{
    if("file:///" == file.left(8))
        file.remove(0,8);
    source = file;
}

void CopyHelper::setModel(bool hasProgress)
{
    copyModel = hasProgress;
}

void CopyHelper::startCopy()
{
    QThread * childthread =  new QThread();
    CopyFile *DoCopy_File = new CopyFile();
    DoCopy_File->setSource(source);
    DoCopy_File->setTarget(target);
    DoCopy_File->moveToThread(childthread); //放到子线程中传输
    connect(DoCopy_File,SIGNAL(update_process(QString)),this,SLOT(reciveCopyPro(QString)));
    connect(childthread, SIGNAL(finished()), childthread, SLOT(deleteLater()));
    connect(childthread, &QThread::finished, childthread, &QObject::deleteLater);
    childthread->start();
    DoCopy_File->startCopy();
}

void CopyHelper::reciveCopyPro(QString Pro_valu)
{
    emit update_pro(Pro_valu);
}
