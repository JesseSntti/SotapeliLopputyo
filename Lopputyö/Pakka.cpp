#include "Pakka.h"
#include <iostream>
#include <algorithm>

Pakka::Pakka() {
	pakka.reserve(52);
	for (Kortti::Numerot n = Kortti::ASSA; n <= Kortti::KALLE; n = static_cast<Kortti::Numerot>(static_cast<int>(n) + 1)) {
		for (Kortti::Maat m = Kortti::HERTTA; m <= Kortti::PATA; m = static_cast<Kortti::Maat>(static_cast<int>(m) + 1)) {
			pakka.push_back(new Kortti(m, n));
		}
	}
}

Pakka::~Pakka() {
	for (Kortti* kortti : pakka) {
		delete kortti;
	}
	pakka.clear();
}

void Pakka::tulosta() {
	for (Kortti* kortti : pakka) {
		kortti->tulosta();
		std::cout << " ";
	}
}

void Pakka::sekoita() {
	std::random_shuffle(pakka.begin(), pakka.end());
}

Kortti* Pakka::topKortti() {
	return pakka.back();
}

void Pakka::popKortti() {
	pakka.pop_back();
}