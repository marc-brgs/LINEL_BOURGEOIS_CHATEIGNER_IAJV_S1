#include "Precondition.h"

// Comparaison entre la valeur actuelle et la valeur nécessaire
bool Precondition::IsSatisfied(World world) const {
    //assert(world.GetResource(type) == nullptr);

    return *world.GetResource(type) >= neededValue;
}