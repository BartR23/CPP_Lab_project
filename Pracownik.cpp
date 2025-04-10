#define _CRT_SECURE_NO_WARNINGS
#include "Pracownik.h"
#include <iostream>
using namespace std;

const char* Pracownik::Imie() const{
	return m_pszImie;
}
const char* Pracownik::Nazwisko() const {
	return m_pszNazwisko;
}
void Pracownik::setImie(const char* nowe_imie) {
	if (this->m_pszImie) delete[] this->m_pszImie;
	m_pszImie = new char[strlen(nowe_imie) + 1];
	strcpy(m_pszImie, nowe_imie);
}
void Pracownik::setNazwisko(const char* nowe_nazwisko) {
	if (this->m_pszNazwisko) delete[] this->m_pszNazwisko;
	m_pszNazwisko = new char[strlen(nowe_nazwisko) + 1];
	strcpy(m_pszNazwisko, nowe_nazwisko);
}
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok) {
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const {
	cout << this->m_pszImie << "\t\t" << this->m_pszNazwisko << "\t\t";
	this->m_DataUrodzenia.Wypisz();
}
void Pracownik::Wpisz() {
	char temp[30];
	cout << "Podaj imie: ";
	cin >> temp;
	setImie(temp);
	//delete temp;
	cout << "\nPodaj nazwisko: ";
	cin >> temp;
	setNazwisko(temp);
	//delete temp;
	this->m_DataUrodzenia.Wpisz();
}
bool Pracownik::SprawdzImie(const char* por_imie) const {
	if (strcmp(this->m_pszImie, por_imie) == 0)
		return 1;
	else
		return 0;
}
bool Pracownik::SprawdzNazwisko(const char* por_nazwisko) const {
	if (strcmp(this->m_pszNazwisko, por_nazwisko) == 0)
		return 1;
	else
		return 0;
}

Pracownik::Pracownik(const char* nowe_imie, const char* nowe_nazwisko) {
	this->m_pszImie = new char[strlen(nowe_imie) + 1];
	strcpy(this->m_pszImie, nowe_imie);
	this->m_pszNazwisko = new char[strlen(nowe_nazwisko) + 1];
	strcpy(this->m_pszNazwisko, nowe_nazwisko);
}

Pracownik::~Pracownik() {
	delete[] m_pszImie;
	delete[] m_pszNazwisko;
}

Pracownik& Pracownik::operator =(const Pracownik& wzorzec) {
	delete m_pszImie;
	delete m_pszImie;
	//delete m_DataUrodzenia;
	setImie(wzorzec.Imie());
	setNazwisko(wzorzec.Nazwisko());
	DataUrodzenia(wzorzec.m_DataUrodzenia.Dzien(), wzorzec.m_DataUrodzenia.Miesiac(), wzorzec.m_DataUrodzenia.Rok());
	return;
}

bool Pracownik::operator ==(const Pracownik& wzorzec) {
	if (SprawdzImie(wzorzec.Imie())==1 && SprawdzNazwisko(wzorzec.Nazwisko()) == 1)
		return true;
	else
		return false;
}

Pracownik& operator >>(istream klawiatura, Pracownik& pracownik) {
	pracownik.Wpisz();
	return pracownik;
}

Pracownik& operator <<(ostream ekran, Pracownik& pracownik) {
	pracownik.Wypisz();
	return pracownik;
}
