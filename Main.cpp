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
	vector<int> textt;
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
				txt = string_to_hex(txt);
				cout << "\nYour text in hexademical " << txt <<"\n\n";
				txt = hex_to_binary(txt);
				cout << "\nYour text in binary " << txt << "\n\n";
				txt = encryptDES(txt, changeKey());
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
				textt = encryptRSA(txt, publicKey);
				txt = "";
				for (auto i : textt)
					 txt += (char)(i);
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
				txt = decryptDES(txt, changeKey());
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
					if (textt.size() == 0) {
						txt = decryptRSA(text, privateKey);
					}
					else {
						txt = decryptRSA(textt, privateKey);
					}
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
			return 0;
		}
	}
}

void print(char* text) {
	cout << text <<"\n";
}


string string_to_hex(std::string& in) {
	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (size_t i = 0; in.length() > i; ++i) {
		ss << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(in[i]));
	}
	return ss.str();
}

string hex_to_binary(string text) {
	string textbin = "";
	for (int i = 0; i < text.length(); i++) {
		bitset<4> symb = text.c_str()[i];
		textbin += symb.to_string();
	}
	return textbin;
}


