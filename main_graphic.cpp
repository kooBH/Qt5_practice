#include <QApplication>
#include "KWidget.h"

#include <QGridLayout>

#include <stdio.h>
#include <string>

#include <QSurfaceFormat>
#include "KGl.h"

#include <QLabel>
#include <QTimer>



int main(int argc, char **argv)
{

  const int num = 10;

  QCoreApplication::addLibraryPath("../lib");

  QApplication application(argc,argv);

  KWidget container;

/* 
  웬만해서는 default 옵션을 사용하자.  
  QSurfaceFormat fmt;
  fmt.setSamples(4);
  QSurfaceFormat::setDefaultFormat(fmt);
  */

  GLWidget** list_gl = new GLWidget*[num];
  QGridLayout *layout = new QGridLayout;

  for(int i=0;i<num;i++){
    list_gl[i] = new GLWidget();
    layout->addWidget(list_gl[i], i, 0);
  }

  QTimer *timer = new QTimer(&container);
  for(int i=0;i<num;i++){
    QWidget::connect(timer, &QTimer::timeout, list_gl[i], &GLWidget::animate);
  }
  timer->start(50);

  container.setLayout(layout);
  container.show();

  return application.exec();
}


