#include <iostream>
#include "menu.h"
using namespace std;

void menu()
{
    int opcion;

    cout<< "MENU" << endl;
    cout<< "1 - UN JUGADOR" << endl;
    cout<< "2 - DOS JUGADORES" << endl;
    cout<< "0 - SALIR" << endl;

    cin>> opcion;

    switch(opcion)
    {
    case 0:
        return;
        break;

    }
}
