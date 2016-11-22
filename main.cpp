#include <iostream>
#include "gridworld.h"
#include "agent.h"

int main()
{
    // const
    const int WORLD_SIZE = 4;
    const int NUMBER_OF_AGENT = 100;
    const int AGENT_LIFE = 100;
    const int REWARD_COEF = 1;
    const int LOG_LIMIT = 10;

    GridWorld gridworld(WORLD_SIZE);

    gridworld.setGoal();

    for (int id = 0; id < NUMBER_OF_AGENT; id++) {
        Agent agent(WORLD_SIZE, AGENT_LIFE, REWARD_COEF, LOG_LIMIT);
        agent.reinforcementLearning(gridworld);
    }
}

