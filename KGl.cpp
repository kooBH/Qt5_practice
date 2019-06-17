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
}
//! [0]

//! [1]
void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()/50) % 1000;
    std::cout << elapsed << std::endl;
    update();
}
//! [1]

//! [2]
void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper.paint(&painter, event, elapsed);
    painter.end();
}


/********** Helper ************/

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Helper::Helper()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(Qt::black);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}
//! [0]

//! [1]
void Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
    //painter->fillRect(event->rect(), background);
    painter->drawPixmap(0,0,1000,200,backgroundPixmap);  
    //painter->translate(100, 100);
//! [1]

//! [2]
    painter->save();
    painter->setOpacity(0.5);
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);
    painter->drawRect(0,0,elapsed,200);

    /*
    painter->rotate(elapsed * 0.030);

    qreal r = elapsed / 1000.0;
    int n = 30;
    for (int i = 0; i < n; ++i) {
        painter->rotate(30);
        qreal factor = (i + r) / n;
        qreal radius = 0 + 120.0 * factor;
        qreal circleRadius = 1 + factor * 20;
        painter->drawEllipse(QRectF(radius, -circleRadius,
                                    circleRadius * 2, circleRadius * 2));
    }
    */
    painter->restore();
//! [2]

//! [3]
    painter->setPen(textPen);
    painter->setFont(textFont);
    painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));
}

/****************** Window *****************/
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
//! [0]
W_OBJECT_IMPL(Window)
Window::Window()
{
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    GLWidget *openGL1 = new GLWidget(this);
   

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, openGL1, &GLWidget::animate);
    timer->start(50);
}
