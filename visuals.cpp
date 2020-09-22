#ifndef VISUALS_H
#define VISUALS_H

/* Imports */
#include<math.h>
#include<GLFW/glfw3.h>

void render_rectangle(float xs[4], float ys[4]) {
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
            glVertex2f(xs[i], ys[i]);
        }
    glEnd();
}

void render_all(Car* player, Car* bot[], Obstacle walls[]) {
    auto xs = player -> x_corners(player);
    auto ys = player -> y_corners(player);

    render_rectangle(player -> x_corners(player), player -> y_corners(player));
    cout << "x = " << player -> x << " y = " << player -> y << " angle = " << player -> angle << " speed = " << player -> speed << endl;

    // cin.get();
    // render_rectangle(bot -> x_corners(bot), bot -> y_corners(bot));
    render_triangle(walls[0].xs, walls[0].ys);
}

#endif