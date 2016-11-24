#ifndef ___AGENT_H___
#define ___AGENT_H___

#include <vector>
#include "gridworld.h"

class Agent
{
protected:
    enum Direction { UP, DOWN, RIGHT, LEFT };
    int x;
    int y;
    const double REWARD_COEF;
    const int LOG_LIMIT;
    std::vector<int> x_log;
    std::vector<int> y_log;
    std::vector<enum Direction> direction_log;

private:
    const int LIFE;

public:
    Agent(int n, int life = 0, double reward_coef = 0, int log_limit = 0);

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    int getLife();

    void reinforcementLearning(GridWorld& grid);
    virtual void reward(GridWorld& grid);
    virtual void move(Cell cell);
};

#endif

