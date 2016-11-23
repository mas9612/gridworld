#include <iostream>
#include <vector>
#include <random>
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

void Evaluator::move(Cell cell)
{
    std::vector<Direction> maxDirection;
    std::vector<double> probs = {cell.getProbUp(), cell.getProbDown(), cell.getProbRight(), cell.getProbLeft()};
    double max = *std::max_element(probs.begin(), probs.end());

    for (int i = 0; i < probs.size(); i++) {
        if (probs[i] == max)
            maxDirection.push_back(static_cast<Direction>(i));
    }

    Direction moveTo;
    if (maxDirection.size() <= 1) {
        moveTo = maxDirection[0];
    } else {
        std::random_device rand;
        int index = rand() % maxDirection.size();
        moveTo = maxDirection[index];
    }

    switch (moveTo) {
        case UP:
            this->y--;
            break;
        case DOWN:
            this->y++;
            break;
        case RIGHT:
            this->x++;
            break;
        case LEFT:
            this->x--;
            break;
        default:
            break;
    }
}
