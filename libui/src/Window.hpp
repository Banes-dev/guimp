#pragma once
#include <SDL.h>
#include <iostream>
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

		// Exceptions SDLInitException
		class SDLInitException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class WindowCantCreatedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class RendererCantCreatedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

