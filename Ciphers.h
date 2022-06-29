#pragma once

#include <iostream>
#include <ios>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <array>
#include <vector>

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
string encryptDES(string text, string key);
string decryptDES(string text, string skey);
string encryptRSA(string text, array<long long int, 2> publicKey);
string decryptRSA(string text, array<long long int, 2> privateKey);
string hex_to_binary(string text);
array<long long int, 2> RSAKeyGen(bool isPublic);
string binary_to_hex(string text);
string hex_to_binary(string text);
string binary_to_string(string text);
string string_to_binary(string text);
void RSAbyPieces(string text, array<long long int, 2> publicKey);
void decryptRSAbyPieces(string text, array<long long int, 2> privateKey);
long long int powerStrings(string sa, string sb, long long int MOD);
long long DiffieHellmanfinalKey(long long g, long long p, long long B, long long a);
long long DiffieHellmanPublicKey(long long g, long long p, long long a);
vector<long long> keygen(bool isPublic);
array<long long, 2> encryptElgamal(vector<long long> key, string text);
string decryptElgamal(array<long long, 2> crypto, vector<long long> key);