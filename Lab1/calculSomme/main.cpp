/*
 Programme: calculSomme.cpp
 Acteur: Julie Gagnon
 Date de création: 21/01/2019
 But du programme: lit des nombres dans un fichier en input, calcul la somme et
 l’affiche en console et dans un fichier en sortie.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>				// librairie pour la manipulation de fichiers
using namespace std;

void siFichierOuvert(ifstream &entree, string fichier);
void siFichierVide(ifstream &entree, string fichier);
void afficherSortie(int nbEtu, int nbEchec, float moyenne, string meilleurEtu, ostream &sortie);

void main()
{
	string nom,
		meilleurEtu,
		fichierEntree = "etudiant.txt",
		fichierSortie = "sortie.txt";

	float note,			// nombre lu dans le fichier
		total = 0,		// total des nombres lu dans le fichier
		moyenne,
		meilleureNote = 0;
	
	int nbEtu = 0,		nbEchec = 0;

	ifstream entree;				//variable ifstream
	entree.open(fichierEntree);		//ouverture du fichier

	ofstream sortie(fichierSortie);	//variable ofstream et ouverture du fichier

	entree >> nom >> note;			//lecture dans le fichier

	siFichierOuvert(entree, fichierEntree);
	siFichierVide(entree, fichierEntree);

	while (entree) {		//tant que le fichier n’est pas la fin
		nbEtu++;
		total += note; 

		if (note < 60) {				// compter les échecs
			nbEchec++;
		}

		if (note > meilleureNote) {		// trouver la meilleure note
			meilleureNote = note;
			meilleurEtu = nom;
		}

		entree >> nom >> note;
	}

	moyenne = total / nbEtu;

	afficherSortie(nbEtu, nbEchec, moyenne, meilleurEtu, sortie);
	afficherSortie(nbEtu, nbEchec, moyenne, meilleurEtu, cout);

	entree.close();
	sortie.close();

	system("PAUSE");
}/* * vérifies si le fichier existe */void siFichierOuvert(ifstream &entree, string fichier) {	if (!entree.is_open()) {
		cout << "\"" << fichier << "\" est manquant." << endl;
		system("PAUSE");
		exit(0);
	}}/* * vérifies si le fichier est vide */void siFichierVide(ifstream &entree, string fichier) {	if (!entree) {
		cout << "\"" << fichier << "\" est vide." << endl;
		system("PAUSE");
		exit(0);
	}}/* * afficher le message de sortie */void afficherSortie(int nbEtu, int nbEchec, float moyenne, string meilleurEtu, ostream &sortie) {
	sortie << setw(48) << right << "Statistiques du groupe 4120" << endl
		<< setw(48) << right << "===========================" << endl
		<< setw(30) << left << "Nombre total d'etudiants :" << setw(10) << left << nbEtu << setw(30) << left << "Nombre d'echecs" << setw(10) << left << nbEchec << endl
		<< setw(30) << left << "Moyenne du groupe :" << setw(10) << left << setprecision(1) << fixed << moyenne << setw(30) << left << "Meilleur(e) etudiant(e) :" << setw(10) << left << meilleurEtu << endl;
}
