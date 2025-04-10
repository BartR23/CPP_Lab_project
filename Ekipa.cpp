#include "Ekipa.h"
#include <iostream>
using namespace std;

Ekipa::Ekipa(long int dlugosc) {
	this->dlugosc = dlugosc;
	tablica = new Pracownik[dlugosc];
	this->aktualne_wypelnienie = 0;
}

Ekipa::~Ekipa() {
	delete[] tablica;
}

void Ekipa::Wypelnij() {
	for (int i = 0; i < this->dlugosc; i++) {
		if (aktualne_wypelnienie <= this->dlugosc) {
			tablica[aktualne_wypelnienie].Wpisz();
			aktualne_wypelnienie += 1;
		}
		else {
			cout << "Tablica pelna\n";
		}
	}
}

void Ekipa::Zmien() {
	int x;
	cout << "Podaj nr indeksu pracownika do zmiany" << endl;
	cin >> x;
	/*cout << "Jesli chcesz zmienic imie wcisnij 1\nJesli chcesz zmienic nazwisko wcisnij 2\n" <<
		"Jesli chcesz zmienic date urodzenia wcisnij 3\nJesli chcesz zmienic wszytko wcisnij 4\n";*/
	if (x >= 0 && x < dlugosc)
	{
		tablica[x].Wpisz();
	}
}

int Ekipa::Sprawdz(const char* imie_spr, const char* nazw_spr) {
	for (int i = 0; i < dlugosc; i++)
	{
		if (tablica[i].SprawdzImie(imie_spr) && tablica[i].SprawdzNazwisko(nazw_spr))
		{
			return i;
		}
	}
	return -1;
}

void Ekipa::WypiszE() const {
	for (int i = 0; i < this->dlugosc; i++) {
		tablica[i].Wypisz();
		cout << "\n";
	}
}

long int Ekipa::LiczbaPracownikow() const {
	return dlugosc;
}

int Ekipa::OstatniNumer() const {
	return aktualne_wypelnienie;
}
Pracownik* Ekipa::ListaPracownikow() const {
	return tablica;
}

Ekipa::Ekipa(const Ekipa& ekipa) {
	this->dlugosc = ekipa.LiczbaPracownikow();
	tablica = ekipa.ListaPracownikow();
	this->aktualne_wypelnienie = ekipa.OstatniNumer();
}

void Ekipa::setDlugosc(long int dlugosc) {
	this->dlugosc = dlugosc;
	delete[] tablica;
	tablica = new Pracownik[dlugosc];
}

void Ekipa::setAktualneWypelnienie(int aktualne_wypelnienie) {
	this->aktualne_wypelnienie = aktualne_wypelnienie;
}

void Ekipa::setTablicaPracownikow(Pracownik* tablica) {
	delete[] this->tablica;
	this->tablica = tablica;
}

Ekipa& Ekipa::operator = (const Ekipa& wzorzec) {
	//delete tablica;
	setDlugosc(wzorzec.LiczbaPracownikow());
	setAktualneWypelnienie(wzorzec.OstatniNumer());
	setTablicaPracownikow(wzorzec.ListaPracownikow());
	return;
}

bool Ekipa::operator ==(const Ekipa& wzorzec) {
	if (this->dlugosc == wzorzec.LiczbaPracownikow() && this->aktualne_wypelnienie == wzorzec.OstatniNumer() && this->tablica == wzorzec.ListaPracownikow())
		return true;
	else
		return false;
}

Ekipa& operator >>(istream klawiatura, Ekipa& ekipa) {
	ekipa.Wypelnij();
	return ekipa;
}

Ekipa& operator <<(ostream ekran, Ekipa& ekipa) {
	ekipa.WypiszE();
	return ekipa;
}