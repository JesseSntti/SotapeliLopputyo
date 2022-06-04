#include "SotaPeli.h"
#include <iostream>
#include <algorithm>

int SotaPeli::pelatutKortit = 0;

SotaPeli::SotaPeli() {
	pakka.sekoita();
	pelaajanKasi.reserve(kadenKoko);
	koneenKasi.reserve(kadenKoko);
	nostaKasi(kadenKoko);

}

void SotaPeli::tulostaKasi() {
	std::cout << "Pelaajan kadessa on viela " << pelaajanKasi.size() << " korttia" << endl;
	std::cout << "Koneen kadessa on viela " << koneenKasi.size() << " korttia" << endl;
}

void SotaPeli::nostaKasi(const int kadenKoko) {
	for (int i = 0; i < kadenKoko; i++) {
		pelaajanKasi.push_back(pakka.topKortti());
		pakka.popKortti();
		koneenKasi.push_back(pakka.topKortti());
		pakka.popKortti();
	}
}

void SotaPeli::pelaaKortti() {
	pelatutKortit++;
	pelatutKortit++;

	if (tarkistaKasi() == false) {
		if (pelatutKortit % 20 == 0) {
			sekoitaKasi();
		}

		kortti1 = pelaajanKasi.back();
		kortti2 = koneenKasi.back();

		std::cout << "Sinun kortti: " << endl;
		kortti1->tulosta();
		poyta.push_back(kortti1);
		std::cout << endl;
		std::cout << "Vastustajan kortti: " << endl;
		kortti2->tulosta();
		poyta.push_back(kortti2);
		std::cout << endl << endl;

		vertailunTulos = vertaileSota(kortti1, kortti2);

		pelaajanKasi.pop_back();
		koneenKasi.pop_back();


		if (sotaKesken == false and vertailunTulos == true) {
				pelaaSota();
			}
		else
			vertaileKortit(kortti1, kortti2);
	}

	else
		pelinPaatos();
}

bool SotaPeli::vertaileSota(Kortti* kortti1, Kortti* kortti2) {
	if (kortti1->getKortinArvo() == kortti2->getKortinArvo())
		return true;
	else 
		return false;
}

bool SotaPeli::tarkistaKasi() {
	if (pelaajanKasi.empty() or koneenKasi.empty())
		return true;
	else
		return false;
}

void SotaPeli::pelaaSota() {
	sotaKesken = true;

	if (tarkistaKasi() == false) {
		std::cout << "----------SOTA----------" << endl << endl;
		kortti1 = pelaajanKasi.back();
		kortti2 = koneenKasi.back();

		if (vertaileSota(kortti1, kortti2))
			sotaKesken = true;

		for (int i = 0; i < 5; i++) {
			pelatutKortit++;
			pelatutKortit++;
			if (tarkistaKasi()) {
				std::cout << "Kortit loppuivat kesken!" << endl << endl;
				std::cout << "Sinun viimeinen kortti: " << endl;
				kortti1->tulosta();
				std::cout << endl;
				std::cout << "Vastustajan viimeinen kortti: " << endl;
				kortti2->tulosta();
				std::cout << endl << endl;
				break;
			}
			else if (i == 4) {
				std::cout << "Molemmat pelaajat pelaavat 5 korttia naama alaspain ja peraan yhden kortin normaalisti." << endl;
				std::cout << "Sinun kortti: " << endl;
				kortti1->tulosta();
				std::cout << endl;
				std::cout << "Vastustajan kortti: " << endl;
				kortti2->tulosta();
				std::cout << endl << endl;
			}

			poyta.push_back(kortti1);
			poyta.push_back(kortti2);

			pelaajanKasi.pop_back();
			koneenKasi.pop_back();
		}

		vertaileKortit(kortti1, kortti2);

		if (tarkistaKasi() == false) {
			sotaKesken = false;
		}
	}
		
	else {
		pelinPaatos();
	}
}

void SotaPeli::vertaileKortit(Kortti* kortti1, Kortti* kortti2) {
	if (kortti1->getKortinArvo() > kortti2->getKortinArvo()) {
		for (Kortti* kortti : poyta) {
			pelaajanKasi.emplace(pelaajanKasi.begin(), kortti);
		}
		if (sotaKesken == true) {
			std::cout << "VOITIT SODAN." << endl << endl;
		}
		else {
			std::cout << "VOITIT KORTIN." << endl << endl;
		}
		
		if (tarkistaKasi()) {
			poyta.clear();
			pelinPaatos();
		}
	}

	else if (kortti2->getKortinArvo() > kortti1->getKortinArvo()) {
		for (Kortti* kortti : poyta) {
			koneenKasi.emplace(koneenKasi.begin(), kortti);
		}
		if (sotaKesken == true) {
			std::cout << "HAVISIT SODAN." << endl << endl;
		}
		else {
			std::cout << "HAVISIT KORTIN." << endl << endl;
		}

		if (tarkistaKasi()) {
			poyta.clear();
			pelinPaatos();
		}
	}

	else if (kortti1->getKortinArvo() == kortti2->getKortinArvo()) {
		if (tarkistaKasi()) {
			std::cout << "Kortit loppuivat kesken!" << endl << endl;
			pelinPaatos();
		}
		else {
			std::cout << "Pelataan uudet kortit." << endl << endl;
			pelaaKortti();
		}
	}
	poyta.clear();
}

void SotaPeli::pelinPaatos() {
	if (pelaajanKasi.empty() == false and koneenKasi.empty()) {
		for (Kortti* kortti : poyta) {
			pelaajanKasi.emplace(pelaajanKasi.begin(), kortti);
		}
		std::cout << "Koneen kadesta loppuivat kortit. " << endl << "VOITIT PELIN " << endl;
	}
	else if (pelaajanKasi.empty() and koneenKasi.empty() == false) {
		for (Kortti* kortti : poyta) {
			koneenKasi.emplace(koneenKasi.begin(), kortti);
		}
		std::cout << "Sinun kadesta loppuivat kortit. " << endl << "HAVISIT PELIN " << endl;
	}
	std::cout << "Pelissa pelattiin " << pelatutKortit << " korttia." << endl << endl << endl;
	peliLoppu = true;
}

void SotaPeli::sekoitaKasi() {
	std::random_shuffle(pelaajanKasi.begin(), pelaajanKasi.end());
	std::random_shuffle(koneenKasi.begin(), koneenKasi.end());
}
