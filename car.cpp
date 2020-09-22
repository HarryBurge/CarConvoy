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

    virtual void move(GLFWwindow* window){}

    void calculate_car_frame(GLFWwindow* window, Car* car) {

        car -> x += speed*cos(angle);
        car -> y += speed*sin(angle);
        
        if (car -> speed > deaccleration) {
            car -> speed -= deaccleration;
        } else if (car -> speed < -deaccleration) {
            car -> speed += deaccleration;
        } else {
            car -> speed = 0;
        }
    }

    float* x_corners(Car* car){
        /* Generate rectangle corners */
        float* xs = new float[4];

        xs[0] = car -> x -width/2;
        xs[1] = car -> x+width/2;
        xs[2] = car -> x+width/2;
        xs[3] = car -> x-width/2;

        float* ys = new float[4];

        ys[0] = y + height/2;
        ys[1] = car -> y + height/2;
        ys[2] = car -> y - height/2;
        ys[3] = car -> y - height/2;

        for (int i = 0; i < 4; i++){
            xs[i] = cos(angle) * (xs[i]-x) - sin(angle) * (ys[i]-y) + x;
        }

        return xs;
    }

    float* y_corners(Car* car){
        /* Generate rectangle corners */
        float* xs = new float[4];

        xs[0] = car -> x -width/2;
        xs[1] = car -> x+width/2;
        xs[2] = car -> x+width/2;
        xs[3] = car -> x-width/2;

        float* ys = new float[4];

        ys[0] = y + height/2;
        ys[1] = car -> y + height/2;
        ys[2] = car -> y - height/2;
        ys[3] = car -> y - height/2;

        for (int i = 0; i < 4; i++){
            ys[i] = sin(angle) * (xs[i]-x) + cos(angle) * (ys[i]-y) + y;
        }

        return ys;
    }
};

#endif