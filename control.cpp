#ifndef CONTROL_H
#define CONTROL_H

#include<iostream>

#include"player.cpp"
#include"bot.cpp"
#include"obstacle.cpp"

float sign(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) {
    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

bool PointInTriangle(float x, float y, float xs[3], float ys[3]) {

    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(x,y, xs[0],ys[0], xs[1],ys[1]);
    d2 = sign(x,y, xs[1],ys[1], xs[2],ys[2]);
    d3 = sign(x,y, xs[2],ys[2], xs[0],ys[0]);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

void step_frame(GLFWwindow* window, Player* player, Bot* bot, Obstacle walls[]) {

    bool collided = false;

    //Check player collided with wall
    for (int i = 0; i < 4; i++) {
        if (PointInTriangle(player -> xs_of_object()[i], player -> ys_of_object()[i], walls[0].xs, walls[0].ys)) {
            collided = true;
        }
    }

    if (!collided) {
        player -> move(window);
        player -> calculate_car_frame(window);
    } else {
        player -> move(window);
        player -> speed = 0;
    }

    bot -> move(window);
    bot -> calculate_car_frame(window);
}

#endif