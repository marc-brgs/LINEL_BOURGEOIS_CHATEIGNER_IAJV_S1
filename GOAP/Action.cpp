#include "Action.h"

Action::Action(const std::string& actionName) : actionName(actionName), cost(0) {}

bool Action::IsApplicable(const std::map<std::string, int>& currentState) const {
    // Vérifier si toutes les préconditions de l'action sont satisfaites.
    for (const Precondition& precondition : preconditions) {
        if (!precondition.IsSatisfied(currentState)) {
            return false; // Une précondition n'est pas satisfaite.
        }
    }
    return true;
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




// IdleAction

//bool IdleAction::IsValid(const World& current) const {
//    return true;
//}
//
//void IdleAction::Execute(World& current) const {
//
//}
//
//int IdleAction::GetCost() const {
//    return 0;
//}
//
//// GatherWoodAction
//
//bool GatherWoodAction::IsValid(const World& current) const {
//    return current.GetWorkers() > 0;
//}
//
//void GatherWoodAction::Execute(World& current) const {
//    current.AddWood(current.GetWorkers());
//}
//
//int GatherWoodAction::GetCost() const {
//    return 4;
//}
//
//// GatherStoneAction
//
//bool GatherStoneAction::IsValid(const World& current) const {
//    return current.GetWorkers() > 0;
//}
//
//void GatherStoneAction::Execute(World& current) const {
//    current.AddStone(current.GetWorkers());
//}
//
//int GatherStoneAction::GetCost() const {
//    return 5;
//}
//
//// GatherFoodAction
//
//bool GatherFoodAction::IsValid(const World& current) const {
//    return current.GetWorkers() > 0;
//}
//
//void GatherFoodAction::Execute(World& current) const {
//    current.AddFood(current.GetWorkers());
//}
//
//int GatherFoodAction::GetCost() const {
//    return 2;
//}
//
//// GenerateWorkerAction
//
//bool GenerateWorkerAction::IsValid(const World& current) const {
//    return current.GetFood() >= 5;
//}
//
//void GenerateWorkerAction::Execute(World& current) const {
//    current.AddFood(-5);
//    current.AddWorker(1);
//}
//
//int GenerateWorkerAction::GetCost() const {
//    return 3;
//}
//
//// BuildHouseAction
//
//bool BuildHouseAction::IsValid(const World& current) const {
//    return current.GetWood() >= 20 && current.GetStone() >= 10;
//}
//
//void BuildHouseAction::Execute(World& current) const {
//    current.AddWood(-20);
//    current.AddStone(-10);
//    current.AddHouse(1);
//}
//
//int BuildHouseAction::GetCost() const {
//    return 1;
//}