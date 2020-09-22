#ifndef MAIN_H
#define MAIN_H

/* Imports */
#include<math.h>
#include<GLFW/glfw3.h>

#include"car.cpp"
#include"player.cpp"
#include"bot.cpp"
#include"obstacle.cpp"

#include"visuals.cpp"
#include"control.cpp"

using namespace std;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


int frame_loop(GLFWwindow* window, Car* player, Car* bot[], Obstacle walls[]) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        /* Does all the behind the scenes calculation */
        step_frame(window, player, bot, walls);

        /* Draws the frame */
        render_all(player, bot, walls);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}


int main() {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "CarConvoy", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    /* Create cars */
    Car* player = new Player;
    Car* bot[1] = {new Bot};

    /* Create obstacles */
    float ax[3] = {0.2, 0.4, 0.4};
    float ay[3] = {0.4, 0.2, 0.4};
    Obstacle walls[1] = {Obstacle(ax, ay)};

    /* Move bot out of player */
    // bot.x = -0.4;

    /* The main control loop */
    frame_loop(window, player, bot, walls);

    glfwTerminate();
    delete player;
    delete bot[0];
    return 0;
}

#endif