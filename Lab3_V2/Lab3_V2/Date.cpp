#include "Date.h"

//constructeur sans paramètre
Date::Date() {
	_jour = _mois = 1;
	_annee = 1900; //initialisons la date à 01/01/1900
}
//constructeur avec paramètres
Date::Date(int jour, int mois, int annee) {
	setDate(jour, mois, annee);
}

//définition du destructeur qui reset (nettoie) le contenu des propriétés
Date::~Date() {
	_jour = 0;
	_mois = 0;
	_annee = 0;
}

//définition du getteur qui retourne le jour
int Date::getJour()const {
	return _jour;
}

//définition du getteur qui retourne le mois
int Date::getMois()const {
	return _mois;
}

//définition du getteur qui retourne l'année
int Date::getAnnee()const {
	return _annee;
}

//get les 3 paramètres
Date Date::getDate() const{
	return *this; //this est un pointeur vers l’objet, *this est l’objet
}

//définition du setteur qui reçoit un int et modifie le jour
void Date::setJour(int jour) {
	assert(jour >= 1 && jour <= 31); //robustesse avec <cassert>
	_jour = jour;
}

//définition du setteur qui reçoit un int et modifie le mois
void Date::setMois(int mois) {
	assert(mois >= 1 && mois <= 12); //robustesse avec <cassert>
	_mois = mois;
}

//définition du setteur qui reçoit un int et modifie l'année
void Date::setAnnee(int annee) {
	assert(annee >= 1900); //robustesse avec <cassert>
	_annee = annee;
}

// setter les 3 paramètres en même temps
void Date::setDate(int jour, int mois, int annee) {
	setJour(jour);
	setMois(mois);
	setAnnee(annee);
}

// génère un objet avec la date d'aujourd'hui
void Date::setToday() {
	struct tm newtime;				// Structure tm qui contiendra la date du jour
	time_t now = time(NULL);		// now contient le nombre de secondes depuis le 01-01-1970.
	localtime_s(&newtime, &now);	// fait la conversion de now en structure tm

	_jour = newtime.tm_mday;
	_mois = newtime.tm_mon + 1;
	_annee = newtime.tm_year + 1900;
}

// print la date en format "jj/mm/aaaa"
void Date::print(ostream& output) const{
	output << setw(2) << setfill('0') << _jour << "/" << setw(2) << setfill('0') << _mois << "/" << _annee;
}
