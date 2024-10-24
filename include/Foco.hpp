#pragma once
#include <iostream>

using namespace std;
class Foco
{
private:
public:
    bool encendido;
    Foco() {}
    ~Foco() {}

    void Encender()
    {
        this->encendido = true;
    }
    void Apagar()
    {
        this->encendido = false;
    }

    void Imprimir()
    {
        if (this->encendido)
        {

            cout << "0";
        }
        else
        {
            cout << ".";
        }
    }
};