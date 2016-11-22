#include <iostream>
#include <iomanip>
#include <random>
#include "gridworld.h"

GridWorld::GridWorld(int n)
    : width(n)
{
    for (int i = 0; i < n; i++) {
        std::vector<Cell> row(n);

        // set probability of outbound direction to 0
        if (i == 0) {
            for (std::vector<Cell>::iterator itr = row.begin(); itr != row.end(); itr++)
                itr->setUp(0);
        } else if (i == n - 1) {
            for (std::vector<Cell>::iterator itr = row.begin(); itr != row.end(); itr++)
                itr->setDown(0);
        }
        row.front().setLeft(0);
        row.back().setRight(0);

        for (std::vector<Cell>::iterator itr = row.begin(); itr != row.end(); itr++)
            itr->calcProbability();

        this->grid.push_back(row);
    }
}

void GridWorld::setGoal()
{
    std::random_device rand;

    this->goalX = rand() % this->width;
    this->goalY = rand() % this->width;
}

int GridWorld::getGoalX()
{
    return this->goalX;
}

int GridWorld::getGoalY()
{
    return this->goalY;
}

Cell GridWorld::getCell(int x, int y)
{
    // return this->grid[x][y];
    return this->grid[y][x];
}

void GridWorld::setCell(int x, int y, Cell cell)
{
    this->grid[y][x] = cell;
}

void GridWorld::printGrid()
{
    for (int i = 0; i < this->grid.size(); i++) {
        for (int j = 0; j < this->grid[i].size(); j++) {
            std::cout << "x = " << j << ", y = " << i << '\n';
            std::cout << "  up: " << this->grid[i][j].getUp() << '\n';
            std::cout << "  down: " << this->grid[i][j].getDown() << '\n';
            std::cout << "  right: " << this->grid[i][j].getRight() << '\n';
            std::cout << "  left: " << this->grid[i][j].getLeft() << '\n';
        }
        std::cout << std::endl;
    }
}

void GridWorld::printProb()
{
    for (int i = 0; i < this->grid.size(); i++) {
        for (int j = 0; j < this->grid[i].size(); j++) {
            std::cout << "x = " << j << ", y = " << i << '\n';
            std::cout << "  p_up: " << this->grid[i][j].getProbUp() << '\n';
            std::cout << "  p_down: " << this->grid[i][j].getProbDown() << '\n';
            std::cout << "  p_right: " << this->grid[i][j].getProbRight() << '\n';
            std::cout << "  p_left: " << this->grid[i][j].getProbLeft() << '\n';
        }
        std::cout << std::endl;
    }
}

