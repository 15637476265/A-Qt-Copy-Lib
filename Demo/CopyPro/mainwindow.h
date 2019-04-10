#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CopyHelper.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    void checkCanRun();

private slots:
    void update_Progress(QString);

private slots:
    void on_run_clicked();

    void on_source_Tool_clicked();

    void on_target_Tool_clicked();

    void on_targetEdit_editingFinished();

    void on_targetEdit_filename_textChanged(const QString &arg1);

    void on_targetEdit_textChanged(const QString &arg1);

    void on_sourceEdit_textChanged(const QString &arg1);

    void on_target_Tool_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    CopyHelper *copy;
    bool canRun;
    QString format;
};

#endif // MAINWINDOW_H
