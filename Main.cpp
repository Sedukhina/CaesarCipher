#define _CRT_SECURE_NO_WARNINGS
#include "Ciphers.h"

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
		printf("Press 0 to see your text\nPress 1 to encrypt your text\nPress 2 to decrypt your text\nPress 3 to change your text\nPress 4 to convert\nPress 5 to exit\n");
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
			printf("Pick cipher\n1 - Caesar\n2 - Trithemius(quadratic)\n3 - Vigenere\n4 - XOR\n5 - DES\n6 - RSA\n");
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
			if (cipher == 53) {
				int roundText = txt.length() % 8;					//adding characters so text deviding on blocks without remainder
				for (int i = 0; i < (8 - roundText); ++i) {
					txt += "A";
				}
				string key = changeKey();
				int which;
				cout << "Key\n1 - is binary\n2 - is hex\n3 - is decimal\n\n";
				cin >> which;
				if (which == 2) {
					key = hex_to_binary(key);
				}
				else if (which == 3) {
					key = string_to_binary(key);
				}
				txt = encryptDES(txt, key);
				text = &txt[0];
				n = txt.length();
				print(text);
			}
			if (cipher == 54) {
				int gen;
				cout << "Generate(0) or enter(1) open key? ";				
				cin >> gen;
				array<long long int, 2> publicKey;
				if (gen == 1) {
					cout << "Enter n ";
					cin >> publicKey[0];
					cout << "Enter encryption exponent ";
					cin >> publicKey[1];
				}
				else {
					publicKey = RSAKeyGen(1);
				}
				txt = encryptRSA(txt, publicKey);
				text = &txt[0];
				n = txt.length();
			}
		}
		if (choose == 50)
		{
			printf("Pick cipher\n1 - Caesar\n2 - Trithemius(quadratic)\n3 - Vigenere\n4 - XOR\n5 - DES\n6 - RSA\n");
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
			if (cipher == 53) {
				string key = changeKey();
				int which;
				cout << "Key\n1 - is binary\n2 - is hex\n3 - is decimal\n\n";
				cin >> which;
				if (which == 2) {
					key = hex_to_binary(key);
				}
				else if (which == 3) {
					key = string_to_binary(key);
				}
				txt = decryptDES(txt, key);
				text = &txt[0];
				n = txt.length();
				print(text);
			}
			if (cipher == 54) {
				int gen;
				cout << "Generate keys(0) or decrypt text(1) ";
				cin >> gen;
				if (gen == 1) {
					array<long long int, 2> privateKey;
					cout << "Enter your private key \nEnter n ";
					cin >> privateKey[0];
					cout << "Enter decryption exponent ";
					cin >> privateKey[1];
					txt = decryptRSA(text, privateKey);
					text = &txt[0];
					n = txt.length();
					print(text);
				}
				else {
					RSAKeyGen(0);
				}
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
			int which;
			cout << "1 - binary to hex\n2 - hex to binary\n3 - binary to string\n4 - string to binary\n\n";
			cin >> which;
			if (which == 1) {
				txt = binary_to_hex(txt);
			} 
			else if (which == 2) {
				txt = hex_to_binary(txt);
			}
			else if (which == 4) {
				txt = string_to_binary(txt);
			}
			else if (which == 3) {
				txt = binary_to_string(txt);
			}
			text = &txt[0];
		}
		if (choose == 53)
		{
			return 0;
		}
	}
}

void print(char* text) {
	cout << text <<"\n";
}

string binary_to_hex(string text) {
	string res = "";
	for (int i = 0; i < text.length(); i+=4) {
		string m = text.substr(i, 4);
		if (m == "0000") {
			res += "0";
		}
		else if (m == "0001") {
			res += "1";
		}
		else if (m == "0010") {
			res += "2";
		}
		else if (m == "0011") {
			res += "3";
		}
		else if (m == "0100") {
			res += "4";
		}
		else if (m == "0101") {
			res += "5";
		}
		else if (m == "0110") {
			res += "6";
		}
		else if (m == "0111") {
			res += "7";
		}
		else if (m == "1000") {
			res += "8";
		}
		else if (m == "1001") {
			res += "9";
		}
		else if (m == "1010") {
			res += "A";
		}
		else if (m == "1011") {
			res += "B";
		}
		else if (m == "1100") {
			res += "C";
		}
		else if (m == "1101") {
			res += "D";
		}
		else if (m == "1110") {
			res += "E";
		}
		else if (m == "1111") {
			res += "F";
		}
	}
	return res;
}

string hex_to_binary(string text) {
	string res = "";
	for (int i = 0; i < text.length(); i++) {
		string m = text.substr(i, 1);
		if (m == "0") {
			res += "0000";
		}
		else if (m == "1") {
			res += "0001";
		}
		else if (m == "2") {
			res += "0010";
		}
		else if (m == "3") {
			res += "0011";
		}
		else if (m == "4") {
			res += "0100";
		}
		else if (m == "5") {
			res += "0101";
		}
		else if (m == "6") {
			res += "0110";
		}
		else if (m == "7") {
			res += "0111";
		}
		else if (m == "8") {
			res += "1000";
		}
		else if (m == "9") {
			res += "1001";
		}
		else if (m == "A") {
			res += "1010";
		}
		else if (m == "B") {
			res += "1011";
		}
		else if (m == "C") {
			res += "1100";
		}
		else if (m == "D") {
			res += "1101";
		}
		else if (m == "E") {
			res += "1110";
		}
		else if (m == "F") {
			res += "1111";
		}
	}
	return res;
}

string binary_to_string(string text) {
	string res = "";
	while (text.length() % 8 != 0) {
		text += "0";
	}
	for (int i = 0; i < text.length(); i += 8) {
		bitset<8> ch;
		string chr = text.substr(i, 8);
		for (int t = 0; t < 8; t++) {
			string m = chr.substr(t, 1);
			if (m == "0") {
				ch[7 - t] = 0;
			}
			else if (m == "1") {
				ch[7 - t] = 1;
			}
		}
		char a = static_cast<char>(ch.to_ulong());
		res += a;
	}
	return res;
}

string string_to_binary(string text) {
	string res = "";
	for (int m = 0; m < text.length(); m++) {
		string block = text.substr(m, 1);
		bitset<8> blocki = bitset<8>(block.c_str()[0]);
		for (int i = 7; i > -1; i--) {
			res += to_string(blocki[i]);
		}
	}
	return res;
}
