/******************************************************************************
Auteur: Julie Gagnon
Date: 01/02/2020
Programme: date.h
But: objet date (jour, mois, annee) qui offre de générer de la date du jour
*******************************************************************************/

#pragma once
#include <time.h>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

class Date {
private:
	int _jour;
	int _mois;
	int _annee;

public:
	Date();
	Date(int jour, int mois, int annee);

	~Date(); //prototype du destructeur

	int getJour()const; //prototype du getteur
	int getMois()const;
	int getAnnee()const;
	Date getDate();

	void setJour(int jour); //prototype du setteur
	void setMois(int mois);
	void setAnnee(int annee);
	void setDate(int jour, int mois, int annee);
	void setToday();
};

void entrerNaissance(Date& dateNaissance, Date dateJour);
void printDate(Date date, ostream& output);