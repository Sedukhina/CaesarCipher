#include "Ciphers.h"
#include <random>
#include <numeric>

using namespace std;
long long generatex(long long p);

vector<long long> keygen(bool isPublic) {
	int p;
	cout << "Enter prime number p ";
	cin >> p;
	long long g = 0;
	while (powerStrings(to_string(g), to_string(p-1), p) != 1) {
		g++;
	}
	long long x;
	cout << "Generate(0) or choose(1) x? ";				
	cin >> x;
	if (x == 1) {
		cout << "Choose x ";
		cin >> x;
	}
	else {
		x = generatex(p);
	}
	long long y = powerStrings(to_string(g), to_string(x), p);
	vector<long long> key = {y, g, p};
	if (isPublic == 0) {
		key.push_back(x);
	}
	return key;
}

array<long long, 2> encryptElgamal(vector<long long> key, string text) {
	long k;
	cout << "Enter your number that smaller than " << key[2]-1 << " and coprime with it ";
	cin >> k;
	long long a = powerStrings(to_string(key[1]), to_string(k), key[2]);
	long long b = powerStrings(to_string(key[0]), to_string(k), key[2]);
	array<long long, 2> result = { a, b };
	return result;
}

string decryptElgamal(array<long long, 2> crypto, vector<long long> key) {
	long long m = (crypto[1] * (crypto[0] ^ ((key[2]) - 1 - (key[3])))) % key[2];
}

long long generatex(long long p) {
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dist(2, p - 1);
	long long int x = dist(gen);
	return x;
}