#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setImageToWindow(QImage &img, QString fileName, QMdiSubWindow* subWindow = 0);

private slots:
    void on_mOpen_triggered();

    void on_mClose_triggered();

    void on_mSave_triggered();

    void on_radon_clicked();

    void on_rotationPoint_chosen();

    void on_rotateButton_clicked();

private:
    Ui::MainWindow *ui;
    void getImage(QImage &img, QMdiSubWindow* subWindow = 0);
    bool isActivateWindow();
    void rotate(QImage&);
    int newWidth = 2000;
    int newHeight = 2000;
};

#endif // MAINWINDOW_H
