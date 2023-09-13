#pragma once
#include "Resources.h"

class World {
private:
    

public:
    int wood;
    int stone;
    int food;
    int workers;
    int houses;

    // Constructeur
    World(int w, int s, int f, int wk, int h) : wood(w), stone(s), food(f), workers(wk), houses(h) {}

    bool operator>=(const World& other) const;

    void Debug() const;

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

    int* GetResource(Resources type) {
        switch (type)
        {
        case Resources::Wood:
            return &wood;
        case Resources::Stone:
            return &stone;
        case Resources::Food:
            return &food;
        case Resources::Workers:
            return &workers;
        case Resources::Houses:
            return &houses;
        default:
            return nullptr;
        }
    }
};

