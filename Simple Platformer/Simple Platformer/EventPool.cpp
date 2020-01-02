#include "EventPool.h"

EventPool& EventPool::GetInstance()
{
	static EventPool _instance;
	return _instance;
}

void EventPool::AddWindowHandler(std::function<void(SDL_Event)> listener, unsigned int id)
{
	if (_window_handlers.count(id))
	{
		return;
	}
	_window_handlers.emplace(id, listener);
}

void EventPool::AddHandler(std::function<void(SDL_Event)> listener, unsigned int type)
{
	if (_handlers.count(type))
	{
		return;
	}
	_handlers.emplace(type, listener);
}

void EventPool::HandleEvent(SDL_Event event)
{
	if (event.type == SDL_WINDOWEVENT)
	{
		if (!_window_handlers.count(event.window.windowID))
		{
			return;
		}
		_window_handlers[event.window.windowID](event);
	}
	else
	{
		if (!_handlers.count(event.type))
		{
			return;
		}
		_handlers[event.type](event);
	}
}

void EventPool::RemoveWindowHandler(unsigned int id)
{
	if (!_window_handlers.count(id))
	{
		return;
	}
	_window_handlers.erase(id);
}

