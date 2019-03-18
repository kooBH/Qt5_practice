#include "QApplication"
#include "QWidget"
#include "QVBoxLayout"
#include "KComboBox.h"

#include <iostream>

#include "QtGlobal"

using namespace std;

int main(int argc,char**argv){
QApplication application(argc,argv);

  QWidget container;
  container.setFixedSize(300,200);
  QVBoxLayout mainLayout;


  KComboBox box;
  box.addItem("one");
  box.addItem("two");

  mainLayout.addWidget(&box);

    container.setLayout(&mainLayout);
  container.show();
  return application.exec();
}

