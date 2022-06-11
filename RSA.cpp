#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ios>
#include <array>
#include <random>
#include <numeric>
#include <vector>

using namespace std;

long long int generateOpenExponent(long long int fpq);
long long int powerStrings(string sa, string sb, long long int MOD);

vector<int> encryptRSA(string text, array<long long int, 2> publicKey){
	vector<int> cryptoText;
	for (int i = 0; i < text.size(); i++) {
		cryptoText.push_back((int)(text[i]));
	}
	cout << "Text as ints ";
	for (auto i : cryptoText)
		cout << i << ' ';
	cout << "\n";
	for (int i = 0; i < cryptoText.size(); i++) {
		cryptoText[i] = powerStrings(to_string(cryptoText[i]), to_string(publicKey[1]), publicKey[0]);
	}
	cout << "Encrypted text ";
	for (auto i : cryptoText)
		cout << i << ' ';
	cout << "\n";
	return cryptoText;
}

string decryptRSA(vector<int> text, array<long long int, 2> privateKey) {
	/*string messsage = " ";
	unsigned long long cryptoMessage = stoll(text);
	unsigned long long messageInt = (cryptoMessage ^ privateKey[1]) % privateKey[0];
	text = to_string(messageInt);
	int messageSize = text.length();
	while (messageSize != 0) {
		if (text[text.length() - messageSize] == 1) {
			messsage += to_string(stoi(text.substr(text.length() - messageSize, 3)));
			messageSize = messageSize - 3;
		}
		else {
			messsage += to_string(stoi(text.substr(text.length() - messageSize, 2)));
			messageSize = messageSize - 2;
		}
	}
	return messsage;*/
	string decryptedText = "";
	cout << "\n";
	for (int i = 0; i < text.size(); i++) {
		text[i] = powerStrings(to_string(text[i]), to_string(privateKey[1]), privateKey[0]);
	}
	cout << "Text as ints ";
	for (auto i : text) {
		cout << i << ' ';
		decryptedText += ((char)i);
	}
	return decryptedText;
}

string decryptRSA(string text, array<long long int, 2> privateKey) {
	vector<int> encryptedText;
	for (int i = 0; i < text.size(); i++) {
		encryptedText.push_back((int)(text[i]));
	}
	text = decryptRSA(encryptedText, privateKey);
	return text;
}

array<long long int, 2> RSAKeyGen(bool isPublic) {
	long long int p, q;
	cout << "Choose two prime numbers ";							//Entering p and q
	cin >> p;
	cin >> q;
	long long int n = p * q;
	long long int fpq = (p - 1)*(q - 1);
	long long int encryptionExponent;
	cout << "Generate(0) or choose(1) open exponent? ";				//open exponent calculation
	cin >> encryptionExponent;
	if (encryptionExponent == 1) {
		cout << "Enter open exponent (1 < e <" << fpq << ") and relatively prime to " << fpq << " ";
		cin >> encryptionExponent;
		if (1 > encryptionExponent || fpq < encryptionExponent || fpq%encryptionExponent == 0) {
			encryptionExponent = generateOpenExponent(fpq);
		}
	}
	else
	{
		encryptionExponent = generateOpenExponent(fpq);
	}
	double k = 0;
	double d = 0.1;
	double e = (float)encryptionExponent;
	while((long long int)d != d){
		d = ((k * fpq) + 1)/e;
		k++;
	}
	long long int decryptionExponent = (long long int)d;
	array<long long int, 2> publicKey = { n, encryptionExponent};
	array<long long int, 2> privateKey = { n,  decryptionExponent };
	cout << "Public key ( " << n << "; " << encryptionExponent << ")\nPrivate key ( " << n << "; " << decryptionExponent << ")\n";
	if (isPublic == 1) {
		return publicKey;
	}
	else if (isPublic == 0) {
		return privateKey;
	}
}

long long int generateOpenExponent(long long int fpq) {
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dist(2, fpq - 1);
	long long int openExponent = dist(gen);
	if ((gcd(openExponent, fpq)) != 1) {
		openExponent = generateOpenExponent(fpq);
	}
	return openExponent;
}

long long int powerLL(long long int x, long long int n, long long int MOD)
{
	long long int result = 1;
	while (n) {
		if (n & 1)
			result = result * x % MOD;
		n = n / 2;
		x = x * x % MOD;
	}
	return result;
}

long long int powerStrings(string sa, string sb, long long int MOD)
{
	long long int a = 0, b = 0;
	for (int i = 0; i < sa.length(); i++)
		a = (a * 10 + (sa[i] - '0')) % MOD;
	for (int i = 0; i < sb.length(); i++)
		b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
	return powerLL(a, b, MOD);
}