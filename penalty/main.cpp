#include <iostream>
#include "gridworld.h"
#include "agent.h"
#include "evaluator.h"
#include "PenaltyAgent.h"

int main(int argc, char *argv[])
{
    int WORLD_SIZE = 4;
    int NUMBER_OF_AGENT = 100;
    int AGENT_LIFE = 100;
    int EVALUATOR_LIFE = 10;
    int LOG_LIMIT = 4;
    double REWARD_COEF = 10.0;
    double PENALTY = 10.0;

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

    std::cout << "World size: " << WORLD_SIZE << '\n';
    std::cout << "Agent life: " << AGENT_LIFE << '\n';
    std::cout << "Number of agent: " << NUMBER_OF_AGENT << '\n';
    std::cout << "Log limit: " << LOG_LIMIT << '\n';
    std::cout << "Goal: (" << gridworld.getGoalX() << ", " << gridworld.getGoalY() << ")\n";
    std::cout << "Goal achieved: " << goalAchieved << '\n';

    gridworld.printGrid();
}

