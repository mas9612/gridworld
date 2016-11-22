#ifndef ___GRIDWORLD_H___
#define ___GRIDWORLD_H___

#include <vector>
#include "cell.h"

class GridWorld
{
private:
    int width;
    int goalX;
    int goalY;
    std::vector<std::vector<Cell> > grid;

public:
    GridWorld(int n);

    void setGoal();
    int getGoalX();
    int getGoalY();
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell cell);
    // void calcProbability();

    void printGrid();
    void printProb();
};

#endif
