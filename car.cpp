#ifndef CAR_H
#define CAR_H

#include<GLFW/glfw3.h>
#include<iostream>
#include<math.h>

using namespace std;

/* Constants */
const float accleration = 0.0025;
const float deaccleration = 0.0001;
const float ftopspeed = 0.01;
const float btopspeed = -0.005;
const float turn = 2*acos(0.0)/128;

class Car{
public:
    /* Car attributes */
    float x = 0;
    float y = 0;
    float angle = 0;
    float speed = 0;
    float width = 0.2;
    float height = 0.1;

    void calculate_car_frame(GLFWwindow* window) {

        x = x + speed*cos(angle);
        y = y + speed*sin(angle);
        
        if (speed > deaccleration) {
            speed = speed - deaccleration;
        } else if (speed < -deaccleration) {
            speed = speed + deaccleration;
        } else {
            speed = 0;
        }
    }

    float * xs_of_object() {
        /* Generate rectangle corners */
        static float xs[4] = {x-width/2, x+width/2, x+width/2, x-width/2};
        static float ys[4] = {y+height/2, y+height/2, y-height/2, y-height/2};

        /* Rotate rectangle corners around center */
        for (int i = 0; i < 4; i++){
            float px = xs[i];
            float py = ys[i];
            xs[i] = cos(angle)*(px-x) - sin(angle)*(py-y) + x;
            ys[i] = sin(angle)*(px-x) + cos(angle)*(py-y) + y;
        }

        return xs;
    }

    float * ys_of_object() {
        /* Generate rectangle corners */
        static float xs[4] = {x-width/2, x+width/2, x+width/2, x-width/2};
        static float ys[4] = {y+height/2, y+height/2, y-height/2, y-height/2};

        /* Rotate rectangle corners around center */
        for (int i = 0; i < 4; i++){
            float px = xs[i];
            float py = ys[i];
            xs[i] = cos(angle)*(px-x) - sin(angle)*(py-y) + x;
            ys[i] = sin(angle)*(px-x) + cos(angle)*(py-y) + y;
        }

        return ys;
    }
};

#endif