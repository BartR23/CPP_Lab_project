#define _CRT_SECURE_NO_WARNINGS
#include "Firma.h"
#include <iostream>
using namespace std;

Firma::Firma(const char* nazwa, Pracownik* szef, long int dlugosc) : Ekipa(dlugosc), Szef(szef) 
{
	setNazwa(nazwa);
	setSzef(szef);
}

Firma::Firma(const Firma& firma) : Ekipa(firma) {
	setNazwa(firma.getNazwaFirmy());
	setSzef(firma.getSzef());
	//Ekipa(firma);
}

Firma::~Firma() {
	delete[] NazwaFirmy;
	delete[] Szef;
	//~Ekipa();
}

Pracownik* Firma::getSzef() const {
	return Szef;
}

char* Firma::getNazwaFirmy() const {
	return NazwaFirmy;
}

long int Firma::LiczbaPracownikowFirmy() const {
	return LiczbaPracownikow();
}

int Firma::OstatniNumerF() const {
	return OstatniNumer();
}

Pracownik* Firma::ListaPracownikowFirmy() const {
	return ListaPracownikow();
}

void Firma::setSzef(Pracownik* nowy_szef) {
	Szef->setImie(nowy_szef->Imie());
	Szef->setNazwisko(nowy_szef->Nazwisko());
}

void Firma::setNazwa(const char* nowa_nazwa) {
	if (this->NazwaFirmy) delete[] this->NazwaFirmy;
	NazwaFirmy = new char[strlen(nowa_nazwa) + 1];
	strcpy(NazwaFirmy, nowa_nazwa);
}

//void Firma::setListaPracownikow(long int l_pracownikow) {
//	Wypelnij();
//}

//void Firma::setDlugoscF(long int dlugosc) {
//	setDlugosc(dlugosc);
//}
//
//void Firma::setAktualneWypelnienieF(int aktualne_wypelnienie) {
//	setAktualneWypelnienie(aktualne_wypelnienie);
//}
//
//void Firma::setTablicaPracownikowF(Pracownik* tablica) {
//	setTablicaPracownikow(tablica);
//}

Firma& Firma::operator = (const Firma& wzorzec) {
	//delete tablica;
	setDlugosc(wzorzec.LiczbaPracownikow());
	setAktualneWypelnienie(wzorzec.OstatniNumer());
	setTablicaPracownikow(wzorzec.ListaPracownikow());
	return;
}

bool Firma::operator ==(const Firma& wzorzec) {
	if (LiczbaPracownikow() == wzorzec.LiczbaPracownikow() && OstatniNumer() == wzorzec.OstatniNumer() && ListaPracownikow() == wzorzec.ListaPracownikow())
		return true;
	else
		return false;
}

Firma& operator >>(istream klawiatura, Firma& firma) {
	char* temp;
	cout << "Podaj nazwe: ";
	klawiatura >> temp;
	firma.setNazwa(temp);
	cout << "Podaj szefa: ";
	firma.getSzef()->Wpisz();
	cout << "Podaj pracownikow: ";
	firma.Wypelnij();
	return firma;
}

Firma& operator <<(ostream ekran, Firma& firma) {
	ekran << "Nazwa: " << firma.getNazwaFirmy();
	//firma.getNazwaFirmy();
	ekran << "\nSzef: ";
	firma.getSzef()->Wypisz();
	ekran << "\nPracownicy: ";
	firma.WypiszE();
	return firma;
}