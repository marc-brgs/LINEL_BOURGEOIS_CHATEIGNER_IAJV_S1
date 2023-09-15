#pragma once

#include "World.h"
#include "Precondition.h"
#include "Effect.h"
#include <string>
#include <vector>


class Action {
public:
    Action(const std::string& name);

    bool IsApplicable(World world) const;
    void Apply(World& world) const;
    void AddPrecondition(const Precondition& precondition);
    void AddEffect(const Effect& effect);
    void SetCost(int actionCost);
    int const GetCost() const;

    std::vector<Effect> const& GetEffects() const {
        return effects;
    }

    std::vector<Precondition> const& GetPreconditions() const {
        return preconditions;
    }

private:
    std::string actionName;
    std::vector<Precondition> preconditions;
    std::vector<Effect> effects;
    int cost;
};
