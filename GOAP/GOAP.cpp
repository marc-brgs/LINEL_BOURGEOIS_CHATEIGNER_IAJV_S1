// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

#include "World.h"
#include "Action.h"
#include "Precondition.h"
#include "Effect.h"
#include "Resources.h"


std::vector<Action*> PlanGOAP(const World& initialState, const World& goalState, const std::vector<Action*>& availableActions);

namespace StarterResources {
    constexpr int Wood = 0;
    constexpr int Stone = 0;
    constexpr int Food = 5;
    constexpr int Workers = 1;
    constexpr int Houses = 0;
}

namespace GoalResources {
    constexpr int Wood = 0;
    constexpr int Stone = 0;
    constexpr int Food = 0;
    constexpr int Workers = 0;
    constexpr int Houses = 1;
}

bool objectiveReached = false;

int main() {
    World world(StarterResources::Wood, StarterResources::Stone, StarterResources::Food, StarterResources::Workers, StarterResources::Houses);
    World goalState(GoalResources::Wood, GoalResources::Stone, GoalResources::Food, GoalResources::Workers, GoalResources::Houses);

    Action* chopWoodAction = new Action("Chop Wood");
    Action* gatherStoneAction = new Action("Gather Stones");
    Action* gatherApplesAction = new Action("Gather Apples");
    Action* recruitWorkerAction = new Action("Recruit Worker");
    Action* buildHouseAction = new Action("Build House");
    //Action* reassignWorkerAction = new Action("Reassign Worker");
    //Action* feedWorkerAction = new Action("Feed Worker");

    chopWoodAction->AddPrecondition(Precondition(Resources::Workers, 1));
    chopWoodAction->AddEffect(Effect(Resources::Wood, 1));

    gatherStoneAction->AddPrecondition(Precondition(Resources::Workers, 1));
    gatherStoneAction->AddEffect(Effect(Resources::Stone, 1));

    gatherApplesAction->AddPrecondition(Precondition(Resources::Workers, 1));
    gatherApplesAction->AddEffect(Effect(Resources::Food, 1));

    recruitWorkerAction->AddPrecondition(Precondition(Resources::Food, 5));
    recruitWorkerAction->AddEffect(Effect(Resources::Workers, 1));

    buildHouseAction->AddPrecondition(Precondition(Resources::Wood, 20));
    buildHouseAction->AddPrecondition(Precondition(Resources::Stone, 10));
    buildHouseAction->AddEffect(Effect(Resources::Houses, 1));


    std::vector<Action*> availableActions;
    availableActions.push_back(chopWoodAction);
    availableActions.push_back(gatherStoneAction);
    availableActions.push_back(gatherApplesAction);
    availableActions.push_back(recruitWorkerAction);
    availableActions.push_back(buildHouseAction);

    std::vector<Action*> plan; //= PlanGOAP(world, goalState, availableActions);
    if (plan.empty()) {
        std::cout << "GOAP Plan not defined (empty)" << "\n\n";
    }
    else {
        std::cout << "GOAP Plan defined" << "\n\n";
    }

    if (gatherStoneAction->IsApplicable(world)) {
        gatherStoneAction->Apply(world);
        world.Debug();
    }
    

    for(Action* action : plan) {
        if (action->IsApplicable(world)) {
            action->Apply(world);
            world.Debug();
        }
        else {
            std::cout << "Action not valid" << "\n";
        }
        Sleep(2000);
    }

    std::cout << "\nFinal world : ";
    world.Debug();
    std::cout << "Goal world : ";
    goalState.Debug();

    for (Action* action : availableActions) {
        delete action;
    }

    std::cout << "\nEND PROGRAM\n";
}

/*
// Structure pour représenter un nœud dans la recherche GOAP
struct GOAPNode {
    World state;
    std::vector<Action*> plan;
    int cost;

    GOAPNode(const World& s, const std::vector<Action*>& p, int c)
        : state(s), plan(p), cost(c) {}
};

// Fonction pour planifier une séquence d'actions GOAP
std::vector<Action*> PlanGOAP(const World& initialState, const World& goalState, const std::vector<Action*>& availableActions) {
    std::vector<GOAPNode> openSet;

    // Ajouter l'état initial à la liste ouverte
    openSet.push_back(GOAPNode(initialState, {}, 0));

    while (!openSet.empty()) {
        // Trouver le nœud avec le coût le plus bas
        auto minNodeIt = std::min_element(openSet.begin(), openSet.end(), [](const GOAPNode& a, const GOAPNode& b) {
            return a.cost < b.cost;
            });
        GOAPNode currentNode = *minNodeIt;
        openSet.erase(minNodeIt);

        // Vérifier si l'objectif est atteint
        if (currentNode.state >= goalState) {
            return currentNode.plan;
        }

        // Explorer les actions disponibles
        for (Action* action : availableActions) {
            if (action->IsValid(currentNode.state)) {
                // Appliquer l'action à un nouvel état
                World nextState = currentNode.state;
                action->Execute(nextState);

                // Créer un nouveau nœud pour cet état
                std::vector<Action*> newPlan = currentNode.plan;
                newPlan.push_back(action);
                int newCost = currentNode.cost + action->GetCost();
                openSet.push_back(GOAPNode(nextState, newPlan, newCost));
                nextState.Debug();
            }
        }

        Sleep(500);
    }

    return {}; // Aucun plan trouvé
}*/