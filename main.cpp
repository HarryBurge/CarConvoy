/* Imports */
#include<iostream>
#include<math.h>
#include<GLFW/glfw3.h>

#include"player.cpp"
#include"bot.cpp"
#include"obstacle.cpp"

using namespace std;

/* Constants */
const double pi = 2*acos(0.0);

void render_rectangle(float x, float y, float angle, float width, float height) {

    /* Generate rectangle corners */
    float xs[4] = {x-width/2, x+width/2, x+width/2, x-width/2};
    float ys[4] = {y+height/2, y+height/2, y-height/2, y-height/2};

    /* Rotate rectangle corners around center */
    for (int i = 0; i < 4; i++){
        float px = xs[i];
        float py = ys[i];
        xs[i] = cos(angle)*(px-x) - sin(angle)*(py-y) + x;
        ys[i] = sin(angle)*(px-x) + cos(angle)*(py-y) + y;
    }

    /* Draw two triangles to make rectangle */
    glBegin(GL_TRIANGLES);
        glVertex2f(xs[0], ys[0]);
        glVertex2f(xs[1], ys[1]);
        glVertex2f(xs[2], ys[2]);
        glVertex2f(xs[3], ys[3]);
        glVertex2f(xs[2], ys[2]);
        glVertex2f(xs[0], ys[0]);
    glEnd();
}

void render_triangle(float xs[3], float ys[3]) {
    /* Draw triangles based on coords */
    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++){
            cout << xs[i];
            cout << ' ';
            cout << ys[i] << endl;
            glVertex2f(xs[i], ys[i]);
        }
    glEnd();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int visuals() {
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


    /* Create Car */
    Player player;
    Bot bot;

    float ax[3] = {0.1, 0.2, 0.2};
    float ay[3] = {0.2, 0.1, 0.2};
    Obstacle wall = Obstacle(ax, ay);

    /* Move bot out of player */
    bot.x = -0.4;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // ----- Things to render
        player.move(window);
        player.calculate_car_frame(window);

        bot.move(window);
        bot.calculate_car_frame(window);

        render_rectangle(player.x, player.y, player.angle, 0.2, 0.1);
        render_rectangle(bot.x, bot.y, bot.angle, 0.1, 0.05);
        render_triangle(wall.xs, wall.ys);
        // -----

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int main() {
    visuals();
    return 0;
}