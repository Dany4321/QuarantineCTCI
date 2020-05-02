#pragma once
#include <string>
#include<map>
#include <algorithm>
using namespace std;
class Exercice {
public:
	bool static IsUnique(string s);
	bool static CheckPermutation(string s1, string s2);
	string static Urlify(string s, int length);
	bool static PalindromePermutation(string s);
	bool static OneAway(string original, string edited);
	string static StringCompression(string s);
	static int** RotateMatrix(int** image, int N);
};