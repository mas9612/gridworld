#ifndef ___EVALUATOR_H___
#define ___EVALUATOR_H___

#include "agent.h"
#include "gridworld.h"

class Evaluator : public Agent
{
private:
    const int LIFE;

public:
    Evaluator(int n, int life);

    int checkLearning(GridWorld& grid);
    void move(Cell cell);
};

#endif
