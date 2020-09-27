#ifndef CONTROL_H
#define CONTROL_H

#include"sprites/player.cpp"
#include"sprites/bot.cpp"
#include"static_sprites/obstacle.cpp"


void step_frame(GLFWwindow* window, Car* player, vector<Car*> bot, vector<Obstacle*> walls) {

    player -> move(window);

    // bool collided = false;

    // for (int i=0; i<4; i++){

    //     for (int j=0; j<walls.size(); j++){
    //         if (walls[j] -> body.coord_in_triangle(player -> body.cs[i])){
    //             collided = true;
    //         }
    //     }
    // }

    // Need to do collisions between bots and walls then bots and players and bots and bots

    // if (collided){
    //     player -> speed = 0;
    // }

    /* Player Collision checks */
    for (int i=0; i<4; i++){

        // Walls check
        for (int j=0; j<walls.size(); j++){
            if (walls[j] -> body.coord_in_triangle(player -> body.cs[i])){
                player -> speed = 0;
            }
        }

        // Bots check
        for (int j=0; j<bot.size(); j++){
            if (bot[j] -> body.coord_in_quadrilateral(player -> body.cs[i])){
                player -> speed = 0;
            }
        }
    }

    player -> calculate_car_frame();

    // bot[0] -> move(window);
    bot[0] -> calculate_car_frame();
}

#endif