#include "Window.hpp"

// int main()
int SDL_main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    Window window("GUImp", 800, 600);
    while (window.isOpen())
	{
        window.handleEvents();
        window.clear();
        // Dessin ici
        window.present();
    }

    return (0);
}