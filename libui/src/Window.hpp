#pragma once
#include <SDL.h>
#include <string>

class Window
{
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		bool running;

	public:
		Window(const std::string &title, int width, int height);
		~Window();
		void clear();
		void present();
		bool isOpen();
		void handleEvents();
};

