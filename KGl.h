#ifndef _H_KGL_
#define _H_KGL_

#include <QPainter>
#include <QTimer>
#include <QOpenGLWidget>

#include <QPaintEvent>

#include <QWidget>


#include "wobjectdefs.h"
class GLWidget : public QOpenGLWidget
{
    //Q_OBJECT
    W_OBJECT(GLWidget)
public:
    GLWidget(QWidget *parent=nullptr);
    ~GLWidget();

public slots:
    void animate();
    W_SLOT(animate)
protected:
    void paintEvent(QPaintEvent *event) override;

private:

    QBrush background;
    QBrush circleBrush;
    QPen circlePen;
    QPixmap backgroundPixmap;


    QPainter painter;

    int elapsed;
};
#endif
