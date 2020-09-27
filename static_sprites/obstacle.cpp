#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../util.cpp"

using namespace std;

class Obstacle{
public:
    /* Obstacle attributes */
    float angle = 0;
    Triangle body;

    Obstacle(float xs[3], float ys[3]) {
        body = Triangle(xs, ys);
    }
};

#endif