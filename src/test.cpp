#include <ftxui/dom/elements.hpp>
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
        auto can = Canvas(300,50);
        if(frame%20==0){
            can.DrawBlockEllipse(9,10,5,1);

           
        }
            

       else{
            can.DrawBlockEllipse(9,10,5,5);
        }
        can.DrawBlockEllipse(29,10,5,5);
        can.DrawBlockLine(24,3,37,0);
        can.DrawBlockLine(2,0,14,0);
        can.DrawBlockEllipseFilled(19,18,2,3);
        can.DrawBlockEllipse(19,22,4,3);
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
}