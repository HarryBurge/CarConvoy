/* Imports */
#include<iostream>
#include<math.h>
#include<GLFW/glfw3.h>

#include"car.cpp"

using namespace std;

/* Constants */
const double pi = 2*acos(0.0);

void render_rectangle(float x, float y, float angle, float size_x, float size_y) {

    struct coord {
        float x;
        float y;
    };

    /* Generate rectangle corners */
    coord coords[4] = {
        {x-size_x/2,y+size_y/2}, 
        {x+size_x/2,y+size_y/2}, 
        {x+size_x/2,y-size_y/2}, 
        {x-size_x/2,y-size_y/2}
        };

    /* Rotate rectangle corners around center */
    for (int i = 0; i < 4; i++){
        float px = coords[i].x;
        float py = coords[i].y;
        coords[i] = {cos(angle)*(px-x) - sin(angle)*(py-y) + x, sin(angle)*(px-x) + cos(angle)*(py-y) + y};
    }

    /* Draw two triangles to make rectangle */
    glBegin(GL_TRIANGLES);
        glVertex2f(coords[0].x, coords[0].y);
        glVertex2f(coords[1].x, coords[1].y);
        glVertex2f(coords[2].x, coords[2].y);
        glVertex2f(coords[3].x, coords[3].y);
        glVertex2f(coords[2].x, coords[2].y);
        glVertex2f(coords[0].x, coords[0].y);
    glEnd();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int visuals() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "CarConvoy", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Sets keypress callback */
    glfwSetKeyCallback(window, key_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    /* Create Car */
    Car player;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        player.calculate_car_frame(window);
        render_rectangle(player.sx, player.sy, player.sangle, 0.2, 0.1);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int main() {
    visuals();
    return 0;
}