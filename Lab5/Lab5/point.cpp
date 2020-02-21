/*
 * Auteur: Étienne Ménard
 * Date 18/02/2020
 * Fichier: point.cpp
 */

#include "point.h"

// Constructeur avec 2 paramêtres
Point::Point(int x, int y) {
    _x = x;
    _y = y;
}

// Destructeur
Point::~Point() {
    _x = _y = 0;
}

// Copieur par défaut p2(p1)
Point::Point(const Point& p) {
    _x = p._x;
    _y = p._y;
}

// Affectateur p1.operator=(p2)
const Point& Point::operator=(const Point& p) {
    _x = p._x;
    _y = p._y;
    return *this;
}

// addition de 2 coordonnées
Point Point::operator+(const Point& p)const {
    Point resultat;
    resultat._x = _x + p._x;
    resultat._y = _y + p._y;
    return resultat;
}

// soustraction de 2 coordonnées
Point Point::operator-(const Point& p)const {
    Point resultat;
    resultat._x = _x - p._x;
    resultat._y = _y - p._y;
    return resultat;
}

// surcharge de l'opérateur ==
bool Point::operator==(const Point& p)const {
    if (_x == p._x && _y == p._y)
        return true;
    else 
        return false;
}

// surcharge de l'opérateur !=
bool Point::operator!=(const Point& p)const {
    if (_x != p._x && _y != p._y)
        return true;
    else
        return false;
}

// Retourne la coordonnée x
int Point::getX()const {
    return _x;
}

// Retourne la coordonnée y
int Point::getY()const {
    return _y;
}

// Setteur de la valeur x
void Point::setX(int x) {
    assert(x >= 0);
    _x = x;
}

// Setteur de la valeur y
void Point::setY(int y) {
    assert(y >= 0);
    _y = y;
}

// Set les valeurs de x et y
void Point::setPosition(int x, int y) {
    setX(x);
    setY(y);
}

// Lis les coordonnées comme ceci: (x,y)
void Point::read(istream& input) {
    char skip;
    input >> skip >> _x >> skip >> _y >> skip;
}

// Affiche les coordonnées comme ceci: (x,y)
void Point::print(ostream& output)const {
    output << "(" << _x << "," << _y << ")";
}

void Point::draw(ostream& output)const {
    gotoxy(_x, _y);
    cout << "\xFE"; //on dessine un petit carré
}

// calcule la distance entre 2 points
double distance(const Point& p1, const Point& p2) {
    int xAdd = p2._x - p1._x;
    int yAdd = p2._y - p1._y;
    return sqrt(pow(xAdd, 2) + pow(yAdd, 2));
}

// Surcharge des opérateurs d'IO
istream& operator>>(istream& input, Point& p) {
    p.read(input);
    return input;
}
ostream& operator<<(ostream& output, const Point& p) {
    p.print(output);
    return output;
}

//fonction pour se positionner dans l'écran à x,y
void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}