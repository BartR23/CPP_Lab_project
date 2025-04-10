#pragma once
#include "Data.h"

class Pracownik
{
	/*char m_pszImie[25];
	char m_pszNazwisko[30];*/
	char* m_pszImie;
	char* m_pszNazwisko;
	Data m_DataUrodzenia;


public:
	//Pracownik() = default;
	Pracownik(const char* imie = "Jan", const char* nazwisko = "Nowak");
	~Pracownik();
	const char* Imie() const;
	const char* Nazwisko() const;
	void setImie(const char* nowe_imie);
	void setNazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	bool SprawdzImie(const char* por_imie) const;
	bool SprawdzNazwisko(const char* por_nazwisko) const;

	Pracownik& operator =(const Pracownik& wzorzec);
	bool operator ==(const Pracownik& wzorzec);
	friend Pracownik& operator >>(istream klawiatura, Pracownik& pracownik);
	friend Pracownik& operator <<(ostream ekran, Pracownik& pracownik);
};

