#include <iostream>
#include <ctime>
#include "Pakka.h"
#include "SotaPeli.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	int input1 = 0, input2 = 0;

	cout << "Haluatko pelata Sota-korttipeliä? 1 = kyllä." << endl;
	cin >> input1;

	if (input1 == 1)
		cout << "Pelataan siis. " << endl << endl;
		SotaPeli s1;


	while (input1 == 1) {
		cout << "1 = pelaa kortti. 2 = tulosta kuinka monta korttia on vielä käsissä. Muu = lopeta peli." << endl;
		cin >> input2;
		cout << endl;

		if (input2 == 1 and s1.peliLoppu == false)
			s1.pelaaKortti();

		else if (input2 == 2) {
			s1.tulostaKasi();
		}

		else if (input2 != 1 and s1.peliLoppu == false) {
			cout << "Halutko lopettaa pelin? 1 = jatka peliä. 2 = tulosta kuinka monta korttia on vielä käsissä. Muu = lopeta peli." << endl;
			cin >> input1;
		}
		

		else
			input1 = 0;
	}
	

	cout << "Peli lopetetaan..." << endl << endl;
	return 0;
}

