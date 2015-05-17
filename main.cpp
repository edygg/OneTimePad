#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include "OneTimePad.hpp"
using namespace std;

const int BUFFER_SIZE = 4096;

int main(int argc, char** argv) {
	if (argc == 3) {
		if (strcmp(argv[1], "--cipher") == 0) {
			ifstream inputFile(argv[2]);
			if (inputFile.is_open()) {
				string line;
				ofstream cipherTextFile("cipher");
				ofstream keyFile("key");
				while (getline(inputFile, line)) {
					OneTimePad cipherMethod;
					cipherTextFile << cipherMethod.cipher(line);
					keyFile << cipherMethod.getRandomKey();
				}

				keyFile.flush();
				cipherTextFile.flush();
			} else {
				cerr << "File not found." << endl;
				return EXIT_FAILURE;
			}
		} else {
			cerr << "Invalid params." << endl;
			return EXIT_FAILURE;
		}
	} else if (argc == 5) {
		if (strcmp(argv[1], "--decipher") == 0 && strcmp(argv[3], "--key") == 0) {
			ifstream cipherTextFile(argv[2]);
			ifstream keyFile(argv[4]);
			if (cipherTextFile.is_open() && keyFile.is_open()) {
				string line;
				stringstream ss;
				
				while (getline(keyFile, line))
					ss << line;
				string key = ss.str();
				
				ss.str("");
				
				while (getline(cipherTextFile, line))
					ss << line;
				string cipherText = ss.str();

				OneTimePad cipherMethod(key);
				ofstream decipherFile("decipher");
				decipherFile << cipherMethod.decipher(cipherText);
				decipherFile.flush();
			} else {
				cerr << "File not found." << endl;
				return EXIT_FAILURE;
			}
		} else {
			cerr << "Invalid params." << endl;
			return EXIT_FAILURE;
		}
	} else {
		cerr << "Invalid params." << endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}