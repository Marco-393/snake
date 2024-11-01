/*#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;

    while (true)
    {
        auto can = Canvas(100, 50);
        if (frame % 20 == 0)
        {
            can.DrawBlockEllipse(9, 10, 5, 1);
            can.DrawBlockEllipse(19, 22, 4, 1);
        }

        else
        {
            can.DrawBlockEllipse(9, 10, 5, 5);
            can.DrawBlockEllipse(19, 22, 4, 3);
        }
        
        can.DrawBlockEllipse(29, 10, 5, 5);
        can.DrawBlockLine(24, 3, 37, 0);
        can.DrawBlockLine(2, 0, 14, 0);
        can.DrawBlockEllipseFilled(19, 18, 2, 3);

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Green1, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}*/
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>
#include <chrono> // Para usar la función sleep_for

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int animation_direction = 1; // 1 para desarmar, -1 para armar
    int max_frame = 100; // Define el punto máximo de desarme
    bool is_armed = false; // Variable para controlar si el carro está armado

    while (true)
    {
        auto can = Canvas(300, 100);

        // Dibuja el carro
        int FD = frame * animation_direction; 
        can.DrawBlockCircle(100, 75 - FD, 15);
        can.DrawBlockCircle(200, 75 - FD, 15);
        can.DrawBlockLine(115, 75 - 1 - FD, 185, 75 - 1 - FD);
        can.DrawBlockLine(75 - FD, 75, 85 - FD, 75);
        can.DrawBlockLine(215 + FD, 75, 225 + FD, 75);
        can.DrawBlockLine(75 - FD, 75, 75 - FD, 40);
        can.DrawBlockLine(225 + FD, 75, 225 + FD, 50);
        can.DrawBlockLine(75, 40 - FD, 225, 50 - FD);
        can.DrawBlockLine(75 + 2 * FD, 40, 75 + 2 * FD, 30);
        can.DrawBlockLine(75, 30 - FD, 70, 30 - FD);

        // Dibuja el lienzo
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Red, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);

        // Controla la animación
        frame += animation_direction; 
        if (frame >= max_frame || frame <= 0) {
            animation_direction *= -1; // Cambia la dirección de la animación
            if (frame == 0) { // Si el carro se armó
                is_armed = true;
                this_thread::sleep_for(chrono::milliseconds(1500)); // Espera 1.5 segundos
                is_armed = false;
            }
        }

        if (!is_armed) {
            this_thread::sleep_for(chrono::milliseconds(100)); // Espera 0.1 segundos
        }
    }

    return 0;
}