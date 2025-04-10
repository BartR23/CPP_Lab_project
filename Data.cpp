#include "Data.h"
#include <iostream>
using namespace std;

Data::Data(void) = default;

//Data::Data(int d = 1, int m = 1, int r = 2000) {
//	this->m_nDzien = d;
//	this->m_nMiesiac = m;
//	this->m_nRok = r;
//}

void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
}

int Data::Dzien() const {
	return m_nDzien;
}
int Data::Miesiac() const {
	return m_nMiesiac;
}
int Data::Rok() const {
	return m_nRok;
}

void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;
}


void Data::Wpisz()
{
	cout << "Podaj dzien urodzenia: ";
	cin >> this->m_nDzien;
	cout << "\nPodaj miesiac urodzenia: ";
	cin >> this->m_nMiesiac;
	cout << "\nPodaj rok urodzenia: ";
	cin >> this->m_nRok;
	Koryguj();
}


void Data::Koryguj()
{
	if (this->m_nMiesiac == 2 && this->m_nRok % 4 == 0) {
		if (this->m_nDzien > 29) { this->m_nDzien = 29; }
	}
	else if (this->m_nMiesiac == 2 && this->m_nRok % 4 != 0) {
		if (this->m_nDzien > 28) { this->m_nDzien = 28; }
	}
	else if (this->m_nMiesiac == 4 || this->m_nMiesiac == 6 || this->m_nMiesiac == 9 || this->m_nMiesiac == 11) {
		if (this->m_nDzien > 30) { this->m_nDzien = 30; }
	}
	else {
		if (this->m_nDzien > 31) { this->m_nDzien = 31; }
	}
}


bool Data::Porownaj(const Data& wzor) const
{
	if (this->m_nDzien == wzor.m_nDzien && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nRok == wzor.m_nRok)
		return true;
	else
		return false;
}

//Data::~Data() {
//	delete this->m_nDzien;
//	delete this->m_nMiesiac;
//	delete this->m_nRok;
//}

Data& Data::operator =(const Data& wzorzec) {
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
	return;
}

bool Data::operator ==(const Data& wzorzec) {
	if (this->m_nDzien == wzorzec.m_nDzien && this->m_nMiesiac == wzorzec.m_nMiesiac && this->m_nRok == wzorzec.m_nRok)
		return true;
	else
		return false;
}

Data& operator >>(istream klawiatura, Data& data) {
	int d, m, r;
	cout << "Podaj dzien: ";
	klawiatura >> d;
	cout << "\nPodaj miesiac: ";
	klawiatura >> m;
	cout << "\nPodaj rok: ";
	klawiatura >> r;
	data.Ustaw(d,m,r);
	return data;
}

Data& operator <<(ostream ekran, Data& data) {
	ekran << "Data: ";
	data.Wypisz();
	return data;
}

