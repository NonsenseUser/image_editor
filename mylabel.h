#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QImage>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QImage &img, QWidget *parent = 0);
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();
    QImage getImage();
    QImage image;
    void mousePressEvent(QMouseEvent *ev);
    int x,y;

private slots:

signals:
    void Mouse_Pressed();
private:

};

#endif // MYLABEL_H
