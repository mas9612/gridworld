#include <iostream>
#include "gridworld.h"
#include "agent.h"
#include "evaluator.h"

int main()
{
    // const
    const int WORLD_SIZE = 10;
    const int NUMBER_OF_AGENT = 100;
    const int AGENT_LIFE = 100;
    const int EVALUATOR_LIFE = 20;
    const int LOG_LIMIT = 10;
    const double REWARD_COEF = 10.0;

    GridWorld gridworld(WORLD_SIZE);

    gridworld.setGoal();

    for (int id = 0; id < NUMBER_OF_AGENT; id++) {
        Agent agent(WORLD_SIZE, AGENT_LIFE, REWARD_COEF, LOG_LIMIT);
        agent.reinforcementLearning(gridworld);
    }

    int goalAchieved = 0;
    for (int id = 0; id < NUMBER_OF_AGENT; id++) {
        Evaluator evaluator(WORLD_SIZE, EVALUATOR_LIFE);
        goalAchieved += evaluator.checkLearning(gridworld);
    }

    std::cout << "======================== Statistics ==========================\n";
    std::cout << "World size: " << WORLD_SIZE << '\n';
    std::cout << "Number of agent: " << NUMBER_OF_AGENT << '\n';
    std::cout << "Agent life: " << AGENT_LIFE << '\n';
    std::cout << "Reward coefficient: " << REWARD_COEF << '\n';
    std::cout << "Number of evaluator: " << NUMBER_OF_AGENT << '\n';
    std::cout << "Evaluator life: " << EVALUATOR_LIFE << '\n';
    std::cout << "Number of evaluator achieved goal: " << goalAchieved << '\n';
}

