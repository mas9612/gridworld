#include <iostream>
#include "gridworld.h"
#include "agent.h"
#include "evaluator.h"
#include "PenaltyAgent.h"

int main()
{
    // const
    const int WORLD_SIZE = 10;
    const int NUMBER_OF_AGENT = 100;
    const int AGENT_LIFE = 100;
    const int EVALUATOR_LIFE = 25;
    const int LOG_LIMIT = 20;
    const double REWARD_COEF = 10.0;
    const double PENALTY = 10.0;

    GridWorld gridworld(WORLD_SIZE);

    gridworld.setGoal();

    for (int id = 0; id < NUMBER_OF_AGENT; id++) {
        PenaltyAgent agent(PENALTY, WORLD_SIZE, AGENT_LIFE, REWARD_COEF, LOG_LIMIT);
        agent.reinforcementLearning(gridworld);
    }

    int goalAchieved = 0;
    for (int id = 0; id < NUMBER_OF_AGENT; id++) {
        Evaluator evaluator(WORLD_SIZE, EVALUATOR_LIFE);
        goalAchieved += evaluator.checkLearning(gridworld);
    }

    gridworld.printGrid();
}

