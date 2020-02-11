/*
 * Auteur: Étienne Ménard
 * Date 11/02/2020
 * Fichier: main.cpp
 * But: coder en  mmorse un message
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct CodeMorse {
	char lettre;
	string code;
};

void initialiserMorse(ifstream& file, CodeMorse codeMorse[37]);
string saisirMessage();
int recherche(CodeMorse codeMorse[], char aComparer);
void openFile(std::ifstream& file, std::string fileName);
void ifEmpty(std::ifstream& file);
void viderBuffer();
void pause();

void main() {
	CodeMorse codeMorse[37];
	ifstream fichier;

	initialiserMorse(fichier, codeMorse);

	string message = saisirMessage();

	for (int i = 0; i < message.length(); i++) {
		if (message[i] == ' ') {
			cout << endl;
		}
		else {
			int pos = recherche(codeMorse, toupper(message[i]));
			if (pos == 37) {
				cout << "<" << message[i] << "> ???" << endl;
			}
			else 
				cout << "<" << message[i] << "> " << codeMorse[pos].code << endl;
		}
		
	}
	fichier.close();
	system("pause");
}
//message
string saisirMessage() {
	string message;
	cout << "Entrez un message: ";
	getline(cin, message);
	return message;
}

// cherche dans le tableau pour le bon code
int recherche(CodeMorse codeMorse[], char aComparer) {
	
	for (int i = 0; i < 37; i++) {
		if (aComparer == codeMorse[i].lettre) 
			return i;
	}
	return 37;
}

/*
Initialise le tableau de codes morse
*/
void initialiserMorse(ifstream& file, CodeMorse codeMorse[37]) {
	openFile(file, "codesMorse.txt");
	ifEmpty(file);

	for (int i = 0; i < 37; i++) {
		file >> codeMorse[i].lettre >> codeMorse[i].code;
	}
}

/*
Ouvres le fichier et ferme s'il n'existe pas
*/
void openFile(std::ifstream& file, std::string fileName) {
	file.open(fileName);

	if (!file.is_open()) {
		std::cout << "File is missing" << std::endl;
		system("pause");
		exit(0);
	}
}

/*
Vérifies si le fichier est vide
*/
void ifEmpty(std::ifstream& file) {
	if (file.fail()) {
		std::cout << "File is empty" << std::endl;
		file.close();
		system("pause");
		exit(0);
	}
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