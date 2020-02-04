/*
Programme: calculNoteFinaleMoy.cpp
Acteur: Etienne M�nard
Date de cr�ation:27/01/2020
But du programme:Lire le nom, le pr�nom et les 5 notes des �tudiants dans
etudiant.txt, calcule la note finale pour chacun et calcul
la moyenne du groupe. Affiche la liste � l��cran*/

/* Directive au pr�-processeur
 =========================== */
#include <iostream>
#include <fstream> //librairie pour la manipulation de fichiers
#include <iomanip> //librairie pour l'affichage (setw, left)
#include <string>
using namespace std;

struct Etudiant {
    string nom; // nom de l'�tudiant
    string prenom; // pr�nom de l'�tudiant
    float noteFinale; // total des 5 notes d'un �tudiant
};

void ouvrirFichier(ifstream &file, string fileName); 
void siVide(ifstream& file);
float calculerNoteFinale(ifstream &file);
void trier(Etudiant groupe[32], int nbEtu);
void afficherEtudiants(Etudiant groupe[32], int nbEtu);
float calculerMoyenne(Etudiant groupe[32], int nbEtu);
void afficherMoyenne(float moyenne);

/* Programme principal
 =================== */
void main()
{
    Etudiant groupe[32]; // information du groupe d'�tudiants

    int nbEtu = 0; //Nombre d'�tudiants

    ifstream fichierNote;

    ouvrirFichier(fichierNote, "etudiant.txt");

    getline(fichierNote, groupe[0].nom); //lecture de l'ent�te

    siVide(fichierNote);

    fichierNote >> groupe[nbEtu].nom >> groupe[nbEtu].prenom;

    while (!fichierNote.eof()) //tant que ce n'est pas la fin du fichier
    {
        groupe[nbEtu].noteFinale = calculerNoteFinale(fichierNote);
        
        nbEtu++;

        fichierNote >> groupe[nbEtu].nom >> groupe[nbEtu].prenom;
    }

    trier(groupe, nbEtu);

    //affichage de l'ent�te dans la console
    cout << left << setw(20) << "Nom" << "Note Finale" << endl;
    afficherEtudiants(groupe, nbEtu);
    afficherMoyenne(calculerMoyenne(groupe, nbEtu));

    fichierNote.close();
    system("pause");
}

// Ouvres le fichier et v�rifies s'il existe
void ouvrirFichier(ifstream& file, string fileName) { 
    file.open(fileName); //Notes en entr�e

    if (!file.is_open()) //le fichier n'existe pas
    {
        cout << "Le fichier n�a pas ete trouve." << endl;
        system("pause");
        exit(0);
    }
}

// V�rifies si le fichier est vide
void siVide(ifstream &file) {
    if (file.fail()) //si le fichier est vide
    {
        cout << "Le fichier est vide." << endl;
        file.close();
        system("pause");
        exit(0);
    }
}

// Calcules la note finale avec pond�ration
float calculerNoteFinale(ifstream &file) {

    float note, //Note lue dans le fichier
        ponderation[5] = { 10, 10, 10, 35, 35 }, //Pond�ration des notes
        total = 0;

    for (int i = 0; i < 5; i++) //lecture des 5 notes
    {
        file >> note;
        total += note * ponderation[i] / 100;
    }

    return total;
}

// Tries les �tudiants en ordre alphab�tique
void trier(Etudiant groupe[32], int nbEtu) {
    for (int i = 0; i < nbEtu - 1; i++) {
        for (int j = i + 1; j < nbEtu; j++) {
            if (groupe[i].nom > groupe[j].nom) {
                Etudiant temp = groupe[i];
                groupe[i] = groupe[j];
                groupe[j] = temp;

            }
            else if (groupe[i].nom == groupe[j].nom && groupe[i].prenom > groupe[j].prenom) {
                Etudiant temp = groupe[i];
                groupe[i] = groupe[j];
                groupe[j] = temp;
            }
        }
    }
}

// Affiche les �tudiants et la moyenne de leurs notes dans la console
void afficherEtudiants(Etudiant groupe[32], int nbEtu) {
    for (int i = 0; i < nbEtu; i++) {
        cout << left
            << setw(10) << groupe[i].nom
            << setw(10) << groupe[i].prenom
            << right << setprecision(0) << fixed << setw(5) << groupe[i].noteFinale << " %";

        if (groupe[i].noteFinale < 60) //affiche EC si �chec
            cout << " EC";

        cout << endl;
    }
}

// Calcule la moyenne
float calculerMoyenne(Etudiant groupe[32], int nbEtu) {
    float temp = 0;
    for (int i = 0; i < nbEtu; i++) {
        temp += groupe[i].noteFinale;
    }

    return temp / nbEtu;
}

// Affiche la moyenne de la classe
void afficherMoyenne(float moyenne) {
    cout << endl << left << setw(10) << "" << setw(10) << "Moyenne"
        << right << setprecision(1) << fixed << setw(5) << moyenne << " %" << endl << endl;
}