#ifndef ___CELL_H___
#define ___CELL_H___

class Cell
{
private:
    double up;
    double down;
    double right;
    double left;

    double p_up;
    double p_down;
    double p_right;
    double p_left;

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

    double getP_up();
    double getP_down();
    double getP_right();
    double getP_left();
    void setP_up(double p_up);
    void setP_down(double p_down);
    void setP_right(double p_right);
    void setP_left(double p_left);

    void calcProbability();
};

#endif

