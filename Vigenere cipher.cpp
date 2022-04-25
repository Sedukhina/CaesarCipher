#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string>

using namespace std;

void print(char* text);
string changeKey();

void encryptVigenere(char* text, string Key, int n) {
	char* key;
	key = &Key[0];
	int k = Key.length();
	int b = 0;
	int a = key[0];
	for (int i = 0; i < n; ++i) {
		if ((text[i] >= 65) && (text[i] <= 90)) {
			if ((a >= 65) && (a <= 90)) {
				text[i] = text[i] + a - 65;
			}
			else if ((a >= 97) && (a <= 122)) {
				text[i] = text[i] + a - 97;
			}
			if (text[i] < 65) {
				text[i] = text[i] + 26;
			}
			if (text[i] > 90) {
				text[i] = text[i] - 26;
			}
			b++;
			if (b == k) {
				b = 0;
			}
			a = key[b];
		}
		else if ((text[i] >= 97) && (text[i] <= 122)) {
			if ((a >= 65) && (a <= 90)) {
				text[i] = text[i] + a - 65;
			}
			else if ((a >= 97) && (a <= 122)) {
				text[i] = text[i] + a - 97;
			}
			if (text[i] > 122) {
				text[i] = text[i] - 26;
			}
			if (text[i] < 97) {
				text[i] = text[i] + 26;
			}
			b++;
			if (b == k) {
				b = 0;
			}
			a = key[b];
		}
	}
}

void decryptVigenere(char text[], string Key, int n) {
	char* key;
	key = &Key[0];
	int k = Key.length();
	int b = 0;
	int a = key[0];
	for (int i = 0; i < n; ++i) {
		if ((text[i] >= 65) && (text[i] <= 90)) {
			if ((a >= 65) && (a <= 90)) {
				text[i] = text[i] - a + 65;
			}
			else if ((a >= 97) && (a <= 122)) {
				text[i] = text[i] - a + 97;
			}
			if (text[i] < 65) {
				text[i] = text[i] + 26;
			}
			if (text[i] > 90) {
				text[i] = text[i] - 26;
			}
			b++;
			if (b == k) {
				b = 0;
			}
			a = key[b];
		}
		else if ((text[i] >= 97) && (text[i] <= 122)) {
			if ((a >= 65) && (a <= 90)) {
				text[i] = text[i] - a + 65;
			}
			else if ((a >= 97) && (a <= 122)) {
				text[i] = text[i] - a + 97;
			}
			if (text[i] > 122) {
				text[i] = text[i] - 26;
			}
			if (text[i] < 97) {
				text[i] = text[i] + 26;
			}
			b++;
			if (b == k) {
				b = 0;
			}
			a = key[b];
		}
	}
}

string changeKey() {
	char c;
	scanf("%c", &c);
	printf("Enter your key\n");
	string key;
	getline(cin, key);
	return key;
}