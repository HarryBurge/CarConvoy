#ifndef VISUALS_H
#define VISUALS_H

/* Imports */
#include<math.h>
#include<GLFW/glfw3.h>

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
            glVertex2f(xs[i], ys[i]);
        }
    glEnd();
}

void render_all(Player player, Bot bot, Obstacle walls[]) {
    render_rectangle(player.x, player.y, player.angle, player.width, player.height);
    render_rectangle(bot.x, bot.y, bot.angle, bot.width, bot.height);
    render_triangle(walls[0].xs, walls[0].ys);
}

#endif