#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<ios>
#include<limits>

using namespace std;

void print(char* text);
void encrypt(char* text, int offset, int n);
void decrypt(char text[], int n);
int changeOffset();

int main() {
	printf("Enter your text\n");
	string txt;
	getline(cin, txt);
	char* text;
	text = &txt[0];
	int n = txt.length();
	char choose;
	while (1)
	{
		printf("Press 0 to see your text\nPress 1 to encrypt your text\nPress 2 to decrypt your text\nPress 3 to change your text\nPress 4 to exit\n");
		scanf("%c", &choose);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choose == 48)
		{
			print(text);
		}
		if (choose == 49)
		{
			encrypt(text, changeOffset(), n);
			print(text);
		}
		if (choose == 50)
		{
			decrypt(text, n);
		}
		if (choose == 51)
		{
			cout << "Enter your text\n";
			getline(cin, txt);
			text = &txt[0];
			n = txt.length();
			char choose;
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

void encrypt(char* text, int offset, int n) {
	
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

void decrypt(char text[], int n) {
	for (int i = 0; i < 26; ++i) {
		cout << "Offset "<< i+1 <<" "<< "Your text:	";
		encrypt(text, -1, n);
		print(text);
	}
}

int changeOffset(){
	cout << "Enter an offset\n";
	int offset;
	scanf("%i", &offset);
	offset = offset % 26;
	return offset;
}