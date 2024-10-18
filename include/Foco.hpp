class Foco
{
private:
    
public:
    bool encendido;
    Foco() {}
    ~Foco() {}

    void  Encender(){
        this->encendido = true;
    }
    void Prender(){
        this->encendido = false;
    }
};