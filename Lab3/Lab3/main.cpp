/*
 * Auteur: Étienne Ménard
 * Date 30/01/2020
 * Fichier: main.cpp
 */

#include <iostream>
#include <time.h>
using namespace std;

struct Date { //https://www.learncpp.com/cpp-tutorial/47-structs/
	int jour;
	int mois;
	int annee;
};

Date dateAjd();
Date dateNaissance();
void viderBuffer();
void pause();
int calcAge(Date date);

void main() {
	Date dateJour = dateAjd();	
	int age;

	cout << "Bonjour, aujourd'hui nous sommes le " << dateJour.jour << "/" << dateJour.mois << "/" << dateJour.annee << endl << endl;

	Date dateBirth = dateNaissance();
	age = calcAge(dateBirth);

	if (age < 0) {
		cout << "Vous n'etes pas encore ne" << endl;
	} 
	else
		cout << "Vous avez " << age << " ans" << endl;

	pause();
}

// génère une struct de la date d'aujourd'hui
Date dateAjd() {
	struct tm newtime;				// Structure tm qui contiendra la date du jour
	time_t now = time(NULL);		// now contient le nombre de secondes depuis le 01-01-1970.
	localtime_s(&newtime, &now);	// fait la conversion de now en structure tm

	Date dateJour;
	dateJour.mois = newtime.tm_mon + 1;			// mois (0- 11)
	dateJour.jour = newtime.tm_mday;			// jours (1-31)
	dateJour.annee = newtime.tm_year + 1900;	// Nombre d'années depuis 1900
	return dateJour;
}

// Rentre la date de naissance de l'utilisateur et loop en cas d'erreur
Date dateNaissance() {
	Date naissance;
	Date dateJour = dateAjd();

	bool inputCorrect;
	do {
		inputCorrect = true;
		cout << "Entrer votre date de naissance (jj mm aaaa) : ";
		cin >> naissance.jour >> naissance.mois >> naissance.annee;

		if (cin.fail()) {
			cout << "La date doit avoir des valeurs numeriques" << endl << endl;
			inputCorrect = false;
		}

		if (naissance.jour < 1 || naissance.jour > 31) {
			cout << "Le jour doit etre compris entre 1 et 31" << endl << endl;
			inputCorrect = false;
		}

		if (naissance.mois < 1 || naissance.mois > 12) {
			cout << "Le mois doit etre compris entre 1 et 12" << endl << endl;
			inputCorrect = false;
		}

		if (naissance.annee < 1900 || naissance.jour > dateJour.annee) {
			cout << "L'annee doit etre compris entre 1900 et " << dateJour.annee << endl << endl;
			inputCorrect = false;
		}

		viderBuffer();

	} while (!inputCorrect);

	return naissance;
}

// calcule l'age de l'utilisteur
int calcAge(struct Date birth) {
	Date ajd = dateAjd();
	int age = ajd.annee - birth.annee;

	if (birth.mois > ajd.mois) 
		age--;

	if (birth.mois == ajd.mois && birth.jour > ajd.jour)
		age--;

	return age;
}

//vide le buffer et remet le flux valide
void viderBuffer()
{
	cin.clear(); //on reset le flux pour que la suite parte d’un flux valide
	cin.seekg(0, ios::end);//se place à la fin, si ça marche, non vide
	if (!cin.fail()) //Le flux est valide, donc le buffer est non vide
		cin.ignore(numeric_limits<streamsize>::max());
	else //Le flux est invalide, donc le buffer est vide
		cin.clear();
	// Le flux est dans un état invalide donc on le remet en état valide
}

// fais pause
void pause()
{
	viderBuffer();
	cin.ignore(numeric_limits<streamsize>::max());
}


