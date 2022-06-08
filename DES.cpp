#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bitset<32> f(bitset<32> RHalf, bitset<48> key);

void print(char* text);
const int IP[64] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
const int IPmin1[64] = { 40, 8,	48,	16,	56,	24,	64,	32,	39,	7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4,	44,	12,	52,	20,	60,	28,	35,	3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9,	49,	17,	57,	25,};
int permutingKey[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
const int ETable[48] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
const int keyPerm[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
/*const int SBox1[64] = { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 };
const int SBox2[64] = { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };
const int SBox3[64] = { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 };
const int SBox4[64] = { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 };
const int SBox5[64] = { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 };
const int SBox6[64] = { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 };
const int SBox7[64] = { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 };
const int SBox8[64] = { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };*/
const int SBoxs[8][64] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }, { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }, { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }, { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }, { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }, { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }, { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }, { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
const int P[32] = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };

string encryptDES(string text, string skey) {
	string result = "";
	string start = "";
	bitset<64> key64;
	while (skey.size() < 16) {
		skey += skey;
	}
	for (int i = 0; i < 61; i += 4) {					//converting key to binary
		bitset<4> keyi = bitset<4>(skey.c_str()[i/4]);
		key64[63 - i] = keyi[3];
		key64[62 - i] = keyi[2];
		key64[61 - i] = keyi[1];
		key64[60 - i] = keyi[0];
	}
	bitset<56> key;
	for (int setkey = 0; setkey < 56; setkey++) {		//permuting 56-bit key
		key[55 - setkey] = key64[64 - permutingKey[setkey]];
		//cout << setkey+1 << " "<< key64[63-setkey] << " ";
	}
	cout << "\n64 bits key " << key64 << "\n56 bits key " << key << "\n";
	bitset<28> C;
	bitset<28> D;
	for (int setkey = 0; setkey < 28; setkey++) {		//parts of key
		C[setkey] = key[setkey+28];
		D[setkey] = key[setkey];
	}
	cout << "\nC0 " << C.to_string() << "\nD0 " << D.to_string() << "\n";
	int n = text.length() / 64;							//diving text on blocks
	for (int i = 0; i < n; ++i) {
		string blockStr = text.substr(i*64, 64);
		bitset<64> block;
		/*for (int setBitset = 0; setBitset < 64; setBitset += 4) {			//convering block to binary
			bitset<4> blocki = bitset<4>(blockStr.c_str()[setBitset/4]);
			block[60-setBitset] = blocki[0];
			block[61-setBitset] = blocki[1];
			block[62-setBitset] = blocki[2];
			block[63-setBitset] = blocki[3];
		}*/
		for (int i = 0; i < 64; i++) {
			string m = blockStr.substr(i, 1);
			if (m == "0") {
				block[63 - i] = 0;
			}
			else if (m == "1") {
				block[63 - i] = 1;
			}
		}
		cout <<"\n" << i + 1 << " block " << block << "\n\n";
		bitset<64> blockCopy = block;
		for (int p = 0; p < 64; p++) {										//initial permutation
			block[63-p] = blockCopy[64-IP[p]];
			//cout << p+1 << " "<< blockCopy[63-p] << " ";
		}
		cout << i + 1 << " block after initial permutation " << block << "\n\n";
		for (int round = 0; round < 16; round++) {							//startring 16 rounds(main algorithm)
			if (round == 0 || round == 1 || round == 8 || round == 15) {	//shifting keys
				bitset<1> c;
				bitset<1> d;
				c[0] = C[27];
				d[0] = D[27];
				C = C << 1;
				D = D << 1;
				C[0] = c[0];
				D[0] = d[0];
			}
			else
			{
				bitset<2> c;
				bitset<2> d;
				c[0] = C[27];
				c[1] = C[26];
				d[0] = D[27];
				d[1] = D[26];
				C = C << 2;
				D = D << 2;
				C[1] = c[0];
				C[0] = c[1];
				D[1] = d[0];
				D[0] = d[1];
			}
			cout << "C" << round + 1 << " " << C << "\n\n" << "D" << round + 1 << " " << D << "\n\n";
			for (int setkey = 0; setkey < 28; setkey++) {		
				key[setkey+28] = C[setkey];
				key[setkey] = D[setkey];
			}
			cout << "key 56 " << round + 1 << " " << key << "\n\n";
			bitset<48> keyn;
			for (int setkey = 0; setkey < 48; setkey++) {
				keyn[47-setkey] = key[56-keyPerm[setkey]];
			}
			cout << "key 48 " << round + 1 << " " << keyn << "\n\n";
			bitset<32> RHalf;
			for (int a = 0; a < 32; ++a) {									//extracting right half 				
				RHalf[a] = block[a];
			}
			cout << "rhalf" << round + 1 << " " << RHalf << "\n\n";
			bitset<32> RHalfPermuted = f(RHalf, keyn);						//feistel function 
			for (int a = 0; a < 32; ++a) {									//XORing new right half with old left half to get new right half
				block[a] = block[a+32]^RHalfPermuted[a];
			}
			for (int a = 0; a < 32; ++a) {									//new left half is old right half
				block[a+32] = RHalf[a];
			}
			cout << i + 1 << " block after " << round + 1 << " round " << block.to_string() << "\n\n";
		}																	//ending of 16 rounds
		for (int setBitset = 0; setBitset < 64; setBitset++) {
			blockCopy[63- setBitset] = block[64-IPmin1[setBitset]];
		};
		result += blockCopy.to_string();
		cout << i+1 << " block final " << blockCopy.to_string() << "\n\n";
	}
	return result;
}

string decryptDES(string text, string skey) {
	bitset<64> key64;
	string result = "";
	while (skey.size() < 16) {
		skey += skey;
	}
	for (int i = 0; i < 61; i += 4) {					//converting key to binary
		bitset<4> keyi = bitset<4>(skey.c_str()[i/4]);
		key64[63 - i] = keyi[3];
		key64[62 - i] = keyi[2];
		key64[61 - i] = keyi[1];
		key64[60 - i] = keyi[0];
	}
	bitset<56> key;
	for (int setkey = 0; setkey < 56; setkey++) {		//permuting 56-bit key
		key[55 - setkey] = key64[64 - permutingKey[setkey]];
	}
	bitset<28> C;
	bitset<28> D;
	for (int setkey = 0; setkey < 28; setkey++) {		//parts of key
		C[setkey] = key[setkey + 28];
		D[setkey] = key[setkey];
	}
	//cout << "\nC16 " << C.to_string() << "\nD16 " << D.to_string() << "\n";
	int n = text.length() / 64;
	for (int i = 0; i < n; ++i) {						//dividing on parts
		string blockStr = text.substr(i*64, 64);		//converting binary string to bitset
		bitset<64> block;
		for (int i = 0; i < 64; i++) {
			string m = blockStr.substr(i, 1);
			if (m == "0") {
				block[63 - i] = 0;
			}
			else if (m == "1") {
				block[63 - i] = 1;
			}
		}
		bitset<64> blockCopy = block;
		cout << "\n" << i + 1 << " block " << block << "\n\n";
		for (int p = 0; p < 64; p++) {										//permutation
			block[63 - p] = blockCopy[64 - IP[p]];
		}
		cout << "\n" << i + 1 << " block after permutation " << block.to_string() << "\n\n";
		for (int round = 0; round < 16; round++) {
			if (round == 1 || round == 8 || round == 15) {	//shifting keys
				bitset<1> c;
				bitset<1> d;
				c[0] = C[0];
				d[0] = D[0];
				C = C >> 1;
				D = D >> 1;
				C[27] = c[0];
				D[27] = d[0];
			}
			else if (round == 0) {
			}
			else
			{
				bitset<2> c;
				bitset<2> d;
				c[0] = C[0];
				c[1] = C[1];
				d[0] = D[0];
				d[1] = D[1];
				C = C >> 2;
				D = D >> 2;
				C[26] = c[0];
				C[27] = c[1];
				D[26] = d[0];
				D[27] = d[1];
			}
			cout << "C" << 16-round << " " << C << "\n\n" << "D" << 16 - round << " " << D << "\n\n";
			for (int setkey = 0; setkey < 28; setkey++) {
				key[setkey + 28] = C[setkey];
				key[setkey] = D[setkey];
			}
			bitset<48> keyn;
			for (int setkey = 0; setkey < 48; setkey++) {
				keyn[47 - setkey] = key[56 - keyPerm[setkey]];
			}
			bitset<32> RHalf;
			for (int a = 0; a < 32; ++a) {									//extracting old right half 				
				RHalf[a] = block[a+32];
			}
			cout << "rhalf" << round + 1 << " " << RHalf << "\n\n";
			bitset<32> RHalfPermuted = f(RHalf, keyn);						//feistel function 
			for (int a = 31; a > -1; --a) {									//XORing new right half with old right half to get old left half
				block[a+32] = block[a] ^ RHalfPermuted[a];
			}
			for (int a = 0; a < 32; ++a) {									
				block[a] = RHalf[a];
			}
			cout << i + 1 << " block after " << round + 1 << " round " << block.to_string() << "\n\n";
		}
		for (int p = 0; p < 64; p++) {										//permutation
			blockCopy[63-p] = block[64 - IPmin1[p]];
		}
		result += blockCopy.to_string();
		C = C >> 1;
		D = D >> 1;
	}
	return result;
}

bitset<32> f(bitset<32> RHalf, bitset<48> key) {
	bitset<48> extendedR;
	for (int i = 0; i < 48; ++i) {											//extending bitset
		extendedR[47-i] = RHalf[32 - ETable[i]];
	}
	extendedR = extendedR ^ key;											//XORing extended bitset with key 
	bitset<32> RHalfPermuted;
	for (int i = 7; i > -1; --i) {											//converting 48 bits to 32 with sboxes
		bitset<4> extract4;
		bitset<2> extract2;
		for (int a = 4; a > 0; --a) {
			extract4[a-1] = extendedR[a + i * 6];
		}
		extract2[1] = extendedR[0 + i * 6];
		extract2[0] = extendedR[5 + i * 6];
		int n = 8 * (int)extract4[3] + 4 * (int)extract4[2] + 2 * (int)extract4[1] + (int)extract4[0];
		int m = 2 * (int)extract2[1] + (int)extract2[0];
		int nm = SBoxs[7-i][m * 16 + n];
		bitset<4> resBitset;
		resBitset = nm;
		for (int a = 3; a > -1; --a) {
			RHalf[i * 4 + a] = resBitset[a];
		}
	}
	for (int a = 31; a > -1; --a) {											//permuting bits
		RHalfPermuted[a] = RHalf[32 - P[31-a]];
	}
	return RHalfPermuted;
}

