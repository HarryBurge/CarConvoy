#ifndef UTIL_H
#define UTIL_H

/* Imports */
#include<math.h>
#include<iostream>

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

    /*
    static float area(Coord c1, Coord c2, Coord c3, Coord c4) { 
        float a = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2)); //c1 - c2
        float b = sqrt(pow(c2.x - c3.x, 2) + pow(c2.y - c3.y, 2)); //c2 - c3
        float c = sqrt(pow(c3.x - c4.x, 2) + pow(c3.y - c4.y, 2)); //c3 - c4
        float d = sqrt(pow(c4.x - c1.x, 2) + pow(c4.y - c1.y, 2)); //c4 - c1

        float fake_side = sqrt(pow(c4.x - c2.x, 2) + pow(c4.y - c2.y, 2)); //c4 - c2

        float c1_theta = acos((a*a + d*d - fake_side*fake_side) / (2 * a * d));
        float c3_theta = acos((b*b + c*c - fake_side*fake_side) / (2 * b * c));

        return 0.5 * a * d * sin(c1_theta) + 0.5 * b * c * sin(c3_theta);
    }

    bool coord_in_quadrilateral(Coord coord){
        float A = area(cs[0], cs[1], cs[2], cs[3]); 
            
        float A1 = area(coord, cs[1], cs[2], cs[3]);  
        float A2 = area(cs[0], coord, cs[2], cs[3]);   
        float A3 = area(cs[0], cs[1], coord, cs[3]); 
        float A4 = area(cs[0], cs[1], cs[2], coord);

        cout << A << " " << A1 << "  " << A2 << "  " << A3 << "  " << A4 << endl;
            
        return (A == A1 + A2 + A3 + A4); 
    }
    */

   bool coord_in_quadrilateral(Coord coord){
       float xt012[3] = {cs[0].x, cs[1].x, cs[2].x};
       float yt012[3] = {cs[0].y, cs[1].y, cs[2].y};
       
       float xt023[3] = {cs[0].x, cs[2].x, cs[3].x};
       float yt023[3] = {cs[0].y, cs[2].y, cs[3].y};

       Triangle t012 = Triangle(xt012, yt012);
       Triangle t023 = Triangle(xt023, yt023);

       if (t012.coord_in_triangle(coord) || t023.coord_in_triangle(coord)){
           return true;
       }

       return false;
   }
};

#endif