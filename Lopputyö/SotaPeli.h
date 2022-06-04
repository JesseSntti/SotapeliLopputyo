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
	bool sotaKesken = false; // Sota tilanteessa varmistaa ett� ei aloita uutta sota tilannetta kesken sodan
	static int pelatutKortit; // Laskee kuinka monta korttia on pelattu ihan vaan koska voi

public:
	bool peliLoppu = false;

	SotaPeli();

	void nostaKasi(const int kadenKoko);

	void tulostaKasi(); // Tulostaa kuinka monta korttia kummassakin k�dess� viel� on
	void pelaaKortti();
	void vertaileKortit(Kortti* kortti1, Kortti* kortti2); // Vertailee kumpi voittaa kortin
	bool vertaileSota(Kortti* kortti1, Kortti* kortti2); // Vertailee t�yttyyk� sodan kriteerit
	bool tarkistaKasi(); // Tarkistaa onko k�dess� kortteja, palauttaa true jos kumpikaan k�si on tyhj�
	void pelaaSota();
	void pelinPaatos();
	void sekoitaKasi(); // Tarkoitus est�� pelin turhan pitk� jatkuminen, sekoittee k�det 20 pelatun kortin v�lein
};

