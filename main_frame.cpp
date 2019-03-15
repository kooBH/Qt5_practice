#include "App.h"
#include "KLabel.h"
#include "KPushButton.h"
#include "KWidget.h"
#include "switch.h"


#include <QVBoxLayout>
#include "BorderLayout.h"

#include <stdio.h>
#include <string>

#include <vector>


using namespace std;

int main(int argc, char **argv)
{

  int i,j;

  App application(argc,argv);

  KWidget container;
  BorderLayout mainLayout;

  KWidget side;
  QVBoxLayout buttonLayout;
  side.setLayout(&buttonLayout);


  KLabel *label = new KLabel("label");
  Switch *sw = new Switch("swtich");

  vector<KPushButton*> buttons;

  for(i=0;i<5;i++){
    KPushButton *button = new KPushButton("button");
    buttons.push_back(button);
    buttonLayout.addWidget(button,BorderLayout::West);
  }
  
  
  //label->setText("first line\nsecond line");
 
  mainLayout.addWidget(&side,BorderLayout::West);
  mainLayout.addWidget(label,BorderLayout::Center);
  mainLayout.addWidget(sw,BorderLayout::Center);

  container.setLayout(&mainLayout);


  container.show();
  return application.exec();
}


