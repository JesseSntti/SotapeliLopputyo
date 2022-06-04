#pragma once
#include <vector>
#include "Kortti.h"

using namespace std;

class Pakka
{
private:
	vector<Kortti*> pakka;

public:
	Pakka();
	~Pakka();

	void tulosta();
	void sekoita();

	Kortti* topKortti();
	void popKortti();
};

