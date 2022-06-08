#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void print(char* text);
string changeKey();

string encryptXOR(string text, string key, int n) {
	int k = 0;
	string result;
	bitset<8> binKeyi = bitset<8>(key.c_str()[k]);
	for (int i = 0; i < n; ++i) {
		bitset<8> binTexti = bitset<8>(text.c_str()[i]);
		bitset<8> resulti = binKeyi ^ binTexti;
		cout << resulti.to_string() << " ";
		unsigned long m = resulti.to_ulong();
		unsigned char c = static_cast<unsigned char>(m);
		result += c;
		k++;
		if (k == (key.length() - 1)) {
			k = 0;
		}
		binKeyi = bitset<8>(key.c_str()[k]);
	}
	cout << "\n";
	return result;
}