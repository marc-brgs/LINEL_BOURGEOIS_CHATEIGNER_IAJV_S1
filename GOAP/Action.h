#pragma once

#include "World.h"

class Action {
public:
    virtual bool IsValid(const World& current) const = 0; // prérequis
    virtual void Execute(World& current) const = 0;
    virtual int GetCost() const = 0;
};

class GatherWoodAction : public Action {
public:
    bool IsValid(const World& current) const override;
    void Execute(World& current) const override;
    int GetCost() const override;
};