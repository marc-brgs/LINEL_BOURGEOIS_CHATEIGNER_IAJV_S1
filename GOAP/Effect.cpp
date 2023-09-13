#include "Effect.h"

Effect::Effect(const std::string& effectName, int effectValue) : effectName(effectName), value(effectValue) {}

const std::string& Effect::GetName() const {
    return effectName;
}

int Effect::GetValue() const {
    return value;
}