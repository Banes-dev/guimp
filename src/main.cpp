#include "Window.hpp"

int main()
// int SDL_main(int argc, char* argv[])
{
    try {
		Window window("GUImp", 800, 600);
        while (window.isOpen())
        {
            window.handleEvents();
            window.clear();
            // Dessin ici
            window.present();
        }
    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
    }

    return (0);
}