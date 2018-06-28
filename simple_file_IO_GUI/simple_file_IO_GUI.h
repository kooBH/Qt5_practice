#pragma once


#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QApplication>
#include <QMenuBar>
#include <QFileDialog>
#include <Qfile>

using std::string;

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class simple_file_IO_GUI : public QMainWindow
{
	Q_OBJECT

public:
	simple_file_IO_GUI(QWidget *parent = Q_NULLPTR);


private:

	private slots:

	void open();
	void save();

private:
	void createActions();
	void createMenus();

	QMenu *fileMenu;
	QActionGroup *alignmentGroup;
	QAction *openAct;
	QAction *saveAct;
	QAction *exitAct;

	QLabel *infoLabel;

	QFile *f=nullptr;

	/*************************************************************/

	void log(QString);
	void openFile();
	
};
