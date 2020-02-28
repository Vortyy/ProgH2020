/*
 * Auteur: Étienne Ménard
 * Date 21/02/2020
 * Fichier: rectangle.cpp
 */

#include "rectangle.h"

// constructeur sans paramètres
rectangle::rectangle() {
    _w = _h = 0;
}

// constructeur avec paramètres
rectangle::rectangle(int x, int y, int w, int h) {
    _coord.setPosition(x,y);
    setW(w);
    setH(h);
}

// destructeur
rectangle::~rectangle() {
    _w = _h = 0;
}

// getteur de la position du point
Point rectangle::getPosition()const {
    return _coord;
}

// getteur de la largeur
int rectangle::getW()const {
    return _w;
}

//getteur de la hauteur
int rectangle::getH()const {
    return _h;
}

// set la valeur de x
void rectangle::setX(int x) {
    _coord.setX(x);
}

// set la valeur de y
void rectangle::setY(int y) {
    _coord.setY(y);
}

// set la valeur de w
void rectangle::setW(int w) {
    assert(w >= 0);
    _w = w;
}

// set la valeur de h
void rectangle::setH(int h) {
    assert(h >= 0);
    _h = h;
}

// set les valeurs de la coordonnées
void rectangle::setPosition(int x, int y) {
    _coord.setPosition(x, y);
}

// set les valeurs de la coordonnées, de la hauteur et de la largeur du rectangle
void rectangle::setRectangle(int x, int y, int w, int h) {
    setPosition(x, y);
    setW(w);
    setH(h);
}

// lis les valeurs entrées de l'utilisateur commme ceci: (x,y) w x h
void rectangle::read(istream& input) {
    char skip;
    input >>  _coord >> _w >> skip >> _h;
}

// prints les valeurs du rectangle comme ceci: (x,y) w x h
void rectangle::print(ostream& output)const {
    output << _coord << " " << _w << " x " << _h;
}

// Surcharge des opérateurs d'IO
istream& operator>>(istream& input, rectangle& r) {
    r.read(input);
    return input;
}
ostream& operator<<(ostream& output, const rectangle& r) {
    r.print(output);
    return output;
}

// calcul de la surface du rectangle
int rectangle::surface()const {
    return _w * _h;
}

// calcul du perimètre
int rectangle::perimetre()const {
    return _w * 2 + _h * 2;
}

// Surcharge des opérateurs bool
bool rectangle::operator==(const rectangle& r)const {
    if (_w == r._w && _h == r._h)
        return true;
    else
        return false;
}
bool rectangle::operator!=(const rectangle& r)const {
    if (_w == r._w && _h == r._h)
        return false;
    else
        return true;
}
bool rectangle::operator<(const rectangle& r)const {
    if (perimetre() < r.perimetre())
        return true;
    else
        return false;
}
bool rectangle::operator<=(const rectangle& r)const {
    if (perimetre() <= r.perimetre())
        return true;
    else
        return false;
}
bool rectangle::operator>(const rectangle& r)const {
    if (perimetre() > r.perimetre())
        return true;
    else
        return false;
}
bool rectangle::operator>=(const rectangle& r)const {
    if (perimetre() >= r.perimetre())
        return true;
    else
        return false;
}

// Dessine un rectangle
void rectangle::draw(ostream& output)const {
    char charactere = '#';
    // ligne du dessus
    for (int i = 0; i < _w; i++) {
        gotoxy(_coord.getX() + i, _coord.getY());
        output << charactere;
    }
    for (int i = 1; i < _h; i++) {
        gotoxy(_coord.getX(), _coord.getY() + i);
        output << charactere;
        gotoxy(_coord.getX() + _w - 1, _coord.getY() + i);
        output << charactere;
    }
    for (int i = 1; i < _w - 1; i++) {
        gotoxy(_coord.getX() + i, _coord.getY() + _h - 1);
        output << charactere;
    }
}

//change la couleur de la forme
void rectangle::color(int nb) {
    switch (nb) {
    case 1:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_RED);
        break;
    case 2:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
        break;
    case 3:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
        break;
    case 4:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
        break;
    case 5:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
    case 6:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_GREEN);
        break;
    case 7:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
        break;
    case 8:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE);
        break;
    case 9:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
        break;
    case 10:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY);
        break;
    }
    
}

void rectangle::setDimensions(int w, int h) {
    setW(w);
    setH(h);
}