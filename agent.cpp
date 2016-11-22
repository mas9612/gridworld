#include <iostream>
#include <random>
#include "agent.h"
#include "cell.h"


Agent::Agent(int n, int life, double reward_coef, int log_limit)
    : LIFE(life), REWARD_COEF(reward_coef), LOG_LIMIT(log_limit)
{
    std::random_device rand;

    // this->x = rand() % n;
    // this->y = rand() % n;
    this->x = 1;
    this->y = 1;
}

void Agent::reinforcementLearning(GridWorld grid)
{
    for (int i = 0; i < this->LIFE; i++) {
        // if goal then give reword
        if (this->x == grid.getGoalX() && this->y == grid.getGoalY()) {
            reward(grid);
            grid.printGrid();
            break;
        }

        // ========================= DEBUG ===========================
        // std::cout << "i: " << i << '\n';
        std::cout << "  x: " << this->x << ", y: " << this->y << '\n';
        Cell cell = grid.getCell(this->x, this->y);
        std::cout << "  p_up: " << cell.getP_up();
        std::cout << "  p_down: " << cell.getP_down();
        std::cout << "  p_right: " << cell.getP_right();
        std::cout << "  p_left: " << cell.getP_left();
        std::cout << '\n';
        // std::cout << "  up: " << cell.getUp() << '\n';
        // std::cout << "  down: " << cell.getDown() << '\n';
        // std::cout << "  right: " << cell.getRight() << '\n';
        // std::cout << "  left: " << cell.getLeft() << '\n';
        // ========================= DEBUG ===========================

        move(grid.getCell(this->x, this->y));
        // grid.printProb();
    }
}

void Agent::reward(GridWorld grid)
{
    std::cout << "ゴール\n";
    int step = this->direction_log.size();

    for (int t = 1; t < this->LOG_LIMIT && t < step; t++) {
        int x = this->x_log[step - t];
        int y = this->y_log[step - t];
        enum Direction direction = this->direction_log[step - t];
        Cell oldCell = grid.getCell(x, y);
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

    std::cout << "number: " << number << '\n';
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // save move log
    this->x_log.push_back(this->x);
    this->y_log.push_back(this->y);

    // decide direction and move
    if (number < cell.getP_up()) {
        this->y--;
        this->direction_log.push_back(UP);
    // } else if (number < cell.getUp() + cell.getRight()) {
    } else if ((number < cell.getP_up() + cell.getP_right()) || (cell.getP_down() == 0 && cell.getP_left() == 0)) {
        this->x++;
        this->direction_log.push_back(RIGHT);
    // } else if (number < cell.getUp() + cell.getRight() + cell.getDown()) {
    } else if ((number < cell.getP_up() + cell.getP_right() + cell.getP_down()) || cell.getP_left() == 0) {
        this->y++;
        this->direction_log.push_back(DOWN);
    } else {
        this->x--;
        this->direction_log.push_back(LEFT);
    }
}

