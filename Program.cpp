//Program do obs³ugi struktury i zatrudnienia w firmach

#define _CRT_SECURE_NO_WARNINGS
#include "Pracownik.h"
#include "Data.h"
#include "Ekipa.h"
#include "Firma.h"
#include <iostream>
using namespace std;

void main() {
	
	/*Data data1;
	data1.Ustaw(28, 4, 1987);
	data1.Wypisz();
	
	Data data2;
	data2.Wpisz();
	data2.Wypisz();*/

	Pracownik pracownik1;
	pracownik1.setImie("Adam");
	pracownik1.setNazwisko("Kowal");
	pracownik1.DataUrodzenia(12, 3, 1983);
	Pracownik pracownik3("Piotr", "Dul");
	//pracownik1.Wypisz();

	Pracownik* pracownik2 = new Pracownik();
	pracownik2->Wpisz();
	//pracownik2->Wypisz();

	/*Ekipa ekipa1(2);
	ekipa1.Wypelnij();
	ekipa1.WypiszE();*/
	/*ekipa1.Zmien();
	ekipa1.WypiszE();

	int sprawdzenie = ekipa1.Sprawdz("Adam", "Nowak");
	if (sprawdzenie == -1) {
		cout << "Brak pracownika o podanych personaliach" << endl;
	}
	else {
		cout << "pracownik o podanym imieniu i nazwisku wpisany jest pod indeksem " << sprawdzenie << endl;
	}*/

	/*Pracownik tab1[2] = { pracownik1, pracownik3 };
	Firma* firma1 = new Firma();
	firma1->setSzef(pracownik2);
	firma1->setNazwa("NazwaFirmy");
	//firma1->setDlugoscF(2);
	//firma1->setAktualneWypelnienieF(2);
	//firma1->setTablicaPracownikowF(tab1);
	firma1->Wypelnij();
	firma1->WypiszE();*/

	const char* nazwa1 = "NowaFirma1";
	const char nazwa2[] = "NowaFirma2";
	Firma firma2("NowaFirma", pracownik2, 2);
	//firma2.setAktualneWypelnienie(0);
	//firma2.setDlugoscF(2);
	firma2.Wypelnij();
	
}