#include "Action.h"

Action::Action(const std::string& actionName) : actionName(actionName), cost(0) {}

bool Action::IsApplicable() const {
    // Vérifier si toutes les préconditions de l'action sont satisfaites.
    for (const Precondition& precondition : preconditions) {
        if (!precondition.IsSatisfied()) {
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


Action* chopWoodAction = new Action("Chop Wood");
Action* gatherStoneAction = new Action("Gather Stones");
Action* gatherApplesAction = new Action("Gather Apples");
Action* recruitWorkerAction = new Action("Recruit Worker");
Action* reassignWorkerAction = new Action("Reassign Worker");
Action* feedWorkerAction = new Action("Feed Worker");
Action* buildHouseAction = new Action("Build House");