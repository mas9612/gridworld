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

double Cell::getProbUp()
{
    return this->probUp;
}

double Cell::getProbDown()
{
    return this->probDown;
}

double Cell::getProbRight()
{
    return this->probRight;
}

double Cell::getProbLeft()
{
    return this->probLeft;
}

void Cell::setProbUp(double probUp)
{
    this->probUp = probUp;
}

void Cell::setProbDown(double probDown)
{
    this->probDown = probDown;
}

void Cell::setProbRight(double probRight)
{
    this->probRight = probRight;
}

void Cell::setProbLeft(double probLeft)
{
    this->probLeft = probLeft;
}

void Cell::calcProbability()
{
    double sum = this->up + this->down + this->right + this->left;
    this->probUp = this->up / sum;
    this->probDown = this->down / sum;
    this->probRight = this->right / sum;
    this->probLeft = this->left / sum;
}
