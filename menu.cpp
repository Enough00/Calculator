#include "menu.h"
#include "calculator.h"
vector<char> type;
void start() {
	cout << "### Witaj w kalkulatorze dla elektronikow ###" << endl;
	cout << "### W tym programie mozesz konwertowac liczby z roznych systemow ###" << endl;
	cout << "### Format zapisow wyglada nastepujaco: ###" << endl;
	cout << "0b - binarne \n0d - decymalne \n0x - heksagonalnie \n0o - oktagonalnie" << endl;
	cout << "Podaj przedrostek b,d,x,o aby przekonwertowac dana liczbe na inne systemy liczbowe" << endl;
	// wybor danego systemu liczbowego i rozpoczenie dzialania programu
	
	char c{}; //zmienna przechowujaca przedrostek
	int model{}; //zmienna przechowujaca char jako liczbe
	int Key{}; //zmienna odczytujaca liczby z klawiatury
	string liczba; //zmienna przechowujaca ciag znakow(liczb)
	cin.get(c); //odczytanie z klawiatury znaku i wpiswanie w zmienna c
	type.push_back(c);
	model = int(type[0]); //przechowanie char jako wektor, ktory rzutuje na int
	cout << "Podaj liczbe, a nastepnie kliknij /spacja/ i /enter/, zeby kalkulator zaczal dzialac" << endl;
	if (model == (int)'b') {
		do {
			Key = getchar();
			if ((Key == (int)'0') | (Key == (int)'1')) {
				liczba += Key;
			}
			if (Key == 32)
				break; // space and enter to exit
		} while (1);
	}
	if (model == (int)'d') {
		do {
			Key = getchar();
			if ((Key >= (int)'0') & (Key <= (int)'9')) {
				liczba += Key;
			}
			if (Key == 32)
				break; //space and enter to exit
		} while (1);
	}
	if (model == (int)'x') {
		do {
			Key = getchar();
			if ((Key >= (int)'0') & (Key <= (int)'9')) {
				liczba += Key;
			}
			else if ((Key >= (int)'A') & (Key <= (int)'F')) {
				liczba += Key;
			}
			else if ((Key >= (int)'a') & (Key <= (int)'f')) {
				liczba += Key;
			}
			if (Key == 32)
				break; // space and enter to exit
		} while (1);
	}
	if (model == (int)'o') {
		do {
			Key = getchar();
			if ((Key >= (int)'0') & (Key <= (int)'7')) {
				liczba += Key;
			}
			if (Key == 32)
				break; //space and enter to exit
		} while (1);
	}
	//wybor danego rozwiazanie, aby stworzyc konwersje na wszystkie liczby
	calculator Calculator;
	if (model == (int)'b') { Calculator.BinToDec(liczba); };
	if (model == (int)'d') { Calculator.dec(liczba); };
	if (model == (int)'x') { Calculator.HexToDec(liczba); };
	if (model == (int)'o') { Calculator.OctToDec(liczba); };
}