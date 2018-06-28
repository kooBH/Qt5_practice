/********************************************************************************
** Form generated from reading UI file 'simple_file_IO_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLE_FILE_IO_GUI_H
#define UI_SIMPLE_FILE_IO_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simple_file_IO_GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *simple_file_IO_GUIClass)
    {
        if (simple_file_IO_GUIClass->objectName().isEmpty())
            simple_file_IO_GUIClass->setObjectName(QStringLiteral("simple_file_IO_GUIClass"));
        simple_file_IO_GUIClass->resize(600, 400);
        menuBar = new QMenuBar(simple_file_IO_GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        simple_file_IO_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(simple_file_IO_GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        simple_file_IO_GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(simple_file_IO_GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        simple_file_IO_GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(simple_file_IO_GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        simple_file_IO_GUIClass->setStatusBar(statusBar);

        retranslateUi(simple_file_IO_GUIClass);

        QMetaObject::connectSlotsByName(simple_file_IO_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *simple_file_IO_GUIClass)
    {
        simple_file_IO_GUIClass->setWindowTitle(QApplication::translate("simple_file_IO_GUIClass", "simple_file_IO_GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simple_file_IO_GUIClass: public Ui_simple_file_IO_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_FILE_IO_GUI_H
