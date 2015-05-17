#pragma once
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class OneTimePad {
private:
	string randomKey;
	void genRandomKey(int length);
public:
	OneTimePad();
	OneTimePad(string key);
	~OneTimePad();
	const string getRandomKey() const;
	const string cipher(const string plainText);
	const string decipher(const string cipherText);
};