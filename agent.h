#ifndef ___AGENT_H___
#define ___AGENT_H___

#include <vector>
#include "gridworld.h"

class Agent
{
private:
    const int LIFE;
    const double REWARD_COEF;
    const int LOG_LIMIT;
    enum Direction { UP, DOWN, RIGHT, LEFT };
    int x;
    int y;
    std::vector<int> x_log;
    std::vector<int> y_log;
    std::vector<enum Direction> direction_log;

    void reward(GridWorld& grid);
    void move(Cell cell);

public:
    Agent(int n, int life, double reward_coef, int log_limit);
    void reinforcementLearning(GridWorld& grid);

    int getX() { return this->x; }
    int getY() { return this->y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

};

#endif

