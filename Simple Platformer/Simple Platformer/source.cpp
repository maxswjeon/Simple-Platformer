#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <chrono>

#include "Map.h"
#include "MainWindow.h"
#include "EventPool.h"

using namespace std::chrono;

int main(int argc, char* argv[])
{
	Map map = Map::Loader::Load("data/testMap.t");

	MainWindow window_main = MainWindow("Simple Platformer", 
		map,
		1024, 768,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);

	EventPool& event_pool = EventPool::GetInstance();

	SDL_Event e;
	auto last_render = system_clock::now();

	bool quit = false;
	while (!quit)
	{
		window_main.Update(duration_cast<milliseconds>(system_clock::now() - last_render));
		window_main.Render();
		while (SDL_PollEvent(&e))
		{
			event_pool.HandleEvent(e);
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		last_render = std::chrono::system_clock::now();
	}
	
	SDL_Quit();
	return 0;
}
