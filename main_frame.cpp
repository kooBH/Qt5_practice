#include "App.h"
#include "KLabel.h"
#include "KPushButton.h"
#include "KWidget.h"
#include "switch.h"


#include <QVBoxLayout>
#include <QBoxLayout>
#include "BorderLayout.h"

#include <stdio.h>
#include <string>

#include <vector>


using namespace std;

int main(int argc, char **argv)
{

  int i,j;

  App application(argc,argv);

  //Main
  KWidget *mainW = new KWidget();
  BorderLayout *mainL = new BorderLayout();
  mainW->setFixedSize(600,400);

  //Side menu
  KWidget *sideW = new KWidget();
  QVBoxLayout *sideL = new QVBoxLayout();
  vector<KPushButton*> buttons;

  for(i=0;i<5;i++){
    KPushButton *button = new KPushButton("B");
    button->setFixedSize(80,80);
    buttons.push_back(button);
    sideL->addWidget(button,BorderLayout::West);
  }

  //Label widget
  KWidget *labelW = new KWidget();
  QBoxLayout *labelL = new QBoxLayout(QBoxLayout::TopToBottom);
  KLabel *label = new KLabel("label");

  labelW->setStyleSheet("background-color:black;");
  

  //switch widget
  KWidget *switchW = new KWidget();
  QBoxLayout *switchL = new QBoxLayout(QBoxLayout::TopToBottom);
  Switch *sw = new Switch("swtich");

  //display layout
  //포인터로 하지 않으면 이중 할당 에러가나 난다
  //전부다 포인터를 써서 관리를 해야하나..
  QWidget *displayW = new QWidget();
  QBoxLayout *displayL = new QBoxLayout(QBoxLayout::TopToBottom);

  //Dumping Widget
  QWidget *binW = new QWidget();
  QBoxLayout *binL = new QBoxLayout(QBoxLayout::TopToBottom);
  binW->setLayout(binL);
  
  
  //버튼 조작
  
  QObject::connect(buttons[0],&KPushButton::clicked,
      [&](){
      //switchW.hide();
      labelW->hide();
      binL->addWidget(labelW);
      //mainL.replaceWidget(&switchW,&labelW);
      
      //mainL.removeWidget(&labelW);
      //mainL.addWidget(&switchW,BorderLayout::Center);
      displayL->replaceWidget(labelW,switchW);
      switchW->show();
      
      }
      );
  
 
  //레이아웃 넣기
//  mainL.addWidget(&labelW,BorderLayout::Center);
 // mainL.setSizeConstraint(QLayout::SetFixedSize);
 

 
 
  //레이아웃 합치기 Down To Top
  labelL->addWidget(label);
  labelW->setLayout(labelL);

  switchL->addWidget(sw);
  switchW->setLayout(switchL);

  displayL->addWidget(labelW);
  displayW->setLayout(displayL);

  mainL->addWidget(displayW,BorderLayout::Center);
  mainL->addWidget(sideW,BorderLayout::West);
  mainW->setLayout(mainL);
  sideW->setLayout(sideL);


  mainW->show();

  return application.exec();
}


