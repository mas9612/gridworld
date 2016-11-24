#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
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
    return this->grid[y][x];
}

void GridWorld::setCell(int x, int y, Cell cell)
{
    this->grid[y][x] = cell;
}

void GridWorld::printGrid()
{
    for (int i = 0; i < this->grid.size(); i++) {
        std::vector<std::vector<std::string> > directions;
        for (int j = 0; j < this->grid[i].size(); j++) {
            std::vector<std::string> dir;
            std::vector<double> rewards = {this->grid[i][j].getUp(), this->grid[i][j].getDown(), this->grid[i][j].getRight(), this->grid[i][j].getLeft()};
            double max = *std::max_element(rewards.begin(), rewards.end());
            if (i == this->getGoalY() && j == this->getGoalX())
                dir.push_back("goal");
            else {
                if (this->grid[i][j].getUp() == max)
                    dir.push_back("up");
                if (this->grid[i][j].getDown() == max)
                    dir.push_back("down");
                if (this->grid[i][j].getRight() == max)
                    dir.push_back("right");
                if (this->grid[i][j].getLeft() == max)
                    dir.push_back("left");
            }
            directions.push_back(dir);
        }

        for (int j = 0; j < 7 * this->width + 1; j++)
            std::cout << "-";
        std::cout << '\n';
        for (std::vector<std::vector<std::string> >::iterator itr = directions.begin(); itr != directions.end(); itr++) {
            if (std::find(itr->begin(), itr->end(), "up") != itr->end())
                std::cout << "|  ↑  ";
            else
                std::cout << "|      ";
        }
        std::cout << "|\n";
        for (std::vector<std::vector<std::string> >::iterator itr = directions.begin(); itr != directions.end(); itr++) {
            if (std::find(itr->begin(), itr->end(), "goal") != itr->end())
                std::cout << "| Goal ";
            else if ((std::find(itr->begin(), itr->end(), "left") != itr->end()) && (std::find(itr->begin(), itr->end(), "right") != itr->end()))
                std::cout << "|←  →";
            else if (std::find(itr->begin(), itr->end(), "left") != itr->end())
                std::cout << "|←    ";
            else if (std::find(itr->begin(), itr->end(), "right") != itr->end())
                std::cout << "|    →";
            else
                std::cout << "|      ";
        }
        std::cout << "|\n";
        for (std::vector<std::vector<std::string> >::iterator itr = directions.begin(); itr != directions.end(); itr++) {
            if (std::find(itr->begin(), itr->end(), "down") != itr->end())
                std::cout << "|  ↓  ";
            else
                std::cout << "|      ";
        }
        std::cout << "|\n";
    }
    for (int i = 0; i < 7 * this->width + 1; i++)
        std::cout << "-";
    std::cout << '\n';
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

