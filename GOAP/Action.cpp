#include "Action.h"


bool GatherWoodAction::IsValid(const World& current) const {
    return current.workers > 0;
}

void GatherWoodAction::Execute(World& current) const {
    current.wood += current.workers;
}

int GatherWoodAction::GetCost() const {
    return 1;
}