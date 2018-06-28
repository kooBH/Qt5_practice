#include "simple_file_IO_GUI.h"


#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	simple_file_IO_GUI w;
	w.setFixedSize(500, 400);
	w.show();
	return a.exec();
}
