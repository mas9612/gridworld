#include "cell.h"

Cell::Cell()
    : up(1), down(1), right(1), left(1)
{
}

Cell::Cell(int up, int down, int right, int left)
    : up(up), down(down), right(right), left(left)
{
}

double Cell::getUp()
{
    return this->up;
}

double Cell::getDown()
{
    return this->down;
}

double Cell::getRight()
{
    return this->right;
}

double Cell::getLeft()
{
    return this->left;
}

void Cell::setUp(double up)
{
    this->up = up;
}

void Cell::setDown(double down)
{
    this->down = down;
}

void Cell::setRight(double right)
{
    this->right = right;
}

void Cell::setLeft(double left)
{
    this->left = left;
}

double Cell::getP_up()
{
    return this->p_up;
}

double Cell::getP_down()
{
    return this->p_down;
}

double Cell::getP_right()
{
    return this->p_right;
}

double Cell::getP_left()
{
    return this->p_left;
}

void Cell::setP_up(double p_up)
{
    this->p_up = p_up;
}

void Cell::setP_down(double p_down)
{
    this->p_down = p_down;
}

void Cell::setP_right(double p_right)
{
    this->p_right = p_right;
}

void Cell::setP_left(double p_left)
{
    this->p_left = p_left;
}

void Cell::calcProbability()
{
    double sum = this->up + this->down + this->right + this->left;
    this->p_up = this->up / sum;
    this->p_down = this->down / sum;
    this->p_right = this->right / sum;
    this->p_left = this->left / sum;
}
