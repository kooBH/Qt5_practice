#include "switch.h"
#include "window.h"
#include "Funcs.h"
#include "App.h"
#include <stdio.h>
#include <functional>


int main(int argc, char **argv)
{

  App application(argc,argv);
  Funcs fcs;

  QWidget container;
  QVBoxLayout mainLayout;
  container.setLayout(&mainLayout);
/*
  Switch* switch1 = new Switch("SWITCH");
  mainLayout.addWidget(switch1);
  Switch* switch2 = new Switch("SWITCH");
  mainLayout.addWidget(switch2);
  switch2->setDisabled(true);
  Switch* switch3 = new Switch("SWITCH");
  mainLayout.addWidget(switch3);
  switch3->setLayoutDirection(Qt::RightToLeft);
  Switch* switch4 = new Switch("SWITCH");
  mainLayout.addWidget(switch4);
  switch4->setLayoutDirection(Qt::RightToLeft);
  switch4->setChecked(true);
  switch4->setDisabled(true);

  QButtonGroup bg;
  Switch* item1 = new Switch("ITEM1");
  Switch* item2 = new Switch("ITEM2");
  bg.addButton(item1);
  bg.addButton(item2);
  mainLayout.addWidget(item1);
  mainLayout.addWidget(item2);
  mainLayout.setMargin(100);
  */

 std::function<void(int)>lambda  = [=](int a) {printf("hello %d\n",a);};

  QPushButton *button = new QPushButton("&Download");
//  QObject::connect(button,&QPushButton::clicked,&Funcs::F1);
//
  /*
  QObject::connect(button, &QPushButton::clicked, [=]() {
       button->setText("Hi");
       });
   */
  int b = 7; 
// 안됨
//  QObject::connect(button, &QPushButton::clicked, lambda(b));
 
//  됨
  QObject::connect(button, &QPushButton::clicked, [b](){printf("%d\n",b);});


  mainLayout.addWidget(button);

  container.show();
  printf("EXEC APP\n");
  return application.exec();
}


