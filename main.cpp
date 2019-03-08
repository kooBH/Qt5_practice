#include "switch.h"
#include "window.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  /*
    QApplication app(argc, argv);
     MainWindow mainWindow;
//     mainWindow.showMaximized();
  mainWindow.setFixedSize(300,300);

    QWidget container;
    QVBoxLayout mainLayout;
    mainWindow.setLayout(&mainLayout);

  Switch* sw1 = new Switch("switch");
  mainLayout.addWidget(sw1);

  mainWindow.show();

     return app.exec();
     */
    QApplication application(argc, argv);
    QWidget container;
    QVBoxLayout mainLayout;
    container.setLayout(&mainLayout);

    Switch* switch1 = new Switch("SWITCH");
    mainLayout.addWidget(switch1);
    Switch* switch2 = new Switch("SWITCH");
    mainLayout.addWidget(switch2);
    switch2->setDisabled(true);
    Switch* switch3 = new Switch("SWITCH");
    mainLayout.addWidget(switch3);
    switch3->setLayoutDirection(Qt::RightToLeft);
    Switch* switch4 = new Switch("SWITCH");
    mainLayout.addWidget(switch4);
    switch4->setLayoutDirection(Qt::RightToLeft);
    switch4->setChecked(true);
    switch4->setDisabled(true);

    QButtonGroup bg;
    Switch* item1 = new Switch("ITEM1");
    Switch* item2 = new Switch("ITEM2");
    bg.addButton(item1);
    bg.addButton(item2);
    mainLayout.addWidget(item1);
    mainLayout.addWidget(item2);
    mainLayout.setMargin(100);

    container.show();
    printf("EXEC APP\n");
    return application.exec();
}


