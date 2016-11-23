#include "evaluator.h"

Evaluator::Evaluator(int n, int life)
    : Agent(n), LIFE(life)
{
}

int Evaluator::checkLearning(GridWorld& grid)
{
    for (int i = 0; i < this->LIFE; i++) {
        if (this->x == grid.getGoalX() && this->y == grid.getGoalY()) {
            return 1;
        }
        move(grid.getCell(this->x, this->y));
    }
    return 0;
}
