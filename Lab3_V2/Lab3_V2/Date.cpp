#include "Date.h"

//constructeur sans param�tre
Date::Date() {
	_jour = _mois = 1;
	_annee = 1900; //initialisons la date � 01/01/1900
}
//constructeur avec param�tres
Date::Date(int jour, int mois, int annee) {
	_jour = jour;
	_mois = mois;
	_annee = annee;
}

//d�finition du destructeur qui reset (nettoie) le contenu des propri�t�s
Date::~Date() {
	_jour = 0;
	_mois = 0;
	_annee = 0;
}

//d�finition du getteur qui retourne le jour
int Date::getJour()const {
	return _jour;
}

//d�finition du getteur qui retourne le mois
int Date::getMois()const {
	return _mois;
}

//d�finition du getteur qui retourne l'ann�e
int Date::getAnnee()const {
	return _annee;
}

//get les 3 param�tres
Date Date::getDate() {
	return *this; //this est un pointeur vers l�objet, *this est l�objet
}

//d�finition du setteur qui re�oit un int et modifie le jour
void Date::setJour(int jour) {
	assert(jour >= 1 && jour <= 31); //robustesse avec <cassert>
	_jour = jour;
}

//d�finition du setteur qui re�oit un int et modifie le mois
void Date::setMois(int mois) {
	assert(mois >= 1 && mois <= 12); //robustesse avec <cassert>
	_mois = mois;
}

//d�finition du setteur qui re�oit un int et modifie l'ann�e
void Date::setAnnee(int annee) {
	assert(annee >= 1900); //robustesse avec <cassert>
	_annee = annee;
}

// setter les 3 param�tres en m�me temps
void Date::setDate(int jour, int mois, int annee) {
	assert(jour >= 1 && jour <= 31); //robustesse avec <cassert>
	_jour = jour;

	assert(mois >= 1 && mois <= 12); //robustesse avec <cassert>
	_mois = mois;

	assert(annee >= 1900); //robustesse avec <cassert>
	_annee = annee;
}

// g�n�re un objet avec la date d'aujourd'hui
void Date::setToday() {
	struct tm newtime;				// Structure tm qui contiendra la date du jour
	time_t now = time(NULL);		// now contient le nombre de secondes depuis le 01-01-1970.
	localtime_s(&newtime, &now);	// fait la conversion de now en structure tm

	_jour = newtime.tm_mday;
	_mois = newtime.tm_mon + 1;
	_annee = newtime.tm_year + 1900;
}

// print la date en format "jj/mm/aaaa"
void printDate(Date date, ostream& output) {
	output << date.getJour() << "/" << date.getMois() << "/" << date.getAnnee();
}

// Rentre la date de naissance de l'utilisateur et loop en cas d'erreur
void entrerNaissance(Date& dateNaissance, Date dateJour) {
	int jour, mois, annee;

	bool inputCorrect;
	do {
		inputCorrect = true;
		cout << "Entrer votre date de naissance (jj mm aaaa) : ";
		cin >> jour >> mois >> annee;

		if (cin.fail()) {
			cout << "La date doit avoir des valeurs numeriques" << endl << endl;
			inputCorrect = false;
		}

		if (jour < 1 || jour > 31) {
			cout << "Le jour doit etre compris entre 1 et 31" << endl << endl;
			inputCorrect = false;
		}

		if (mois < 1 || mois > 12) {
			cout << "Le mois doit etre compris entre 1 et 12" << endl << endl;
			inputCorrect = false;
		}

		if (annee < 1900 || annee > dateJour.getAnnee()) {
			cout << "L'annee doit etre compris entre 1900 et " << dateJour.getAnnee() << endl << endl;
			inputCorrect = false;
		}

		viderBuffer();

	} while (!inputCorrect);

	dateNaissance.setDate(jour, mois, annee);
}