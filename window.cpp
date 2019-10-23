#include "window.h"
#include <iostream>

window::window(const string, int width, int height): title(title), width(width), height(height)
{
	close = !init();
}

window::~window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL Failed to initialize" << endl;
		return 0;
	}
	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

	if (_window == nullptr)
	{
		std::cerr << "Failed to create window.\n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr)
	{
		std::cerr << "Failed to create renderer :(\n";
		return 0;
	}

	return true;
}

void window::pollEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			close = true;
			break;
		case SDL_MOUSEBUTTONUP:
			std::cout << "You clicked your mouse!\n";
			break;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << "," << event.motion.y << endl;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_p:
			{
				cout << "WE preseed\n";
				break;
			}
			case SDLK_LEFT:
				std::cout << "You pressed the left arrow!" << endl;
				break;
			case SDLK_ESCAPE:
				close = true;
				break;
			}
		default:
			break;
		}
	}
}

void window::clear() const
{
	SDL_SetRenderDrawColor(_renderer, 0, 200, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_Rect rect;
	rect.w = 120;
	rect.h = 120;
	rect.x = (width / 2) - (rect.w / 2);
	rect.y = (height / 2) - (rect.h / 2);
	SDL_SetRenderDrawColor(_renderer, 200, 200, 200, 255);
	SDL_RenderFillRect(_renderer, &rect);
	SDL_RenderPresent(_renderer);

}