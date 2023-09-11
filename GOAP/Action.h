#pragma once

#include "World.h"

class Action {
public:
    virtual bool IsValid(const World& current) const = 0; // préconditions
    virtual void Execute(World& current) const = 0; // effets
    virtual int GetCost() const = 0;
};

class GatherWoodAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};

class GatherStoneAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};

class GatherFoodAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};

class GenerateWorkerAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};

class BuildHouseAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};