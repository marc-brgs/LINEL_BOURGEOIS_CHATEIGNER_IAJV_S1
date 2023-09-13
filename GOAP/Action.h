#pragma once

#include "World.h"
#include "Precondition.h"
#include "Effect.h"
#include <string>
#include <vector>


class Action {
public:
    Action(const std::string& name);

    bool IsApplicable() const;
    void AddPrecondition(const Precondition& precondition);
    void AddEffect(const Effect& effect);
    void SetCost(int actionCost);

private:
    std::string actionName;
    std::vector<Precondition> preconditions;
    std::vector<Effect> effects;
    int cost;
};
