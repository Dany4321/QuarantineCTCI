#include "Chapter1.h"
#include "iostream";
bool Chapter1::IsUnique(string s) {
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
bool Chapter1::CheckPermutation(string s1, string s2) {
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
string Chapter1::Urlify(string s,int length) {
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
bool Chapter1::PalindromePermutation(string s) {
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
bool  Chapter1::OneAway(string original, string edited) {
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
string Chapter1::StringCompression(string s) {
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

int**  Chapter1::RotateMatrix(int** image, int N) {
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
//O(n^2)
int**  Chapter1:: ZeroMatrix(int** matrix, int width, int heigth) {
	bool* cols = new bool[width];
	bool* rows = new bool[heigth];
	
	for (int k = 0; k < width; k++){
		cols[k] = false;
	}
	for (int k = 0; k < heigth; k++) {
		rows[k] = false;
	}
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[i][j] == 0) {
				cols[j] = true;
				rows[i] = true;
			}
		}
	}
	for (int k = 0; k < heigth; k++) {
		for (int l = 0; l < width; l++) {
			if (rows[k]) {
				matrix[k][l] = 0;
			}
			else if (cols[l]) {
				matrix[k][l] = 0;
			}
		}
		
	}
	return matrix;
}
int  Chapter1::StringRotationHeuristic(string s1, string s2) {
	int max = 0;
	for (int i = 0; i < s1.length(); i++) {
		int score = 0;
		if ((s1.length() - i) < max) {
			break;
		}
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				++score;
			}
			else {
				break;
			}
		}
		if (score > max) {
			max = score;
		}
	}
	return max;
}
bool Chapter1::StringRotation(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return false;
	}
	int max = 0;
	int bestMatchS1Start = 0;
	for (int i = 0; i < s1.length(); i++) {
		int k = i;
		int score = 0;
		for (int j = 0; j < s2.length(); j++) {
			int l = j;
			score = 0;
			while (l<s2.length()) {
				if (s1[k] == s2[l]) {
					++score;
					++k;
				}
				else if (score > max) {
					max = score;
					bestMatchS1Start = i;
				}
				else {
					break;
				}
				++l;
			}
			if (score > max) {
				max = score;
				bestMatchS1Start = i;
			}

		}
	}
	if (bestMatchS1Start > 0) {
		string diff1 = s1;
		string diff2 = s2;
		string common = s1.substr(bestMatchS1Start, max);
		diff1 = diff1.replace(bestMatchS1Start, max, "");
		int i = diff2.find(common);
		if (i != string::npos) {
			diff2.erase(i, common.length());
		}
		
		return (diff1 == diff2);
	}
	else {
		return false;
	}
	
}