#ifndef OBSTACLE_H
#define OBSTACLE_H

using namespace std;

class Obstacle{
public:
    /* Obstacle attributes */
    float angle = 0;
    float xs[3];
    float ys[3];

    Obstacle(float x[3], float y[3]) {
        for (int i = 0; i < 3; i++){
            xs[i] = x[i];
            ys[i] = y[i];
        }
    }
};

#endif