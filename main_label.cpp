#include <QApplication>
#include "KLabel.h"
#include "KWidget.h"

#include <QVBoxLayout>

#include <stdio.h>
#include <string>

#include <QTextCodec>
#include <QFont>


int main(int argc, char **argv)
{

  QApplication application(argc,argv);

  KWidget container;
  QVBoxLayout mainLayout;
  container.setLayout(&mainLayout);

  container.setFixedSize(500,500);

   QTextCodec *codec = QTextCodec::codecForName("UTF-8");
   QFont font;
   font.setFamily(codec->toUnicode("맑은 고딕"));
   font.setPointSize(24);


KLabel *label = new KLabel("맑은 고딕");
//label->setText("first line\nsecond line");
//
  label->setFont(font);

  mainLayout.addWidget(label);

  container.show();
  return application.exec();
}


