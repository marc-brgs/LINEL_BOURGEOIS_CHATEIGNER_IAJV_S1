// GOAP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "World.h"
#include "Action.h"
#include "Precondition.h"
#include "Effect.h"
#include "Resources.h"

std::vector<Action*> InitActions();
void DestroyActions(std::vector<Action*>& actions);
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

int main() {
    // Define intial and goal states
    World world(StarterResources::Wood, StarterResources::Stone, StarterResources::Food, StarterResources::Workers, StarterResources::Houses);
    World goalState(GoalResources::Wood, GoalResources::Stone, GoalResources::Food, GoalResources::Workers, GoalResources::Houses);
    
    std::cout << "\nStart world : ";
    world.Debug();
    std::cout << "\n";

    // Define actions
    std::vector<Action*> availableActions;
    availableActions = InitActions();
   
    // Define GOAP plan
    std::vector<Action*> plan = PlanGOAP(world, goalState, availableActions);
    if (plan.empty()) {
        std::cout << "GOAP Plan not defined (empty)" << "\n\n";
    }
    else {
        std::cout << "GOAP Plan defined" << "\n\n";
    }
    
    availableActions.at(0)->Apply(world);
    // Apply plan
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

    // Final debug
    std::cout << "\nFinal world : ";
    world.Debug();
    std::cout << "Goal world : ";
    goalState.Debug();

    // Destroy actions
    DestroyActions(availableActions);

    std::cout << "\nEND PROGRAM\n";
}

std::vector<Action*> InitActions() {
    std::vector<Action*> actions;

    Action* chopWoodAction = new Action("Chop Wood");
    Action* gatherStoneAction = new Action("Gather Stones");
    Action* gatherFoodAction = new Action("Gather Food");
    Action* recruitWorkerAction = new Action("Recruit Worker");
    Action* buildHouseAction = new Action("Build House");
    //Action* reassignWorkerAction = new Action("Reassign Worker");
    //Action* feedWorkerAction = new Action("Feed Worker");

    chopWoodAction->AddPrecondition(Precondition(Resources::Workers, 1));
    chopWoodAction->AddEffect(Effect(Resources::Wood, 1));
    chopWoodAction->SetCost(2);

    gatherStoneAction->AddPrecondition(Precondition(Resources::Workers, 1));
    gatherStoneAction->AddEffect(Effect(Resources::Stone, 1));
    gatherStoneAction->SetCost(2);

    gatherFoodAction->AddPrecondition(Precondition(Resources::Workers, 1));
    gatherFoodAction->AddEffect(Effect(Resources::Food, 1));
    gatherFoodAction->SetCost(2);

    recruitWorkerAction->AddPrecondition(Precondition(Resources::Food, 5));
    recruitWorkerAction->AddEffect(Effect(Resources::Workers, 1));
    recruitWorkerAction->AddEffect(Effect(Resources::Food, -5));
    recruitWorkerAction->SetCost(1);

    buildHouseAction->AddPrecondition(Precondition(Resources::Wood, 20));
    buildHouseAction->AddPrecondition(Precondition(Resources::Stone, 10));
    buildHouseAction->AddEffect(Effect(Resources::Houses, 1));
    buildHouseAction->AddEffect(Effect(Resources::Wood, -20));
    buildHouseAction->AddEffect(Effect(Resources::Stone, -10));
    buildHouseAction->SetCost(1);

    actions.push_back(chopWoodAction);
    actions.push_back(gatherStoneAction);
    actions.push_back(gatherFoodAction);
    actions.push_back(recruitWorkerAction);
    actions.push_back(buildHouseAction);

    return actions;
}

void DestroyActions(std::vector<Action*> &actions) {
    for (Action* action : actions) {
        delete action;
    }
}

// Structure pour représenter un nœud dans la recherche GOAP
struct GOAPNode {
    World state;
    Action* action;
    int cost;
    GOAPNode* parent;
    int heuristic; // Valeur heuristique

    GOAPNode(const World& s, Action* a, int c, GOAPNode* p, int h)
        : state(s), action(a), cost(c), parent(p), heuristic(h) {}
};


// Fonction pour calculer la valeur heuristique entre deux états
int CalculateHeuristic(const World& currentState, const World& goalState, const std::vector<Precondition>& unsatisfiedPreconditions) {
    int heuristic = unsatisfiedPreconditions.size();

    return heuristic;
}


std::vector<Action*> PlanGOAP(const World& initialState, const World& goalState, const std::vector<Action*>& availableActions) {
    std::vector<GOAPNode> openNode;
    std::vector<Precondition> unsatisfiedPreconditions;

    // Ajoutez le nœud initial avec les préconditions du monde initial
    openNode.push_back(GOAPNode(initialState, nullptr, 0, nullptr, CalculateHeuristic(initialState, goalState, unsatisfiedPreconditions)));

    while (!openNode.empty()) {
        // Triez la liste openNode en fonction du coût + heuristique le plus bas
        std::sort(openNode.begin(), openNode.end(), [](const GOAPNode& a, const GOAPNode& b) {
            return a.cost + a.heuristic < b.cost + b.heuristic;
            });

        // Sélectionnez le nœud avec le coût + heuristique le plus bas
        GOAPNode currentNode = openNode.front();
        openNode.erase(openNode.begin());

        // Si toutes les préconditions sont satisfaites, nous avons trouvé une solution
        if (unsatisfiedPreconditions.empty()) {
            // Construisez et retournez le plan à partir du nœud final
            std::vector<Action*> plan;
            while (currentNode.parent != nullptr) {
                plan.insert(plan.begin(), currentNode.action); // Ajoutez l'action au début du plan
                currentNode = *currentNode.parent;
            }
            return plan;
        }

        // Explorez les actions disponibles
        for (Action* action : availableActions) {
            if (action->IsApplicable(currentNode.state)) {
                // Vérifiez si toutes les préconditions sont satisfaites
                bool allPreconditionsSatisfied = true;
                for (const Precondition& precondition : action->GetPreconditions()) {
                    if (!precondition.IsSatisfied(currentNode.state)) {
                        allPreconditionsSatisfied = false;
                        break; // Une précondition n'est pas satisfaite, donc ignorez cette action
                    }
                }

                if (allPreconditionsSatisfied) {
                    // Appliquez l'action pour obtenir un nouvel état
                    World nextState = currentNode.state;
                    action->Apply(nextState);

                    // Créez un nouveau nœud pour cet état
                    GOAPNode newNode(nextState, action, currentNode.cost + action->GetCost(), &currentNode, CalculateHeuristic(nextState, goalState, unsatisfiedPreconditions));
                    openNode.push_back(newNode);
                }
            }
        }
    }

    return {}; // Aucun plan trouvé
}

