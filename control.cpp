#ifndef CONTROL_H
#define CONTROL_H

#include"sprites/player.cpp"
#include"sprites/bot.cpp"
#include"static_sprites/obstacle.cpp"


void step_frame(GLFWwindow* window, Car* player, Car* bot[], Obstacle* walls[]) {

    player -> move(window);

    bool collided = false;

    for (int i=0; i<4; i++){
        if (walls[0] -> body.coord_in_triangle(player -> body.cs[i])){
            collided = true;
        }
    }

    if (collided){
        player -> speed = 0;
    }

    player -> calculate_car_frame();

    bot[0] -> move(window);
    bot[0] -> calculate_car_frame();
}

#endif