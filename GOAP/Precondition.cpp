#include "Precondition.h"

// Comparaison entre la valeur actuelle et la valeur n�cessaire
bool Precondition::IsSatisfied(World world) const {
    return *world.GetResource(type) >= neededValue;
}