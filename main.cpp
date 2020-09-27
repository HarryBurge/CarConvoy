#ifndef MAIN_H
#define MAIN_H

/* Imports */
#include<math.h>
#include<GLFW/glfw3.h>
#include<vector>

#include"sprites/car.cpp"
#include"sprites/player.cpp"
#include"sprites/bot.cpp"
#include"static_sprites/obstacle.cpp"

#include"visuals.cpp"
#include"control.cpp"

using namespace std;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


int frame_loop(GLFWwindow* window, Car* player, vector<Car*> bot, vector<Obstacle*> walls) {
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
    Car* player = new Player(0,0, 0);
    vector<Car*> bot(1, new Bot(0,0.4, 0));

    /* Create obstacles */
    float ax[3] = {0.2, 0.4, 0.4};
    float ay[3] = {0.4, 0.2, 0.4};
    
    float ax2[3] = {-0.2, -0.4, -0.4};
    float ay2[3] = {-0.4, -0.2, -0.4};
    vector<Obstacle*> walls(2, new Obstacle(ax, ay));

    walls[1] = new Obstacle(ax2, ay2);

    /* The main control loop */
    frame_loop(window, player, bot, walls);

    glfwTerminate();
    delete player;
    delete bot[0];
    delete walls[0];
    return 0;
}

#endif