#include "Window.hpp"

int main()
{
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