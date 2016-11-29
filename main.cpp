#include <iostream>
#include "gridworld.h"
#include "agent.h"
#include "evaluator.h"

int main(int argc, char *argv[])
{
    int WORLD_SIZE;
    int NUMBER_OF_AGENT;
    int AGENT_LIFE;
    int EVALUATOR_LIFE;
    int LOG_LIMIT;
    double REWARD_COEF;

    if (argc < 7) {
        std::cerr << "usage: " << argv[0] << " WORLD_SIZE NUMBER_OF_AGENT AGENT_LIFE EVALUATOR_LIFE"
            << " LOG_LIMIT REWARD_COEF\n";
        exit(1);
    }

    try {
        WORLD_SIZE = std::stoi(argv[1]);
        NUMBER_OF_AGENT = std::stoi(argv[2]);
        AGENT_LIFE = std::stoi(argv[3]);
        EVALUATOR_LIFE = std::stoi(argv[4]);
        LOG_LIMIT = std::stoi(argv[5]);
        REWARD_COEF = std::stod(argv[6]);
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what();
        exit(1);
    }

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

    std::cout << "World size: " << WORLD_SIZE << '\n';
    std::cout << "Agent life: " << AGENT_LIFE << '\n';
    std::cout << "Number of agent: " << NUMBER_OF_AGENT << '\n';
    std::cout << "Evaluator life: " << EVALUATOR_LIFE << '\n';
    std::cout << "Log limit: " << LOG_LIMIT << '\n';
    std::cout << "Goal: (" << gridworld.getGoalX() << ", " << gridworld.getGoalY() << ")\n";
    std::cout << "Goal achieved: " << goalAchieved << '\n';

    gridworld.printGrid();
}

