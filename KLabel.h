#ifndef _H_LABEL_
#define _H_LABEL_

#include <QLabel>
#include <QFrame>

class KLabel:public QLabel{
  Q_OBJECT

  public:
    KLabel(QString text):QLabel(text){
    

//      setFrameStyle(QFrame::Panel | QFrame::Plain|QFrame::HLine );
    //  setFrameStyle(QFrame::Plain|QFrame::HLine );
      setFrameStyle(QFrame::Plain|QFrame::Box);

      setAlignment(Qt::AlignBottom | Qt::AlignRight);
    }


  private:

};

#endif
