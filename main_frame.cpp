#include "App.h"
#include "KLabel.h"
#include "KPushButton.h"
#include "KWidget.h"
#include "switch.h"


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
  KPushButton *button = new KPushButton("button");
  Switch *sw = new Switch("swtich");
  
  
  //label->setText("first line\nsecond line");

  mainLayout.addWidget(label);
  mainLayout.addWidget(button);
  mainLayout.addWidget(sw);


  container.show();
  return application.exec();
}


