#pragma once

#include "World.h"
#include "Precondition.h"
#include "Effect.h"
#include <string>
#include <vector>


class Action {
public:
    Action(const std::string& name);

    bool IsApplicable(const std::map<std::string, int>& currentState) const;
    void AddPrecondition(const Precondition& precondition);
    void AddEffect(const Effect& effect);
    void SetCost(int actionCost);

private:
    std::string actionName;
    std::vector<Precondition> preconditions;
    std::vector<Effect> effects;
    int cost;
};








//class Action {
//public:
//    virtual bool IsValid(const World& current) const = 0; // préconditions
//    virtual void Execute(World& current) const = 0; // effets
//    virtual int GetCost() const = 0;
//};

//class IdleAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};
//
//class GatherWoodAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};
//
//class GatherStoneAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};
//
//class GatherFoodAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};
//
//class GenerateWorkerAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};
//
//class BuildHouseAction : public Action {
//public:
//    bool IsValid(const World& current) const override;
//    void Execute(World& current) const override;
//    int GetCost() const override;
//};