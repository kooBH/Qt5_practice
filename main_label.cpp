#include "App.h"
#include "KLabel.h"
#include "KWidget.h"

#include <QVBoxLayout>

#include <stdio.h>
#include <string>



int main(int argc, char **argv)
{

  App application(argc,argv);

  KWidget container;
  QVBoxLayout mainLayout;
  container.setLayout(&mainLayout);

KLabel *label = new KLabel("label");
//label->setText("first line\nsecond line");

  mainLayout.addWidget(label);

  container.show();
  return application.exec();
}


