#pragma once
#include "Pakka.h"
#include <vector>

class SotaPeli
{
private:
	const int kadenKoko = 26;
	vector<Kortti*> pelaajanKasi;
	vector<Kortti*> koneenKasi;
	vector<Kortti*> poyta;
	Kortti* kortti1;
	Kortti* kortti2;
	Pakka pakka;
	bool vertailunTulos = false;
	bool sotaKesken = false; // Sota tilanteessa varmistaa että ei aloita uutta sota tilannetta kesken sodan
	static int pelatutKortit; // Laskee kuinka monta korttia on pelattu ihan vaan koska voi

public:
	bool peliLoppu = false;

	SotaPeli();

	void nostaKasi(const int kadenKoko);

	void tulostaKasi(); // Tulostaa kuinka monta korttia kummassakin kädessä vielä on
	void pelaaKortti();
	void vertaileKortit(Kortti* kortti1, Kortti* kortti2); // Vertailee kumpi voittaa kortin
	bool vertaileSota(Kortti* kortti1, Kortti* kortti2); // Vertailee täyttyykö sodan kriteerit
	bool tarkistaKasi(); // Tarkistaa onko kädessä kortteja, palauttaa true jos kumpikaan käsi on tyhjä
	void pelaaSota();
	void pelinPaatos();
	void sekoitaKasi(); // Tarkoitus estää pelin turhan pitkä jatkuminen, sekoittee kädet 20 pelatun kortin välein
};

