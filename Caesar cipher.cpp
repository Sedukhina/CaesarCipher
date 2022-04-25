#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void print(char* text);

void encryptCaesar(char* text, int offset, int n) {

	for (int i = 0; i < n; ++i) {
		if ((text[i] >= 65) && (text[i] <= 90)) {
			text[i] = text[i] + offset;
			if (text[i] < 65) {
				text[i] = text[i] + 26;
			}
			if (text[i] > 90) {
				text[i] = text[i] - 26;
			}
		}
		else if ((text[i] >= 97) && (text[i] <= 122)) {
			text[i] = text[i] + offset;
			if (text[i] > 122) {
				text[i] = text[i] - 26;
			}
			if (text[i] < 97) {
				text[i] = text[i] + 26;
			}
		}
	}
}

void decryptCaesar(char text[], int n) {
	for (int i = 0; i < 26; ++i) {
		cout << "Offset " << i + 1 << " Your text:	";
		encryptCaesar(text, -1, n);
		print(text);
	}
}

int changeOffset() {
	cout << "Enter an offset\n";
	int offset;
	scanf("%i", &offset);
	offset = offset % 26;
	return offset;
}