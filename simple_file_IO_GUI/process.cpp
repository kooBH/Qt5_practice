#include "process.h"

void fileProcess(string filename)
{
	std::ofstream f;
	f.open(filename);

	f << "hello world";

	f.close();

}