#include "MainWindow.h"

MainWindow::MainWindow(const char* title,
	Map map,
	int width, int height,
	int x, int y,
	Uint32 wflags,
	int index,
	Uint32 rflags) : Window(title, x, y, width, height, wflags, index, rflags) , map_(map)
{

}
