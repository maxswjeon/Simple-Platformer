#pragma once

#include <map>
#include <functional>
#include <chrono>

#include <SDL.h>

/*
 * Since SDL uses a single event pool, (and almost Windows Program Does)
 * this event pool is implemented as Singleton.
 * This EventPool Class is for Multi-Window Program, which requires the
 * adequate events to be sent to each window by its window id.
 */

class EventPool
{
	std::map<unsigned int, std::function<void(SDL_Event)>> _window_handlers;
	std::map<unsigned int, std::function<void(SDL_Event)>> _handlers;

	EventPool() = default;

public:
	static EventPool& GetInstance();

	void AddWindowHandler(std::function<void(SDL_Event)>, unsigned int);
	void AddHandler(std::function<void(SDL_Event)>, unsigned int);
	void RemoveWindowHandler(unsigned int);
	void HandleEvent(SDL_Event);

	EventPool(const EventPool& other) = delete;
	EventPool(EventPool&& other) noexcept = delete;
	EventPool& operator=(const EventPool& other) = delete;
	EventPool& operator=(EventPool&& other) noexcept = delete;
};

