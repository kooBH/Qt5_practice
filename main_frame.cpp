#include "App.h"
#include "KLabel.h"
#include "KPushButton.h"
#include "KWidget.h"
#include "switch.h"


#include <QVBoxLayout>
#include "BorderLayout.h"

#include <stdio.h>
#include <string>



int main(int argc, char **argv)
{

  App application(argc,argv);

  KWidget container;
  BorderLayout mainLayout;

  KLabel *label = new KLabel("label");
  KPushButton *button = new KPushButton("button");
  Switch *sw = new Switch("swtich");
  
  
  //label->setText("first line\nsecond line");

  mainLayout.addWidget(label,BorderLayout::Center);
  mainLayout.addWidget(button,BorderLayout::West);
  mainLayout.addWidget(sw,BorderLayout::Center);

  container.setLayout(&mainLayout);


  container.show();
  return application.exec();
}


