#include "Precondition.h"

// Comparaison entre la valeur actuelle et la valeur nécessaire
bool Precondition::IsSatisfied(World world) const {
    return *world.GetResource(type) >= neededValue;
}