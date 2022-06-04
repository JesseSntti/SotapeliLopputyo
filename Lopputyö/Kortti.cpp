#include "Kortti.h"
#include "Pakka.h"
#include <iostream>

Kortti::Kortti(Maat maa, Numerot numero) {
	this->maa = maa;
	this->numero = numero;
}

Kortti::~Kortti() {

}

Kortti::Maat; int Kortti::getMaa() {
	return maa;
}

Kortti::Numerot; int Kortti::getNumero() {
	return numero;
}

int Kortti::getKortinArvo() {
	return static_cast<int>(numero);
}

void Kortti::tulosta() {
	if (maa == HERTTA)
		std::cout << "Hertta ";
	else if (maa == RUUTU)
		std::cout << "Ruutu ";
	else if (maa == RISTI)
		std::cout << "Risti ";
	else
		std::cout << "Pata ";

	if (numero > ASSA and numero <= KYMPPI)
		std::cout << numero << ", ";
	else if (numero == JATKA)
		std::cout << "Jatka (11), ";
	else if (numero == KUNINGATAR)
		std::cout << "Kuningatar (12), ";
	else if (numero == KALLE)
		std::cout << "Kalle (13), ";
	else
		std::cout << "Assa (1), ";
}