#ifndef VISUALS_H
#define VISUALS_H

/* Imports */
#include<math.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<iostream>

#include"util.cpp"

void render_quadrilatral(Quadrilateral body) {
    glBegin(GL_TRIANGLES);
        glVertex2f(body.cs[0].x, body.cs[0].y);
        glVertex2f(body.cs[1].x, body.cs[1].y);
        glVertex2f(body.cs[2].x, body.cs[2].y);
        glVertex2f(body.cs[0].x, body.cs[0].y);
        glVertex2f(body.cs[2].x, body.cs[2].y);
        glVertex2f(body.cs[3].x, body.cs[3].y);
    glEnd();
}

void render_triangle(Triangle body) {
    /* Draw triangles based on coords */
    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; i++){
            glVertex2f(body.cs[i].x, body.cs[i].y);
        }
    glEnd();
}

void render_all(Car* player, vector<Car*> bot, vector<Obstacle*> walls) {

    render_quadrilatral(player -> body);

    for (int i=0; i<bot.size(); i++){
        render_quadrilatral(bot[i] -> body);
    }

    for (int i=0; i<walls.size(); i++){
        render_triangle(walls[i] -> body);
    }
}

#endif