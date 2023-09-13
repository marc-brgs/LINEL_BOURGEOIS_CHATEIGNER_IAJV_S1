#include "Precondition.h"


Precondition::Precondition(int current, int needed)
    : currentValue(current), neededValue(needed) {}

bool Precondition::IsSatisfied() const {
    // Comparaison entre la valeur actuelle et la valeur n�cessaire
    return currentValue >= neededValue;
}