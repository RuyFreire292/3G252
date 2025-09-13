// # comandos de preprocesador
//c++ src/main.cpp -o bin/programa -I include
//man make    para documentacion
//./bin/programa
#include <iostream>
#include <Foco.hpp>
using namespace std;
int main()
{
    Foco foquito;
    foquito.Encender();
    foquito.Apagar();

    return 0;
}
