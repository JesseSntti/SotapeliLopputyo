#pragma once
#include <string>

using namespace std;

class Kortti
{
private:
	int numero;
	int maa;

public:
	enum Maat{
		HERTTA = 3,
		RUUTU,
		RISTI,
		PATA
	};

	enum Numerot {
		ASSA = 1,
		KAKKONEN,
		KOLMONEN, 
		NELONEN,
		VITONEN,
		KUTONEN,
		SEISKA,
		KASI,
		YSI,
		KYMPPI,
		JATKA,
		KUNINGATAR,
		KALLE
	};

	Kortti(Maat maa, Numerot numero);
	virtual ~Kortti();

	int getNumero();
	int getMaa();
	virtual int getKortinArvo();

	void tulosta();

};

