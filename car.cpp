/* Imports */
#include<iostream>
#include<math.h>
#include<GLFW/glfw3.h>

using namespace std;

/* Constants */
const float accleration = 0.005;
const float deaccleration = 0.0001;
const float ftopspeed = 0.01;
const float btopspeed = -0.005;
const float turn = 2*acos(0.0)/128;

class Car{
public:
    /* Car attributes */
    float sx = 0;
    float sy = 0;
    float sangle = 0;
    float sspeed = 0;

    void calculate_car_frame(GLFWwindow* window) {

        if (glfwGetKey(window, GLFW_KEY_A)) {
            sangle = sangle + turn;
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            sangle = sangle - turn;
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            if (sspeed < ftopspeed) {
                sspeed = sspeed + accleration;
            } else {
                sspeed = ftopspeed;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            if (sspeed > btopspeed) {
                sspeed = sspeed - accleration;
            } else {
                sspeed = btopspeed;
            }
        }

        sx = sx + sspeed*cos(sangle);
        sy = sy + sspeed*sin(sangle);
        
        if (sspeed > deaccleration) {
            sspeed = sspeed - deaccleration;
        } else if (sspeed < -deaccleration) {
            sspeed = sspeed + deaccleration;
        } else {
            sspeed = 0;
        }
    }
};