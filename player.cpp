#ifndef PLAYER_H
#define PLAYER_H

/* Imports */
#include<GLFW/glfw3.h>

#include"car.cpp"
#include<iostream>

using namespace std;

class Player : public Car{
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