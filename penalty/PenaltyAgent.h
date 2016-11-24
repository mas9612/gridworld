#ifndef ___PENALTY_AGENT_H___
#define ___PENALTY_AGENT_H___

#include "agent.h"

class PenaltyAgent : public Agent
{
private:
    const double PENALTY;

public:
    PenaltyAgent(double penalty, int n, int life = 0,
            double reward_coef = 0, int lon_limit = 0);
    void reward(GridWorld& grid);
};

#endif

