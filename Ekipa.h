#pragma once
#include "Pracownik.h"
#include "Data.h"

class Ekipa {
	
	Pracownik* tablica;
	long int dlugosc;
	int aktualne_wypelnienie;

public:

	Ekipa(long int dlugosc = 0);
	~Ekipa();
	void Wypelnij();
	void Zmien();
	int Sprawdz(const char* imie_spr, const char* nazw_spr);
	void WypiszE() const;

	long int LiczbaPracownikow() const;
	int OstatniNumer() const;
	Pracownik* ListaPracownikow() const;
	Ekipa(const Ekipa& ekipa);

	void setDlugosc(long int dlugosc);
	void setAktualneWypelnienie(int aktualne_wypelnienie);
	void setTablicaPracownikow(Pracownik* tablica);

	Ekipa& operator = (const Ekipa& wzorzec);
	bool operator ==(const Ekipa& wzorzec);
	friend Ekipa& operator >>(istream klawiatura, Ekipa& ekipa);
	friend Ekipa& operator <<(ostream ekran, Ekipa& ekipa);
};