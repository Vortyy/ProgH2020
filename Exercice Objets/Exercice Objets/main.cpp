#include <iostream>
#include <cassert>
using namespace std;

class temps { //1 t majuscule
private: //2 :
	int _heure;
	int _minute;
	int _seconde;

public: //3 :
	temps(int heure = 0, int min = 0, int sec = 0);
	~temps(void);
	int heure()const;
	int minute()const;
	int seconde()const;
	void setTemps(int heure, int minute, int seconde);
	void affiche(ostream&)const;
}; //4 ;
ostream& operator<<(ostream& output, const temps& t);

temps::temps(int heure, int min, int sec) { //5 pas de void
	assert(heure < 0 || min < 0 || sec < 0);
	heure = _heure;
	min = _minute;
	sec = _seconde;
}

temps::~temps(void) { //6 pas de void
	_heure == _minute == _seconde == 0;
}

int temps::heure()const //7 const
{
	return _heure;
}
int temps::minute()const //8 const
{
	return _minute;
}
int temps::seconde()const //9 const
{
	return _seconde;
}
void temps::setTemps(int heure, int minute, int seconde)
{
	_heure = (heure >= 0 && heure < 24) ? heure : 0;
}

void temps::affiche(ostream& output)const //10 temps::
{
	output << _heure << ":" << _minute << ":" << _seconde
		<< (_heure < 12) ? " AM" : " PM" << endl;
}

ostream& operator<<(ostream& output, const temps& t) {
	t.affiche(output);
	return output;
}

void main() {
	temps T1, T2(5, 22), T3(T2);
	T1.setTemps(16, 10, 3);
	T1.affiche(cout);
	cout << T2; // << pas overloadé
}