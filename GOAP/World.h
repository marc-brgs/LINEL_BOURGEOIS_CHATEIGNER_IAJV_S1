#pragma once
#include "Resources.h"

class World {
private:
    int wood;
    int stone;
    int food;
    int workers;
    int houses;

public:
    // Constructeur
    World(int w, int s, int f, int wk, int h) : wood(w), stone(s), food(f), workers(wk), houses(h) {}

    bool operator>=(const World& other) const;

    void Debug() const;

    int* GetResource(Resources type);

    void AddWood(int amount);
    int const GetWood() const;

    void AddStone(int amount);
    int const GetStone() const;

    void AddFood(int amount);
    int const GetFood() const;

    void AddWorker(int amount);
    int const GetWorkers() const;

    void AddHouse(int amount);
    int const GetHouses() const;
};

