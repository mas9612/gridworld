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
    std::vector<int> x_log;
    std::vector<int> y_log;
    std::vector<enum Direction> direction_log;

protected:
    int x;
    int y;

public:
    Agent(int n, int life = 0, double reward_coef = 0, int log_limit = 0);

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    int getLife();

    void reinforcementLearning(GridWorld& grid);
    void reward(GridWorld& grid);
    void move(Cell cell);
};

#endif

