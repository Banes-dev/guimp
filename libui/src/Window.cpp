#include "Window.hpp"

Window::Window(const std::string &title, int width, int height) : running(true)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw (SDLInitException());
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
        throw (WindowCantCreatedException());
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        throw (RendererCantCreatedException());
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    SDL_Quit();
}

void Window::clear()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Window::present()
{
    SDL_RenderPresent(renderer);
}

bool Window::isOpen()
{
    return (running);
}

void Window::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            running = false;
    }
}

// Exceptions
const char *Window::SDLInitException::what() const throw()
{
	return ("\033[0;31mSDL can't be init\033[0m");
}
const char *Window::WindowCantCreatedException::what() const throw()
{
	return ("\033[0;31mThe window can't be created\033[0m");
}
const char *Window::RendererCantCreatedException::what() const throw()
{
	return ("\033[0;31mThe renderer can't be created\033[0m");
}
