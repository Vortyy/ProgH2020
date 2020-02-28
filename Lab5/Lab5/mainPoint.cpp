/*
 * Auteur: Étienne Ménard
 * Date 18/02/2020
 * Fichier: mainPoint.cpp
 * But: Exercice avec les classes
 */

#include <iostream>
#include "point.h"
using namespace std;

void oldmain() {
    Point p1, p2;

    cout << "Entrer les coordonnees d'un point (x,y): ";
    p1.read(cin);
    cout << endl;

    cout << "Entrer les coordonnees d'un point (x,y): ";
    p2.read(cin);
    cout << endl;

    p1.print(cout); //on affiche les coordonnées comme ceci: (x,y)
    cout << endl << p2; //fonction operator<< qui appel print

    //surcharge de l’operator== qui compare 2 points
    if (p1 == p2)
        cout << endl << "Les coordonnees sont identiques" << endl << endl;
    else
        cout << endl << "Les coordonnees ne sont pas identiques" << endl << endl;
    //surcharger aussi l’operator!=

    cout << p1 + p2; //surcharge de l’operator+ qui retourne un point par valeur
    cout << p1 - p2; //surcharge de l’operator- qui retourne un point par valeur
    cout << distance(p1, p2) << endl; //retourne la distance entre les 2 points

    p1.draw(cout);
    system("pause");
}