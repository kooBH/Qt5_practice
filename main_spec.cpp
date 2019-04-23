
#include <QVBoxLayout>
#include "KLabel.h"
#include "KWidget.h"
#include "KSpectrogram.h"
#include <QApplication>
int main(int argc, char **argv)
{

  QApplication application(argc,argv);

  KWidget container;
  QVBoxLayout mainLayout;
  container.setLayout(&mainLayout);

  container.setBaseSize(2500,900);
  KSpectrogram spec("../input");
  KSpectrogram spec3("../ref");
  KSpectrogram spec2("../output");
  mainLayout.addWidget(&spec);
  mainLayout.addWidget(&spec3);
  mainLayout.addWidget(&spec2);

  container.show();
  return application.exec();
}


