#include "header.h" 

namespace Ui {
    class MainWindow;
 }

 class MainWindow : public QMainWindow
 {
   //Q_OBJECT 매크로 선언은 헤더에 해줘야 moc이 알아서 잡아준다
    Q_OBJECT
 public:
    explicit MainWindow(QWidget *parent = 0): QMainWindow(parent)

    {
     // Create the button, make "this" the parent
    button_inc = new QPushButton("0", this);
    num=0;
    button_exit = new QPushButton("Exit", this);
    // set size and location of the button
    button_inc->setGeometry(QRect(QPoint(0, 100),QSize(50, 50)));
    button_exit->setGeometry(QRect(QPoint(100, 100),QSize(20, 20)));
 
    // Connect button signal to appropriate slot
    connect(button_inc, SIGNAL (released()), this, SLOT (handle_inc()));
    connect(button_exit, SIGNAL (released()), this, SLOT (handle_exit()));
 
    }
 private slots:
    void handle_inc(){
    // change the text
    num++;
    button_inc->setText((std::to_string(num)).c_str() );
    // resize button
    button_inc->resize(50+num*5,50+num*5);
    }

    void handle_exit(){

      exit(-1);
    }
 private:
    int num;
    QPushButton *button_inc;
    QPushButton *button_exit;

 };
 


