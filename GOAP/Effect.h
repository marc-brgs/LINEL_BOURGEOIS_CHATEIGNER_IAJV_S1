#pragma once
#include <string>

class Effect {
public:
    Effect(const std::string& name, int value);

    const std::string& GetName() const;
    int GetValue() const;

private:
    std::string effectName;
    int value;
};

