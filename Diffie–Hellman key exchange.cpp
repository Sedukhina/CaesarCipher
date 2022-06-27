#include "Ciphers.h"

using namespace std;

long long DiffieHellmanfinalKey(long long g, long long p, long long B, long long a){
	long long key;
	key = powerStrings(to_string(B), to_string(a), p);
	return key;
}

long long DiffieHellmanPublicKey(long long g, long long p, long long a) {
	long long key;
	key = powerStrings(to_string(g), to_string(a), p);
	return key;
}