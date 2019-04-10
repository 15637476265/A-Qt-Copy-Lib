#include "CopyFile.h"
#include <QDebug>

CopyFile::CopyFile(QObject *parent) : QObject(parent)
{
}

void CopyFile::setTarget(QString path, QString name)
{
    source = path + name;
}

void CopyFile::setSource(QString path, QString name)
{
    target = path + name;
}

void CopyFile::startCopy()
{
    qDebug()<<"source---->"<<source<<"target---->"<<target;
    bool ret ;
    if(copyModel){
       ret  = this->copyFileFunction(source,target);
    }else {
       ret = this->copyFile(source,target);
    }

    if(!ret){qDebug()<<"Copy file has Error!";}
}


bool CopyFile::copyFileFunction(QString fromFIleName, QString toFileName)
{
    char* byteTemp = new char[4096];//字节数组
    qint64 fileSize = 0;
    qint64 totalCopySize = 0;
    QFile tofile;
    tofile.setFileName(toFileName);
    if(!tofile.open(QIODevice::WriteOnly)){
        return false;
    }
    QDataStream out(&tofile);
    out.setVersion(QDataStream::Qt_4_0);

    QFile fromfile;
    fromfile.setFileName(fromFIleName);
    if(!fromfile.open(QIODevice::ReadOnly)){
        return false;
    }
    fileSize = fromfile.size();
    QDataStream in(&fromfile);
    in.setVersion(QDataStream::Qt_4_0);
    while(!in.atEnd())
    {

        qint64 readSize = 0;
        //读入字节数组,返回读取的字节数量，如果小于4096，则到了文件尾
        readSize = in.readRawData(byteTemp, 4096);
        out.writeRawData(byteTemp, readSize);
        totalCopySize += readSize;
         int tmpVal = totalCopySize / (double)fileSize * 100;
         emit update_process(QString::number(tmpVal));
    }
    if(totalCopySize == fileSize){
        tofile.setPermissions(QFile::ExeUser);
        tofile.close();
        fromfile.close();
        return true;
    }
    else
        return false;
}

bool CopyFile::copyFile(QString from, QString to)
{
    return  QFile::copy(from, to);
}

void CopyFile::setTarget(QString file)
{
    target = file;
}

void CopyFile::setSource(QString file)
{
    source = file;
}

void CopyFile::setModel(bool hasProgress)
{
    copyModel = hasProgress;
}
