#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void print(char* text);
int changeParameter(int param);

void encryptTrithemius(char* text, int c, int b, int a, int n) {
	int texti;
	for (int i = 0; i < n; ++i) {
		if ((text[i] >= 65) && (text[i] <= 90)) {
			texti = int(text[i]) + a * (i + 1) * (i + 1) + b * (i + 1) + c;
			while (texti < 65) {
				texti = texti + 26;
			}
			while (texti > 90) {
				texti = texti - 26;
			}
			text[i] = texti;
		}
		else if ((text[i] >= 97) && (text[i] <= 122)) {
			texti = int(text[i]) + a * (i + 1) * (i + 1) + b * (i + 1) + c;
			while (texti > 122) {
				texti = texti - 26;
			}
			while(texti < 97) {
				texti = texti + 26;
			}
			text[i] = texti;
		}
	}
}

void decryptTrithemius(char text[], int n) {
	cout << "Enter parameters maximum\n";
	int maxa = changeParameter(1) + 1;
	int maxb = changeParameter(2) + 1;
	int maxc = changeParameter(3) + 1;
	for (int a = 0; a < maxa; ++a) {
		for (int b = 0; b < maxb; ++b) {
			for (int c = 0; c < maxc; ++c) {
				cout << "A = " << a << " B = "<< b << " C = " << c << " Your text:	";
				encryptTrithemius(text, -c, -b, -a, n);
				print(text);
				encryptTrithemius(text, c, b, a, n);
			}
		}
	}
}

int changeParameter(int param) {
	if (param == 1) {
		cout << "Enter first parameter\n";
	}
	if (param == 2) {
		cout << "Enter second parametr\n";
	}
	if (param == 3) {
		cout << "Enter third parametr\n";
	}
	int parameter;
	scanf("%i", &parameter);
	return parameter;
}