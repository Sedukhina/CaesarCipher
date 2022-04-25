#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<ios>
#include<limits>

using namespace std;

void print(char* text);
void encryptCaesar(char* text, int offset, int n);
void decryptCaesar(char text[], int n);
int changeOffset();
void encryptTrithemius(char* text, int a, int b, int c, int n);
void decryptTrithemius(char text[], int n);
int changeParameter(int param);
void encryptVigenere(char* text, string Key, int n);
void decryptVigenere(char text[], string Key, int n);
string changeKey();
string encryptXOR(string text, string key, int n);


int main() {
	printf("Enter your text\n");
	string txt;
	getline(cin, txt);
	char* text;
	text = &txt[0];
	int n = txt.length();
	char choose;
	char cipher;
	while (1)
	{
		printf("Press 0 to see your text\nPress 1 to encrypt your text\nPress 2 to decrypt your text\nPress 3 to change your text\nPress 4 to exit\n");
		scanf("%c", &choose);
		if (choose == 10) {
			scanf("%c", &choose);
		}
		if (choose == 48)
		{
			print(text);
		}
		if (choose == 49)
		{
			printf("Pick cipher\n1 - Caesar\n2 - Trithemius(quadratic)\n3 - Vigenere\n4 - XOR\n");
			scanf("%c", &cipher);
			if (cipher == 10) {
				scanf("%c", &cipher);
			}
			if (cipher == 49) {
				encryptCaesar(text, changeOffset(), n);
				print(text);
			}
			if (cipher == 50)
			{
				encryptTrithemius(text, changeParameter(3), changeParameter(2), changeParameter(1), n);
				print(text);
			}
			if (cipher == 51) {
				encryptVigenere(text, changeKey(), n);
				print(text);
			}
			if (cipher == 52)
			{
				txt = encryptXOR(txt, changeKey(), n);
				text = &txt[0];
				n = txt.length();
				print(text);
			}
		}
		if (choose == 50)
		{
			printf("Pick cipher\n1 - Caesar\n2 - Trithemius(quadratic)\n3 - Vigenere\n4 - XOR\n");
			scanf("%c", &cipher);
			if (cipher == 10) {
				scanf("%c", &cipher);
			}
			if (cipher == 49) {
				decryptCaesar(text, n);
			}
			if (cipher == 50)
			{
				decryptTrithemius(text, n);
			}
			if (cipher == 51)
			{
				decryptVigenere(text, changeKey(), n);
				print(text);
			}
			if (cipher == 52)
			{
				txt = encryptXOR(txt, changeKey(), n);
				text = &txt[0];
				n = txt.length();
				print(text);
			}
		}
		if (choose == 51)
		{
			scanf("%c", &choose);
			cout << "Enter your text\n";
			getline(cin, txt);
			text = &txt[0];
			n = txt.length();
		}
		if (choose == 52)
		{
			return 0;
		}
	}
}

void print(char* text) {
	cout << text <<"\n";
}



