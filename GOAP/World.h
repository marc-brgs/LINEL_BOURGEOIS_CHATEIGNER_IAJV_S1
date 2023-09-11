#pragma once


class World {
public:
    int wood;
    int stone;
    int food;
    int workers;

    int houseNumber;

    // Constructeur
    World(int w, int s, int f, int wk) : wood(w), stone(s), food(f), workers(wk) {
        houseNumber = 0;
    }
};

