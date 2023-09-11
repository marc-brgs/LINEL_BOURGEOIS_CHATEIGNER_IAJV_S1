// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include <iostream>
#include <windows.h>
#include "World.h"

namespace StarterResources {
    constexpr int Wood = 0;
    constexpr int Stone = 0;
    constexpr int Food = 0;
    constexpr int Worker = 0;
}

bool objectiveReached = false;

int main()
{
    World world(StarterResources::Wood, StarterResources::Stone, StarterResources::Food, StarterResources::Worker);

    while(!objectiveReached) {
        std::cout << "Action test\n";
        Sleep(2000);
    }
}
