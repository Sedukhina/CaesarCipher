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
string string_to_hex(std::string& in);
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
vector<int> encryptRSA(string text, array<long long int, 2> publicKey);
string decryptRSA(vector<int> text, array<long long int, 2> privateKey);
string decryptRSA(string text, array<long long int, 2> privateKey);
string hex_to_binary(string text);
array<long long int, 2> RSAKeyGen(bool isPublic);
