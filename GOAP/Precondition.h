#pragma once
#include <string>
#include <map>
#include "Resources.h"
#include "World.h"

class Precondition {
public:
    Precondition(Resources t, int needed) : type(t), neededValue(needed) {};

    bool IsSatisfied(World world) const;

private:
    Resources type;
    int neededValue;
};

