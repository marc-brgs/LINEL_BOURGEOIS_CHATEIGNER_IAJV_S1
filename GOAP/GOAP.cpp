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


std::vector<Action*> PlanGOAP(const World& initialState, const World& goalState, const std::vector<Action*>& availableActions);

namespace StarterResources {
    constexpr int Wood = 0;
    constexpr int Stone = 0;
    constexpr int Food = 5;
    constexpr int Workers = 1;
    constexpr int Houses = 0;
}

bool objectiveReached = false;

int main() {
    World world(StarterResources::Wood, StarterResources::Stone, StarterResources::Food, StarterResources::Workers, StarterResources::Houses);
    World goalState(0, 0, 0, 0, 1);

    std::vector<Action*> availableActions;
    availableActions.push_back(new GatherWoodAction());
    availableActions.push_back(new GatherStoneAction());
    availableActions.push_back(new GatherFoodAction());
    availableActions.push_back(new GenerateWorkerAction());
    availableActions.push_back(new BuildHouseAction());

    std::vector<Action*> plan = PlanGOAP(world, goalState, availableActions);
    std::cout << "GOAP Plan defined" << "\n\n";

    for(Action* action : plan) {
        if (action->IsValid(world)) {
            action->Execute(world);
            world.Debug();
        }
        else {
            std::cout << "Action not valid" << "\n";
        }
        Sleep(2000);
    }

    std::cout << "Final world : ";
    world.Debug();
    std::cout << "Goal world : ";
    goalState.Debug();

    for (Action* action : availableActions) {
        delete action;
    }

    std::cout << "\nEND PROGRAM\n";
}

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
}