#pragma once
#include <string>
#include <cassert>
#include "World.h"

class Effect {
public:
    Effect(Resources t, int o) : type(t), offset(o) {}

    void Execute(World& world) const;

private:
    Resources type;
    int offset;
};