#include <iostream>
#include "PenaltyAgent.h"

PenaltyAgent::PenaltyAgent(double penalty, int n, int life,
        double reward_coef, int log_limit)
    : Agent(n, life, reward_coef, log_limit), PENALTY(penalty)
{
}

void PenaltyAgent::reward(GridWorld& grid)
{
    int step = this->direction_log.size();

    for (int t = 1; t < this->LOG_LIMIT && t < step; t++) {
        int x = this->x_log[step - t];
        int y = this->y_log[step - t];
        enum Direction direction = this->direction_log[step - t];
        Cell oldCell = grid.getCell(x, y);
        Cell newCell(oldCell.getUp(), oldCell.getDown(),
                oldCell.getRight(), oldCell.getLeft());
        double add = this->REWARD_COEF * (this->LOG_LIMIT - t + 1) / this->LOG_LIMIT;
        double sub = this->PENALTY * (this->LOG_LIMIT - t + 1) / this->LOG_LIMIT;
        switch (direction) {
            case UP:
                newCell.setUp(newCell.getUp() + add);
                newCell.setDown(newCell.getDown() - sub);
                break;
            case DOWN:
                newCell.setDown(newCell.getDown() + add);
                newCell.setUp(newCell.getUp() - sub);
                break;
            case RIGHT:
                newCell.setRight(newCell.getRight() + add);
                newCell.setLeft(newCell.getLeft() - sub);
                break;
            case LEFT:
                newCell.setLeft(newCell.getLeft() + add);
                newCell.setRight(newCell.getRight() - sub);
                break;
            default:
                break;
        }
        newCell.calcProbability();
        grid.setCell(x, y, newCell);
    }
}

