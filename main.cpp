#include <Foco.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    Foco foco1;
    Foco foco2;

    std::cout<<"Encendiendo el foco"<<std::endl;
    foco1.Encender();
    std::cout<<"Apagando el foco"<<std::endl;
    foco2.Prender();

    return 0;
}
