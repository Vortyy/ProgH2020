/*
 * Auteur: Étienne Ménard
 * Date 18/02/2020
 * Fichier: point.h
 */

#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include <Windows.h>
using namespace std;

class Point {
    private:
        int _x, _y;

    public:
        Point(int =0, int =0);
        ~Point(); // Destructeur
        Point(const Point& p); // Copieur

        // Opérateurs surchargés
        const Point& operator=(const Point& p);
        Point operator+(const Point& p)const;
        Point operator-(const Point& p)const;
        bool operator==(const Point& p)const;        
        bool operator!=(const Point& p)const;
        
        // Getteurs
        int getX()const;
        int getY()const;

        // Setteurs
        void setX(int x);
        void setY(int y);
        void setPosition(int x, int y);

        // Autres méthodes
        void print(ostream& output)const;
        void read(istream& input);
        void draw(ostream& output)const;
        friend double distance(const Point& p1, const Point& p2); 
};
// Surcharge des opérateurs d'IO
ostream& operator<<(ostream& output,const Point& p);
istream& operator>>(istream& input, Point& p);
void gotoxy(int xpos, int ypos);