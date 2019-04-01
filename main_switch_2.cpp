#include <QApplication>
#include "switch_2.h"

int main(int argc,char**argv){
  QApplication application(argc,argv);

  QWidget container;
  container.setFixedSize(300,200);
  QVBoxLayout mainLayout;


SwitchButton* sbtn = new SwitchButton(); // Default style is Style::ONOFF

  mainLayout.addWidget(sbtn);

  container.setLayout(&mainLayout);
  container.show();

  return application.exec();
}

