#pragma once
#include <string>
#include <SDL.h.>

using namespace std;

class window
{
public:
	window(const string, int width, int height);
	~window();
	void pollEvents();
	void clear() const;
	inline bool isClosed() const {return close;}

private:
	bool init();

private:
	string title;
	int width = 800;
	int height = 600;

	bool close = false;
	SDL_Window *_window = nullptr;
	SDL_Renderer *_renderer = nullptr;
};