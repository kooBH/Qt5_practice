#ifndef _H_KAPP_
#define _H_KAPP_
#include <QApplication>

#include "KLabel.h"
#include "KPushButton.h"
#include "KWidget.h"


#include <QVBoxLayout>
#include <QBoxLayout>
#include "BorderLayout.h"

#include "KRun.h"

#include <stdio.h>
#include <string>

#include <vector>

using namespace std;

class KApplication :public QApplication{

  private:

 int state; 
 KWidget *mainW;
 BorderLayout *mainL; 

  KWidget *sideW ;
  QVBoxLayout *sideL;
  vector<KPushButton*> buttons;

  //switch widget
  KWidget *switchW ;
  QBoxLayout *switchL;
  //Switch *sw ;

  //display layout
  //포인터로 하지 않으면 이중 할당 에러가나 난다
  //전부다 포인터를 써서 관리를 해야하나..
  QWidget *displayW;
  QBoxLayout *displayL;

  //Dumping Widget
  QWidget *binW;
  QBoxLayout *binL;

  //RunWidget
  KRun * RunW;
  
  
  public:
KApplication( int & argc ,char** argv ):QApplication( argc ,argv ){
  int i,j;
  state = 0;

  printf("App init\n");
  //Main
  mainW = new KWidget();
  mainL = new BorderLayout();
  mainW->setFixedSize(600,400);

  //Side menu
  sideW = new KWidget();
  sideL = new QVBoxLayout();
  vector<KPushButton*> buttons;

  for(i=0;i<5;i++){
    KPushButton *button = new KPushButton("B");
    button->setFixedSize(80,80);
    buttons.push_back(button);
    sideL->addWidget(button,BorderLayout::West);
  }

  //switch widget
  switchW = new KWidget();
  switchL = new QBoxLayout(QBoxLayout::TopToBottom);
  //sw = new Switch("swtich");

  //display layout
  //포인터로 하지 않으면 이중 할당 에러가나 난다
  //전부다 포인터를 써서 관리를 해야하나..
  displayW = new QWidget();
  displayL = new QBoxLayout(QBoxLayout::TopToBottom);

  //Dumping Widget
  binW = new QWidget();
  binL = new QBoxLayout(QBoxLayout::TopToBottom);
  binW->setLayout(binL);

  //run widget
  RunW = new KRun();
  
  
  //버튼 조작
  QObject::connect(buttons[0],&KPushButton::clicked,
      [&](){
     // switchW.hide();

      if(state){
        displayL->removeWidget(RunW);
        RunW->hide();
       
		displayL->insertWidget(0,switchW);
        switchW->show();
        state=0;
      }
      else{
        displayL->removeWidget(switchW);
        switchW->hide();
        displayL->insertWidget(0,RunW);
        RunW->show();
        state=1;
      }
      //mainL->addWidget(switchW,BorderLayout::Center);
      //mainW->update();
    // displayL->update();
     // switchW->show();
      
      }
      );
  
 
  //레이아웃 넣기
 // mainL.setSizeConstraint(QLayout::SetFixedSize);
 

 
 
  //레이아웃 합치기 Down To Top

  //switchL->addWidget(sw);
  switchW->setLayout(switchL);

  displayL->addWidget(RunW);
  displayW->setLayout(displayL);

  mainL->addWidget(displayW,BorderLayout::Center);
  mainL->addWidget(sideW,BorderLayout::West);
  mainW->setLayout(mainL);
  sideW->setLayout(sideL);


  mainW->show();

}

~KApplication(){
  printf("App finish\n");
}


};



#endif
