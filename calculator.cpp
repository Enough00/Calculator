#include "calculator.h"
#include "menu.h"
using std::cout, std::endl, std::size_t;
calculator::calculator() {};//domyslny konstruktor

void calculator::dec(string liczba) {
	int ans{};
	int base = 1;
	for (size_t i = liczba.size(); i > 0; i--) {
		ans += (int(liczba[i - 1]) - 48) * base;
		base = base * 10; //increment base (10^0) to (10^1) ...
	}
	DecToBin(ans);
	DecToHex(ans);
	DecToOct(ans);

};
void calculator::BinToDec(string liczba) {

	int ans{};
	int base = 1;
	for (size_t i = liczba.size(); i > 0; i--) {
		ans += (int(liczba[i - 1]) - 48) * base;
		base = base * 2; //increment base (2^0) to (2^1) ...
	}

	cout << "0d" << ans << endl;
	DecToHex(ans);
	DecToOct(ans);
}
void calculator::HexToDec(string liczba) {

	int ans{};
	int base = 1;
	for (size_t i = liczba.size(); i > 0; i--) {
		if ((liczba[i - 1] >= '0') && (liczba[i - 1] <= '9')) {
			ans += (int(liczba[i - 1]) - 48) * base;
			base = base * 16; //increment base (16^0) to (16^1) ...
		}
		else if ((liczba[i - 1] >= 'A') && (liczba[i - 1] <= 'F')) {
			ans += (int(liczba[i - 1]) - 55) * base;
			base = base * 16;
		}
		else if ((liczba[i - 1] >= 'a') && (liczba[i - 1] <= 'f')) {
			ans += (int(liczba[i - 1]) - 87) * base;
			base = base * 16;
		}
	}
	cout << "0d" << ans;
	DecToOct(ans);
	DecToBin(ans);
	
}
void calculator::OctToDec(string liczba) {
	int ans{};
	int base = 1;
	for (size_t i = liczba.size(); i > 0; i--) {
		ans += (int(liczba[i - 1]) - 48) * base;
		base = base * 8; //increment base (8^0) to (8^1) ...
	}

	cout << "0d" << ans << endl;
	DecToBin(ans);
	DecToHex(ans);
}
void calculator::DecToBin(int ans) {
	string r{};
	while (ans > 0) {
		r += (ans % 2 == 0 ? "0" : "1");
		ans = ans / 2;
	}
	cout << "0b";
	//reverse string
	for (int i = r.size(); i > 0; i--) {
		cout << r[i - 1];
	}
	cout << "\n";
}
void calculator::DecToHex(int ans) {
	string r;

	while (ans != 0) {
		int variable = 0;
		variable = ans % 16;
		if (variable < 10) {
			r += variable + 48;
		}
		else {
			r += variable + 55;
		}
		ans = ans / 16;
	}
	//reverse string
	cout << "0x";
	for (int i = r.size(); i > 0; i--) {
		cout << r[i - 1];
	}

};
void calculator::DecToOct(int ans) {
	string r;

	while (ans != 0) {
		int variable = 0;
		variable = ans % 8;
		r += variable + 48;
		ans = ans / 8;
	}
	//reverse string
	cout << endl;
	cout << "0o";
	for (int i = r.size(); i > 0; i--) {
		cout << r[i - 1];
	}
	cout << endl;
}