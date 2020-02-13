/*
 * Auteur: �tienne M�nard
 * Date 11/02/2020
 * Fichier: main.cpp
 * But: 
 */

#include "Date.h"
#include "Header.h"

int calcAge(Date dateNaissance, Date dateJour);

void main() {
	Date dateJour; //appel du constructeur sans param�tre
	Date dateNaissance; //appel du constructeur avec 3 param�tres

	dateJour.setToday();
	cout << "Bonjour, aujourd'hui nous sommes le ";
	printDate(dateJour, cout);
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
	cin.clear(); //on reset le flux pour que la suite parte d�un flux valide
	cin.seekg(0, ios::end);//se place � la fin, si �a marche, non vide
	if (!cin.fail()) //Le flux est valide, donc le buffer est non vide
		cin.ignore(numeric_limits<streamsize>::max());
	else //Le flux est invalide, donc le buffer est vide
		cin.clear();
	// Le flux est dans un �tat invalide donc on le remet en �tat valide
}

// fais pause
void pause()
{
	viderBuffer();
	cin.ignore(numeric_limits<streamsize>::max());
}


