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

string encryptRSA(string text, array<long long int, 2> publicKey){
	string cryptoText = "";												//important that m < nm < n
	int which;
	cout << "1 - text is already int\n2 - text is string\n";
	cin >> which;
	if (which == 1) {
		cryptoText += text;
	}
	else {
		for (int i = 0; i < text.length(); i++) {
			cryptoText += to_string(((int)text[i]));
		}
	}
	long long int crypto = powerStrings(cryptoText, to_string(publicKey[1]), publicKey[0]);
	cryptoText = to_string(crypto);
	return cryptoText;
}

void RSAbyPieces(string text, array<long long int, 2> publicKey) {
	string cryptoText = "";												//important that m < nm < n
	int which;
	cout << "1 - Letter by letter\n2 - Reenter\n";
	cin >> which;
	if (which == 1) {
		for (int i = 0; i < text.length(); i++) {
			string smth = to_string(((int)text[i]));
			cout << smth << "\n";
			cryptoText += to_string(powerStrings(smth, to_string(publicKey[1]), publicKey[0]));
			cryptoText += " ";
		}
		cout << cryptoText <<"\n";
	}
	else {
		vector<int> txt;
		cout << "Enter int by int and enter negative number when you finish\n";
		int i = 0;
		cin >> i;
		while (i >= 0) {
			txt.push_back(i);
			cin >> i;
		}
		for (auto i : txt) {
			i = powerStrings(to_string(i), to_string(publicKey[1]), publicKey[0]);
			cout << i << "\n";
		}
	}
}

void decryptRSAbyPieces(string text, array<long long int, 2> privateKey) {
	vector<int> txt;
	cout << "Enter int by int and enter negative number when you finish\n";
	int i = 0;
	cin >> i;
	while (i >= 0) {
		txt.push_back(i);
		cin >> i;
	}
	for (auto i : txt) {
		i = powerStrings(to_string(i), to_string(privateKey[1]), privateKey[0]);
		cout << i << "\n";
	}
}

string decryptRSA(string text, array<long long int, 2> privateKey) {
	string decryptedText = "";
	long long int crypto = powerStrings(text, to_string(privateKey[1]), privateKey[0]);
	decryptedText = to_string(crypto);
	return decryptedText;
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