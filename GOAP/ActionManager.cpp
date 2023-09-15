#include "ActionManager.h"

std::vector<Action*> ActionManager::InitActions() {
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

void ActionManager::DestroyActions(std::vector<Action*>& actions) {
    for (Action* action : actions) {
        delete action;
    }
}
