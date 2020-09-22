#ifndef CONTROL_H
#define CONTROL_H

#include<iostream>

#include"player.cpp"
#include"bot.cpp"
#include"obstacle.cpp"


float area(float x1, float y1, float x2, float y2, float x3, float y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  

bool PointInTriangle(float x, float y, float xs[3], float ys[3]) 
{    
   float A = area (xs[0], ys[0], xs[1], ys[1], xs[2], ys[2]); 
     
   float A1 = area (x, y, xs[1], ys[1], xs[2], ys[2]);  
   float A2 = area (xs[0], ys[0], x, y, xs[2], ys[2]);   
   float A3 = area (xs[0], ys[0], xs[1], ys[1], x, y); 
    
   return (A == A1 + A2 + A3); 
}


void step_frame(GLFWwindow* window, Car* player, Car* bot[], Obstacle walls[]) {

    player -> move(window);

    bool collided = false;

    auto pxs = player -> x_corners(player);
    auto pys = player -> y_corners(player);

    for (int i = 0; i < 4; i++){
        if (PointInTriangle(pxs[i], pys[i], walls -> xs, walls -> ys)){
            collided = true;
        }
    }

    if (collided){
        player -> speed = 0;
    }

    player -> calculate_car_frame(window, player);

    bot[0] -> move(window);
    bot[0] -> calculate_car_frame(window, bot[0]);
}

#endif