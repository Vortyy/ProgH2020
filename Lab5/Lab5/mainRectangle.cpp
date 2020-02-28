/*
 * Auteur: �tienne M�nard
 * Date 21/02/2020
 * Fichier: mainRectangle.cpp
 * But: Exercice avec les classes
 */

#include <iostream>
#include "rectangle.h"
using namespace std;

void mainRectangle() {
    rectangle r1, r2;
    cout << "Entrer les coordonnees d'un rectangle, sa largeur et hauteur : (x,y) w x h ";
    r1.read(cin); //saisie les infos comme ceci: (x,y) w x h. appel read de point
    cout << "Entrer les coordonnees d'un rectangle, sa largeur et hauteur : (x, y) w x h ";
    cin >> r2; //fonction operator>> qui appel read
    cout << endl;
    r1.print(cout); //on l�affiche comme ceci: (x,y) de h x w. appel print de point
    cout << endl << r2; //fonction operator<< qui appel print
    cout << endl;

    r2.draw(cout); //on dessine le contour du rectangle (choisir un caract�res)
    //selon w et h a la position (x,y) en console
    cout << endl;

    cout << "Surface: " << r2.surface() << endl << "Perimetre: " << r2.perimetre(); //calcul l�air et le p�rim�tre du rectangle
    //surcharge de l�operator== qui compare les coordonn�es et dimensions des rectangles
    if (r1 == r2) cout << endl << "Les rectangles sont identiques";
    else cout << endl << "Les rectangles ne sont pas identiques";
    //surcharger aussi l�operator!=
    //surcharge de l�operator< qui compare la taille (air ou p�rim�tre) des rectangles
    if (r1 < r2) cout << endl << "r1 est plus petit que r2";
    else cout << endl << "r1 est plus grand que r2";
    //surcharger aussi l�operator>, >=, <=
    cout << endl;
    
    system("pause");
}