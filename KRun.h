#ifndef _H_KRUN_
#define _H_KRUN_


#include <QWidget>
#include "KPushButton.h"
#include "KLabel.h"

//temp
#include <QVBoxLayout>
#include <QHBoxLayout>

class KRun : public QWidget{
 // Q_OBJECT
  private:
  QVBoxLayout *layout;

  KWidget *widget_upper;
  QHBoxLayout *layout_upper;
  KPushButton * btn_run;
  KLabel *label_stat;

  KWidget *widget_lower;
  QVBoxLayout *layout_lower;
  KLabel *label_lower;

  public:
  KRun():QWidget(){

    layout = new QVBoxLayout;

    widget_upper = new KWidget();
    layout_upper = new QHBoxLayout;

    btn_run = new KPushButton("KRun btn",100,100);
    label_stat = new KLabel("KRun label",200,100);

    layout_upper->addWidget(btn_run);
    layout_upper->addWidget(label_stat);
    widget_upper->setLayout(layout_upper);
    layout->addWidget(widget_upper);

    widget_lower = new KWidget();
    layout_lower = new QVBoxLayout();

    label_lower = new KLabel("Unsigned");

    layout_lower->addWidget(label_lower);
    widget_lower->setLayout(layout_lower);

    layout->addWidget(widget_lower);

    setLayout(layout);
  }

  ~KRun(){
    delete btn_run;
    delete label_stat;
    delete label_lower;
    delete layout;
    delete layout_upper;

    delete widget_lower;
    delete widget_upper;
  }


};

#endif
