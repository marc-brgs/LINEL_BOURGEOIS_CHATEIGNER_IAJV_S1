#pragma once
#include <string>
#include <map>

class Precondition {
public:
    Precondition(int currentValue, int neededValue);

    bool IsSatisfied() const;

private:
    int currentValue;
    int neededValue;
};

