#include "KGl.h"
#include <iostream>


#include "wobjectimpl.h"

W_OBJECT_IMPL(GLWidget)

//! [0]
GLWidget::GLWidget( QWidget *parent )
    : QOpenGLWidget(parent)
{
    elapsed = 0;
    setFixedSize(1000, 50);
    setAutoFillBackground(true);

    /* Helper */

    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(Qt::black);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);

}
GLWidget::~GLWidget(){
}
//! [0]

//! [1]
void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()/50) % 1000;
//    std::cout << elapsed << std::endl;
    update();
}
//! [1]

//! [2]
void GLWidget::paintEvent(QPaintEvent *event)
{

    painter.begin(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setOpacity(0.5);
    painter.setBrush(circleBrush);
    painter.setPen(circlePen);

//    QPainter painter;
  //  painter.begin(this);
  //  painter.setRenderHint(QPainter::Antialiasing);
    //helper.paint(&painter, event, elapsed);
    painter.drawPixmap(0,0,1000,200,backgroundPixmap);  
  //  painter.save();
    painter.drawRect(0,0,elapsed,200);

//    painter.restore();
//
    painter.end();

}




