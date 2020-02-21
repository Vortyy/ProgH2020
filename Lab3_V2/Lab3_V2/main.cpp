/*
 * Auteur: Étienne Ménard
 * Date 11/02/2020
 * Fichier: main.cpp
 * But: 
 */

#include "Date.h"
#include "Header.h"

void entrerNaissance(Date& dateNaissance, Date dateJour);
int calcAge(Date dateNaissance, Date dateJour);

void main() {
	Date dateJour; //appel du constructeur sans paramètre
	Date dateNaissance; //appel du constructeur avec 3 paramètres

	dateJour.setToday();
	cout << "Bonjour, aujourd'hui nous sommes le ";
	dateJour.print(cout);
	cout << endl << endl;

	entrerNaissance(dateNaissance, dateJour);

	int age = calcAge(dateNaissance, dateJour);

	if (age < 0) {
		cout << "Vous n'etes pas encore ne" << endl;
	} 
	else
		cout << "Vous avez " << age << " ans" << endl;

	system("pause");
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
// calcule l'age de l'utilisteur
int calcAge(Date dateNaissance, Date dateJour) {
	int age = dateJour.getAnnee() - dateNaissance.getAnnee();

	if (dateNaissance.getMois() > dateJour.getMois())
		age--;

	if (dateNaissance.getMois() == dateJour.getMois() && dateNaissance.getJour() > dateJour.getJour())
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


