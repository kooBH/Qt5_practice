#ifndef _H_KGL_
#define _H_KGL_

#include <QPainter>
#include <QTimer>
#include <QOpenGLWidget>


#include <QWidget>


#include "wobjectdefs.h"

class Helper
{
public:
    Helper();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    QPixmap backgroundPixmap;
};

class GLWidget : public QOpenGLWidget
{
    //Q_OBJECT
    W_OBJECT(GLWidget)
public:
    GLWidget(QWidget *parent=nullptr);

public slots:
    void animate();
    W_SLOT(animate)
protected:
    void paintEvent(QPaintEvent *event) override;

private:

    Helper helper;
    int elapsed;
};

class Window : public QWidget
{
    //Q_OBJECT
    W_OBJECT(Window)
public:
    Window();

private:
};


#endif
