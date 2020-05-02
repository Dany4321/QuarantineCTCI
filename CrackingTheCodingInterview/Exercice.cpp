#include "Exercices.h"
#include "iostream";
bool Exercice::IsUnique(string s) {
	if (s.length() > 256)
	{
		return false;
	}
	// O(n) en tps, O(n) en espace
	map<char, bool>dict;
	for (char c : s) {
		map<char, bool>::iterator it = dict.find(c);
		if (it != dict.end()) {
			dict.insert(pair<char, bool>(c, true));
		}
		else {
			return false;
		}
	}
	return true;
/*
* O(1) en espace
	if (s.length() < 2)
		return true;
	sort(s.begin(),s.end());// O(nlog(n))
	char c = s[0];
	for (int i = 1; i < s.length();++i) { // O(n)
		if (c != s[i]) {
			return true;
		}
	}
	return false;

*/
}
bool Exercice::CheckPermutation(string s1, string s2) {
	if (s1.length() == s2.length() && s1.length() == 0) {
		//O(n) in time O(1) in space
		// we assume that the string is ascii
		int* charCounter = new int[256];
		for (int i = 0; i < 256; i++) {
			charCounter[i] = 0;
		}
		for (char c : s1) {
			++charCounter[(int)c];
		}
		for (char c : s2) {
			if (charCounter[(int)c] == 0) {
				return false;
			}
			else {
				--charCounter[(int)c];
			}
		}
	}
	else {
		return false;
	}
}
string Exercice::Urlify(string s,int length) {
	string s2 = string(s);
	int idxS2 = 0;
	for (int i = 0; i < length;i++) {
		if ( s[i] == ' ') {
			s2[idxS2++] = '%';
			s2[idxS2++] = '2';
			s2[idxS2++] = '0';
		}
		else {
			s2[idxS2++] = s[i];
		}
	}
	return s2;
}
bool Exercice::PalindromePermutation(string s) {
	for (int k = 0; k < s.length();k++) {
		s[k] = tolower(s[k]);
	}
	int* charCounter = new int[256];
	for (int i = 0; i < 256; i++) {
		charCounter[i] = 0;
	}
	for (char c : s) {
		if(c!=' ')
			++charCounter[(int)c];
	}
	int nbOdd = 0;
	for (int i = 0; i < 256; i++) {
		if (charCounter[i]!= 0 && charCounter[i] % 2 != 0 ) {
			++nbOdd;
		}
		if (nbOdd > 1)
			return false;
	}
	return true;
}
bool  Exercice::OneAway(string original, string edited) {
	int oSize = original.length();
	int eSize = edited.length();
	if (abs(oSize - eSize) > 1) { //one insertion max, one remove max
		return false;
	}
	// histogram creation
	char* oHist = new char[256];
	char* eHist = new char[256];
	for (int i = 0; i < 256; i++) {
		oHist[i] = 0;
		eHist[i] = 0;
	}
	for (char c : original) {
		++oHist[(int)c];
	}
	for (char c : edited) {
		++eHist[(int)c];
	}
	// search for difference
	bool changeFound = false;
	for (int i = 0; i < 256; i++)
	{
		if ((eHist[i] != oHist[i])) {
			if (!changeFound) {
				changeFound = true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
string Exercice::StringCompression(string s) {
	if (s.length() == 0) {
		return "";
	}
	int counter = 1;
	char c = s[0];
	string result = "";
	//O(n)
	for (int i = 1; i < s.length(); i++) {
		if (c != s[i]) {
			result += std::to_string(counter)+c;
			counter = 1;
			c = s[i];
		}
		else {
			++counter;
		}
		if (result.length() >= s.length()) {
			return s;
		}
	}
	result += std::to_string(counter)+c;
	if (result.length() >= s.length()) {
		return s;
	}
	return result;
}

int**  Exercice::RotateMatrix(int** image, int N) {
	int** newImage = new int*[N];
	for (int k = 0; k < N; k++) {
		newImage[k] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			newImage[j][N - i - 1] = image[i][j];
		}
	}
	return newImage;
}