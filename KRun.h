#ifndef _H_KRUN_
#define _H_KRUN_


#include <QWidget>
#include "KPushButton.h"

//temp
#include <QVBoxLayout>

class KRun : public QWidget{
  Q_OBJECT
  private:
  KPushButton * b1;
  KLabel *l1;

  QVBoxLayout *layout;

  public:
  KRun():QWidget(){

    layout = new QVBoxLayout;
    b1 = new KPushButton("KRun btn");
    l1 = new KLabel("KRun label");
    layout->addWidget(b1);
    layout->addWidget(l1);
    setLayout(layout);

  
  }

  ~KRun(){}


};

#endif
