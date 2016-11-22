#include <iostream>
#include <random>
#include "agent.h"
#include "cell.h"


Agent::Agent(int n, int life, double reward_coef, int log_limit)
    : LIFE(life), REWARD_COEF(reward_coef), LOG_LIMIT(log_limit)
{
    std::random_device rand;

    this->x = rand() % n;
    this->y = rand() % n;
}

void Agent::reinforcementLearning(GridWorld& grid)
{
    for (int i = 0; i < this->LIFE; i++) {
        // if goal then give reword
        if (this->x == grid.getGoalX() && this->y == grid.getGoalY()) {
            reward(grid);
            break;
        }

        move(grid.getCell(this->x, this->y));
    }
}

void Agent::reward(GridWorld& grid)
{
    int step = this->direction_log.size();

    for (int t = 1; t < this->LOG_LIMIT && t < step; t++) {
        int x = this->x_log[step - t];
        int y = this->y_log[step - t];
        enum Direction direction = this->direction_log[step - t];
        Cell oldCell = grid.getCell(x, y);
        // TODO: declare copy constructor and replace this statement
        Cell newCell(oldCell.getUp(), oldCell.getDown(), oldCell.getRight(), oldCell.getLeft());
        double add = this->REWARD_COEF * (this->LOG_LIMIT - t + 1) / this->LOG_LIMIT;
        switch (direction) {
            case UP:
                newCell.setUp(newCell.getUp() + add);
                break;
            case DOWN:
                newCell.setDown(newCell.getDown() + add);
                break;
            case RIGHT:
                newCell.setRight(newCell.getRight() + add);
                break;
            case LEFT:
                newCell.setLeft(newCell.getLeft() + add);
                break;
            default:
                break;
        }
        newCell.calcProbability();
        grid.setCell(x, y, newCell);
    }
}

void Agent::move(Cell cell)
{
    std::random_device rand;
    double number = (double)rand() / rand.max();

    // save move log
    this->x_log.push_back(this->x);
    this->y_log.push_back(this->y);

    // decide direction and move
    if (number < cell.getProbUp()) {
        this->y--;
        this->direction_log.push_back(UP);
    } else if (number < cell.getProbUp() + cell.getProbRight()) {
    // } else if ((number < cell.getProbUp() + cell.getProbRight()) || (cell.getProbDown() == 0 && cell.getProbLeft() == 0)) {
        this->x++;
        this->direction_log.push_back(RIGHT);
    } else if (number < cell.getProbUp() + cell.getProbRight() + cell.getProbDown()) {
    // } else if ((number < cell.getProbUp() + cell.getProbRight() + cell.getProbDown()) || cell.getProbLeft() == 0) {
        this->y++;
        this->direction_log.push_back(DOWN);
    } else {
        this->x--;
        this->direction_log.push_back(LEFT);
    }
}

