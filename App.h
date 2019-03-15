#ifndef _H_APP_
#define _H_APP_

#include <QApplication>
#include <stdio.h>

class App :public QApplication{

  Q_OBJECT

  private:

  public:
  App( int & argc ,char** argv );
  ~App();
};


App::App( int & argc ,char** argv ):QApplication(  argc ,argv ){
  printf("App init\n");
}

App::~App(){
  printf("App finish\n");
}


#endif
