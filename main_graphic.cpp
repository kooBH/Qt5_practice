#include <QApplication>
#include "KWidget.h"

#include <QVBoxLayout>

#include <stdio.h>
#include <string>

#include <QSurfaceFormat>
#include "KGl.h"


int main(int argc, char **argv)
{

  QCoreApplication::addLibraryPath("../lib");

  QApplication application(argc,argv);

  KWidget container;
/*
  QSurfaceFormat fmt;
  fmt.setSamples(4);
  QSurfaceFormat::setDefaultFormat(fmt);
  */

  GLWidget *openGL1 = new GLWidget();
  QGridLayout *layout = new QGridLayout;

  layout->addWidget(openGL1, 0, 0);

  QTimer *timer = new QTimer(&container);
  QWidget::connect(timer, &QTimer::timeout, openGL1, &GLWidget::animate);
  timer->start(50);

  container.setLayout(layout);
  container.show();

  return application.exec();
}


