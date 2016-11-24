#ifndef ___CELL_H___
#define ___CELL_H___

class Cell
{
private:
    // reward
    double up;
    double down;
    double right;
    double left;

    // probability
    double probUp;
    double probDown;
    double probRight;
    double probLeft;

public:
    Cell();
    Cell(int up, int down, int right, int left);
    double getUp();
    double getDown();
    double getRight();
    double getLeft();
    void setUp(double up);
    void setDown(double down);
    void setRight(double right);
    void setLeft(double left);

    double getProbUp();
    double getProbDown();
    double getProbRight();
    double getProbLeft();
    void setProbUp(double probUp);
    void setProbDown(double probDown);
    void setProbRight(double probRight);
    void setProbLeft(double probLeft);

    void calcProbability();
};

#endif

