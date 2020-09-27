#ifndef CAR_H
#define CAR_H

#include<GLFW/glfw3.h>
#include<math.h>

#include"../util.cpp"

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
    Quadrilateral body;
    float angle = 0;
    float speed = 0;

    Car(float x, float y, float angle, float width = 0.2, float height = 0.1) {
        float xs[4];
        float ys[4];

        xs[0] = x - width/2;
        xs[1] = x + width/2;
        xs[2] = x + width/2;
        xs[3] = x - width/2;

        ys[0] = y + height/2;
        ys[1] = y + height/2;
        ys[2] = y - height/2;
        ys[3] = y - height/2;

        body = Quadrilateral(xs, ys, x, y);

        rotate_car_by(angle);
    }

    virtual void move(GLFWwindow* window){}

    void rotate_car_by(float dangle){
        angle += dangle;
        body.rotate_quad_by(dangle);
    }

    void calculate_car_frame() {

        body.translate_quad_by(speed*cos(angle), speed*sin(angle));
        
        if (speed > deaccleration) {
            speed -= deaccleration;
        } else if (speed < -deaccleration) {
            speed += deaccleration;
        } else {
            speed = 0;
        }
    }

};

#endif