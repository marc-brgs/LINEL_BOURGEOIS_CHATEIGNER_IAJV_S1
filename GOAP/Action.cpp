#include "Action.h"

// GatherWoodAction

bool GatherWoodAction::IsValid(const World& current) const {
    return current.GetWorkers() > 0;
}

void GatherWoodAction::Execute(World& current) const {
    current.AddWood(current.GetWorkers());
}

int GatherWoodAction::GetCost() const {
    return 1;
}

// GatherStoneAction

bool GatherStoneAction::IsValid(const World& current) const {
    return current.GetWorkers() > 0;
}

void GatherStoneAction::Execute(World& current) const {
    current.AddStone(current.GetWorkers());
}

int GatherStoneAction::GetCost() const {
    return 1;
}

// GatherFoodAction

bool GatherFoodAction::IsValid(const World& current) const {
    return current.GetWorkers() > 0;
}

void GatherFoodAction::Execute(World& current) const {
    current.AddFood(current.GetWorkers());
}

int GatherFoodAction::GetCost() const {
    return 1;
}

// GenerateWorkerAction

bool GenerateWorkerAction::IsValid(const World& current) const {
    return current.GetFood() >= 5;
}

void GenerateWorkerAction::Execute(World& current) const {
    current.AddFood(-5);
    current.AddWorker(1);
}

int GenerateWorkerAction::GetCost() const {
    return 1;
}

// BuildHouseAction

bool BuildHouseAction::IsValid(const World& current) const {
    return current.GetWood() >= 20 && current.GetStone() >= 10;
}

void BuildHouseAction::Execute(World& current) const {
    current.AddWood(-20);
    current.AddStone(-10);
    current.AddHouse(1);
}

int BuildHouseAction::GetCost() const {
    return 1;
}