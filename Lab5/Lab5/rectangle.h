/*
 * Auteur: Étienne Ménard
 * Date 21/02/2020
 * Fichier: rectangle.h
 */

#pragma once
#include <iostream>
#include <cassert>
#include "point.h"
using namespace std;

class rectangle {
    private:
        Point _coord;   // coordonnée du coin haut gauche
        int _w;         // largeur
        int _h;         // hauteur

    public:
        rectangle();
        rectangle(int x, int y, int w=0, int h=0);
        ~rectangle();

        // getteurs
        Point getPosition()const;
        int getW()const;
        int getH()const;

        // setteurs
        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        void setPosition(int x, int y);
        void setRectangle(int x, int y, int w, int h);
        void setDimensions(int w, int h);

        // surcharge d'opérateurs
        bool operator==(const rectangle& r)const;
        bool operator!=(const rectangle& r)const;
        bool operator<(const rectangle& r)const;
        bool operator<=(const rectangle& r)const;
        bool operator>(const rectangle& r)const;
        bool operator>=(const rectangle& r)const;

        // autres méthodes
        void read(istream& input);
        void print(ostream& output)const;
        int surface()const;
        int perimetre()const;
        void draw(ostream& output)const;
        void color(int nb);
};
ostream& operator<<(ostream& output, const rectangle& r);
istream& operator>>(istream& input, rectangle& r);
