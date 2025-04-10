#pragma once
#include "Ekipa.h"
class Firma :
    public Ekipa
{
    char* NazwaFirmy;
    Pracownik* Szef;

public:
    Firma(const char* nazwa = "Firma", Pracownik* szef = new Pracownik("Jan", "Kowalski"), long int dlugosc = 0);
    Firma(const Firma& firma);
    ~Firma();

    Pracownik* getSzef() const;
    char* getNazwaFirmy() const;
    long int LiczbaPracownikowFirmy() const;
    int OstatniNumerF() const;
    Pracownik* ListaPracownikowFirmy() const;

    void setSzef(Pracownik* nowy_szef);
    void setNazwa(const char* nowa_nazwa);
    
    //void setListaPracownikow(long int l_pracownikow);
    //void setDlugoscF(long int dlugosc);
    //void setAktualneWypelnienieF(int aktualne_wypelnienie);
    //void setTablicaPracownikowF(Pracownik* tablica);

    Firma& operator = (const Firma& wzorzec);
    bool operator ==(const Firma& wzorzec);
    friend Firma& operator >>(istream klawiatura, Firma& firma);
    friend Firma& operator <<(ostream ekran, Firma& firma);
};

