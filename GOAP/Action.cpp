#include "Action.h"

Action::Action(const std::string& actionName) : actionName(actionName), cost(0) {}

// Vérifier si toutes les préconditions de l'action sont satisfaites
bool Action::IsApplicable(World& world) const {
    for (const Precondition& precondition : preconditions) {
        if (!precondition.IsSatisfied(world)) {
            return false;
        }
    }
    return true;
}

void Action::Apply(World& world) const {
    for (const Effect& effect : effects) {
        effect.Execute(world);
    }
}

void Action::AddPrecondition(const Precondition& precondition) {
    preconditions.push_back(precondition);
}

void Action::AddEffect(const Effect& effect) {
    effects.push_back(effect);
}

void Action::SetCost(int actionCost) {
    cost = actionCost;
}

int const Action::GetCost() const {
    return cost;
}

std::vector<Precondition> const& Action::GetPreconditions() const {
    return preconditions;
}

std::vector<Effect> const& Action::GetEffects() const {
    return effects;
}