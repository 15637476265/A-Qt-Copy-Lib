#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    copy = new CopyHelper();
    QObject::connect(copy,SIGNAL(update_pro(QString)),this,SLOT(update_Progress(QString)));
    canRun = true;
    format = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkCanRun()
{
    if(!ui->targetEdit_filename->text().isEmpty() && !ui->targetEdit->text().isEmpty() &&
            !ui->sourceEdit->text().isEmpty()){
        canRun = true;
    }else {
        canRun = false;
    }
    ui->run->setEnabled(canRun);
}

void MainWindow::update_Progress(QString data)
{
    ui->progressBar->setValue(data.toInt());
}

void MainWindow::on_run_clicked()
{
    copy->setModel(true);
    copy->startCopy();
}

void MainWindow::on_source_Tool_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Source"), "my.format", tr("All Files (*.*)"));
    if(!fileName.isEmpty())
        ui->sourceEdit->setText(fileName);
}

void MainWindow::on_target_Tool_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty())
        ui->targetEdit->setText(dir);
}


void MainWindow::on_targetEdit_editingFinished()
{
    if(     (!ui->targetEdit_filename->text().isEmpty()) &&
            (!ui->targetEdit->text().isEmpty()         )  ){
        copy->setTarget(ui->targetEdit->text() + "/" + ui->targetEdit->text());
    }
    checkCanRun();
}



void MainWindow::on_targetEdit_filename_textChanged(const QString &arg1)
{
    if(     (!arg1.isEmpty()) &&   (!ui->targetEdit->text().isEmpty()         )  ){
        copy->setTarget( ui->targetEdit->text() + "/." + arg1 );
    }
    checkCanRun();
}

void MainWindow::on_targetEdit_textChanged(const QString &arg1)
{
    if(     (!ui->targetEdit_filename->text().isEmpty()) &&
            (!arg1.isEmpty()         )  ){
        copy->setTarget(arg1 + "/" + ui->targetEdit->text());
    }
    checkCanRun();
}

void MainWindow::on_sourceEdit_textChanged(const QString &arg1)
{
    copy->setSource(arg1);
}

void MainWindow::on_target_Tool_2_clicked()
{
    ui->targetEdit_filename->setText(QString::number(QRandomGenerator::global()->generate()) + format);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    format = arg1;
}
