#ifndef _H_KCOMBOBOX
#define _H_KCOMBOBOX

#include <QObject>

#include <QWidget>
#include <QComboBox>

#include <iostream>

using namespace std;

class KComboBox : public QComboBox {

  //Q_OBJECT
  public:
   KComboBox(QWidget*parent=nullptr):QComboBox(parent){
   
   QObject::connect(this,&KComboBox::currentTextChanged,
       [&](const QString &text){
          cout<<text.toStdString()<<endl;
         
       }
         
   );
 }

   ~KComboBox(){};


  private:

};

#endif
