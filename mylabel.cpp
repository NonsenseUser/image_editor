#include "mylabel.h"
#include <QMouseEvent>
#include <iostream>
#include <QRgb>
#include <cmath>
MyLabel::MyLabel(QImage &img, QWidget *parent) :
    QLabel(parent), image(img)
{

}

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
}

MyLabel::~MyLabel()
{
}

QImage MyLabel::getImage(){
    return image;
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    this->x = ev->position().x();
    this->y = ev->position().y();
    emit Mouse_Pressed();
}






