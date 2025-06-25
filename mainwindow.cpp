#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include "radonTransform.h"
#include <iostream>
#include <QAction>
#include <QScrollArea>
#include <QLabel>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QObject>
#include <QDebug>


#define MAX_BRIGHT 255

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImageToWindow(QImage &img, QString fileName, QMdiSubWindow* subWindow){
    if (ui->tabWidget->currentWidget() == ui->tabRotation){
        int centerX = img.width()/2;
        int centerY = img.height()/2;
        newWidth = 1.25*sqrt(pow(img.width(), 2) + pow(img.height(), 2));
        newHeight = newWidth;
        QImage* bufImage = new QImage(newWidth, newHeight, QImage::Format_ARGB32);
        for (int x = 0; x< newWidth; ++x){
            for (int y = 0; y< newHeight; ++y){
                bufImage->setPixel(x, y, 0);
            }
        }
        for (int x = newWidth/2 - centerX; x< newWidth/2 + centerX; ++x){
            for (int y = newHeight/2 - centerY; y< newHeight/2 + centerY; ++y){
                bufImage->setPixel(x, y, img.pixel(x - (newWidth/2 - centerX), y - (newHeight/2 - centerY)));
            }
        }
        QImage& ref = *bufImage;
        img = ref;
    }
    QScrollArea* scroll = new QScrollArea();
    //QLabel* labelPixmap = new QLabel();
    MyLabel* labelPixmap = new MyLabel(img);
    QPixmap qMap = QPixmap::fromImage(img);
    labelPixmap->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    labelPixmap->setPixmap(qMap);
    scroll->setWidget(labelPixmap);
    scroll->setMouseTracking(true);
    if (!qMap.isNull()){
        QWidget *widget = new QWidget();
        QGridLayout *gridLayout = new QGridLayout();
        gridLayout->addWidget(scroll);
        widget->setLayout(gridLayout);
        if (subWindow == 0){ //если необходимо создать новое окно
            QMdiSubWindow *subWindow1 = new QMdiSubWindow;
            subWindow1->setWidget(widget);
            subWindow1->setWindowTitle(fileName);
            ui->mdiArea->addSubWindow(subWindow1);
        } else { //если задано окно для визуализации изображения
            subWindow->setWidget(widget);
        }
        widget->show();
        QObject::connect(labelPixmap, SIGNAL(Mouse_Pressed()), this, SLOT(on_rotationPoint_chosen()));
    } else {
        QMessageBox::critical(this, "Ошибка","Не удалось открыть изображение!");
    }
}

void MainWindow::on_mOpen_triggered()
{
    QString initialPath = QFileInfo(QCoreApplication::applicationFilePath()).dir().path() + "/../../..";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выбор файла"), initialPath, tr("Images (*.bmp)"));
    if (fileName != ""){
        QImage img;
        bool wasRead = false;
        wasRead = img.load(fileName);
        if (!wasRead){
            QMessageBox::critical(this, "Ошибка","Файл не был открыт!");
        }
        setImageToWindow(img, fileName);
    }
}

void MainWindow::on_mClose_triggered()
{
    this->close();
}

bool MainWindow::isActivateWindow(){
    if (ui -> mdiArea -> activeSubWindow() == Q_NULLPTR){
        QMessageBox::critical(this, "Ошибка", "Выберите окно с изображением!");
        return false;
    } else {
        return true;
    }
}

void MainWindow::getImage(QImage &img, QMdiSubWindow* subWindow){
    if (subWindow == 0){
        subWindow = ui->mdiArea->activeSubWindow();
    }
    QWidget* widget = subWindow -> widget();
    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(widget -> layout());
    QScrollArea* scroll = qobject_cast<QScrollArea*>(gridLayout -> itemAtPosition(0, 0) -> widget());
    QWidget* obj = qobject_cast<QWidget*>(scroll -> widget());
    MyLabel* labelPixmap = qobject_cast<MyLabel*>(obj);
    img = labelPixmap -> getImage();
}

void MainWindow::on_mSave_triggered()
{
    QImage img;
    if (isActivateWindow()){
        getImage(img);
        QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить изображение"), QCoreApplication::applicationDirPath(), tr("Images (*.bmp)"));
        if (!img.save(fileName)){
            QMessageBox::critical(this, "Ошибка", "Изображение не было сохранено!");
        } else {
            QMessageBox::information(this, "Информация", "Изображение было сохранено");

        }
    }
}




void MainWindow::on_radon_clicked()
{
    QImage img;
    if (isActivateWindow()){
        QMdiSubWindow* window = ui->mdiArea->activeSubWindow();
        getImage(img, window);
        if (ui->radonNewImage->isChecked()){
            QImage newImg = img;
            radon(newImg);
            setImageToWindow(newImg, "Преобразование Радона");
        } else {
            radon(img);
            setImageToWindow(img, "", window);
        }
    }
}

void MainWindow::on_rotationPoint_chosen()
{
    if (ui->tabWidget->currentWidget() == ui->tabRotation){
        MyLabel *sender = (MyLabel*) QObject::sender();
        ui->pointCoordsLabel->setText(QString("%1, %2").arg(sender->x).arg(sender->y));
    }
}

void MainWindow::rotate(QImage& img)
{
    int degrees = ui->rotationDegreeInput->toPlainText().toInt();
    double rads = degrees * M_PI/180;
    QStringList coordinates = ui->pointCoordsLabel->text().split(',');
    int rotationCenterX = coordinates.at(0).toInt();
    int rotationCenterY = coordinates.at(1).toInt();


    int** rotatedImage = new int*[img.width()];
    for (int i = 0; i < img.width(); ++i){
        rotatedImage[i] = new int[img.height()]{0};
    }

    for (int x = 0; x < img.width(); x++)
    {
        for (int y = 0; y < img.height(); y++)
        {
            int oldX = (x - rotationCenterX)*cos(rads) - (y - rotationCenterY)*sin(rads) + rotationCenterX-5;
            int oldY = (x - rotationCenterX)*sin(rads) + (y - rotationCenterY)*cos(rads) + rotationCenterY-5;
            if (oldY < img.height()  and oldX < img.width()  and oldY>=0 and oldX>=0)
                {
                rotatedImage[x][y] = img.pixel(oldX, oldY);
                }
        }
    }
    for (int x = 0; x<img.width(); x++)
    {
        for (int y = 0; y<img.height(); y++)
        {
            img.setPixel(x, y, rotatedImage[x][y]);
        }
    }
    delete[] rotatedImage;
}


void MainWindow::on_rotateButton_clicked()
{
    QImage img;
    if (isActivateWindow()){
        QMdiSubWindow* window = ui->mdiArea->activeSubWindow();
        getImage(img, window);
        if (ui->rotateNewImage->isChecked()){
            QImage newImg = img;
            rotate(newImg);
            setImageToWindow(newImg, "Преобразование Радона");
        } else {
            rotate(img);
            setImageToWindow(img, "", window);
        }
    }
}
