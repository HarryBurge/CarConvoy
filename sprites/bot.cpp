#ifndef BOT_H
#define BOT_H

/* Imports */
#include<GLFW/glfw3.h>

#include"car.cpp"

using namespace std;

class Bot : public Car{
public:

    Bot(float x, float y, float angle, float width = 0.2, float height = 0.1)
    : Car(x, y, angle, width, height)
    {
        
    }

    void move(GLFWwindow* window) {

        if (glfwGetKey(window, GLFW_KEY_A)) {
            rotate_car_by(turn);
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            rotate_car_by(-turn);
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            if (speed < ftopspeed) {
                speed += accleration;
            } else {
                speed = ftopspeed;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            if (speed > btopspeed) {
                speed -= accleration;
            } else {
                speed = btopspeed;
            }
        }
    }
};

#endif