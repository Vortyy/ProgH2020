/*
 * Auteur: Étienne Ménard
 * Date 25/02/2020
 * Fichier: main.cpp
 * But: Exercice avec les classes
 */

#include <iostream>
#include <ctime>
#include "rectangle.h"
using namespace std;

void main() {
    /* initialise le point de départ du random : */
    srand(time(NULL));
    int rng;
    rectangle r1, r2;

    cout << "Entrez les dimensions de votre rectangle (x,y) w x h : ";
    r1.read(cin);

    while (true) {
        /* genere un nombre entre 1 et 10: */
        rng = rand() % 10 + 1;  
        r2.color(rng); // on attribue une couleur pour notre rectangle basée sur le chiffre aléatoire

        // ligne de rectangles
        r2 = r1; // on reset la position initiale de notre r2
        system("cls");
        cout << "Voici une ligne de " << rng << " a la position " << r1.getPosition();
        for (int i = 0; i < rng; i++) {
            r2.setX(r1.getPosition().getX() + (r1.getW() * i));
            r2.draw(cout);        
        }
        cout << endl;
        system("pause");
        
        // triangle de rectangles
        r2 = r1;
        system("cls");
        cout << "Voici un triangle de " << rng << " a la position " << r1.getPosition();
        for (int i = 0; i < rng; i++) {
            r2.setY(r1.getPosition().getY() + (r1.getH() * i));
            for (int j = 0; j < i+1; j++) {
                r2.setX(r1.getPosition().getX() + (r1.getW() * j));
                r2.draw(cout);
            }
        }
        cout << endl;
        system("pause");

        // carré de rectangles
        r2 = r1;
        system("cls");
        cout << "Voici un carre de " << rng << " a la position " << r1.getPosition();
        for (int i = 0; i < rng; i++) {
            r2.setY(r1.getPosition().getY() + (r1.getH() * i));
            for (int j = 0; j < rng; j++) {
                r2.setX(r1.getPosition().getX() + (r1.getW() * j));
                r2.draw(cout);
            }
        }
        cout << endl;
        system("pause");
    }
}