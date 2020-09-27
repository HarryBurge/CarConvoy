#ifndef UTIL_H
#define UTIL_H

/* Imports */
#include<math.h>

using namespace std;


class Coord{
public:

    float x;
    float y;

    Coord(){}

    Coord(float tx, float ty){
        x = tx;
        y = ty;
    }

    void rotate_around_another_coord(Coord c, float angle){
        y = sin(angle) * (x-c.x) + cos(angle) * (y-c.y) + c.y;
        x = cos(angle) * (x-c.x) - sin(angle) * (y-c.y) + c.x;
    }

    void translate_coord_by(float dx, float dy){
        x += dx;
        y += dy;
    }

};


class Quadrilateral{
public:

    Coord cs[4];
    Coord center;

    Quadrilateral(){}

    Quadrilateral(float xs[4], float ys[4], float cx, float cy){

        center = Coord(cx, cy);

        for (int i=0; i<4; i++){
            cs[i] = Coord(xs[i], ys[i]);
        }
    }

    void rotate_quad_by(float dangle){
        for (int i=0; i<4; i++){
            cs[i].rotate_around_another_coord(center, dangle);
        }
    }

    void translate_quad_by(float dx, float dy){
        center.translate_coord_by(dx, dy);

        for (int i=0; i<4; i++){
            cs[i].translate_coord_by(dx, dy);
        }
    }
};


class Triangle{
public:

    Coord cs[3];
    Coord center;

    Triangle(){}

    Triangle(float xs[3], float ys[3]){

        float sumx = 0;
        float sumy = 0;

        for (int i=0; i<3; i++){
            cs[i] = Coord(xs[i], ys[i]);
            sumx += xs[i];
            sumy += ys[i];
        }

        center = Coord(sumx/3, sumy/3);
    }

    Triangle(float xs[3], float ys[3], float cx, float cy){

        center = Coord(cx, cy);

        for (int i=0; i<3; i++){
            cs[i] = Coord(xs[i], ys[i]);
        }
    }

    static float area(Coord c1, Coord c2, Coord c3) { 
        return abs((c1.x*(c2.y-c3.y) + c2.x*(c3.y-c1.y)+ c3.x*(c1.y-c2.y))/2.0);
    }

    bool coord_in_triangle(Coord coord) {    
        float A = area(cs[0], cs[1], cs[2]); 
            
        float A1 = area(coord, cs[1], cs[2]);  
        float A2 = area(cs[0], coord, cs[2]);   
        float A3 = area(cs[0], cs[1], coord); 
            
        return (A == A1 + A2 + A3); 
    }

};

#endif