#include "OneTimePad.hpp"

OneTimePad::OneTimePad() {
	this->randomKey = "";
	srand(time(0));
}

OneTimePad::OneTimePad(string key) {
	this->randomKey = key;
}

OneTimePad::~OneTimePad() { 
	/* Nothing */ 
}

void OneTimePad::genRandomKey(int length) {
	stringstream ss;

	for(int i = 0; i < length; i++) {
		char tmp = (char) ((rand() % 127) + 1);
		ss << tmp;
	}

	this->randomKey = ss.str();
}

const string OneTimePad::getRandomKey() const {
	return this->randomKey;
}

const string OneTimePad::cipher(const string plainText) {
	if (this->randomKey == "" || this->randomKey.length() != plainText.length())
		genRandomKey(plainText.length());
	
	stringstream ss; 
	for (int i = 0; i < plainText.length(); i++)
		ss << (char) (plainText[i] ^ this->randomKey[i]); 

	return ss.str();
}

const string OneTimePad::decipher(const string cipherText) {
	if (this->randomKey == "")
		return "";

	if (this->randomKey.length() != cipherText.length())
		return "";

	stringstream ss;
	for (int i = 0; i < cipherText.length(); i++)
		ss << (char) (this->randomKey[i] ^ cipherText[i]);
	return ss.str();
}