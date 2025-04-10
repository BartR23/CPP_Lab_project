#pragma once
class Data
{
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

public:

	Data(void);
	//Data(int d=1, int m=1, int r=2000);
	
	void Ustaw(int d, int m, int r);
	
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	bool Porownaj(const Data& wzor) const;
	
	//~Data();

	Data& operator =(const Data& wzorzec);
	bool operator ==(const Data& wzorzec);
	friend Data& operator >>(istream klawiatura, Data& data);
	friend Data& operator <<(ostream ekran, Data& data);
};






