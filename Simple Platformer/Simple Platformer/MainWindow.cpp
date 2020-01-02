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

void MainWindow::Render(SDL::Renderer renderer)
{
	for (auto& element : elements_)
	{
		renderer.Render(element);
	}
}

void MainWindow::SetGravity(double g)
{
}

void MainWindow::AddObject(Object& o)
{
	elements_.emplace_back(o);
}

void MainWindow::Update(std::chrono::milliseconds delta)
{
	for (auto& element : elements_)
	{
		element.Update(delta);

		if (!element.Solid)
		{
			//Handle Gravity
		}
	}
}

void MainWindow::Render()
{
	Render(renderer_);
}
