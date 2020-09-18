#ifndef BOT_H
#define BOT_H

/* Imports */
#include<GLFW/glfw3.h>

#include"car.cpp"

using namespace std;

class Bot : public Car{
public:

    void move(GLFWwindow* window) {

        if (glfwGetKey(window, GLFW_KEY_A)) {
            angle = angle + turn;
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            angle = angle - turn;
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            if (speed < ftopspeed) {
                speed = speed + accleration;
            } else {
                speed = ftopspeed;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            if (speed > btopspeed) {
                speed = speed - accleration;
            } else {
                speed = btopspeed;
            }
        }
    }
};

#endif