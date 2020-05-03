#pragma once
#include <string>
#include<map>
#include <algorithm>
using namespace std;
class Chapter1 {
public:
	bool static IsUnique(string s);
	bool static CheckPermutation(string s1, string s2);
	string static Urlify(string s, int length);
	bool static PalindromePermutation(string s);
	bool static OneAway(string original, string edited);
	string static StringCompression(string s);
	static int** RotateMatrix(int** image, int N);
	static int** ZeroMatrix(int** matrix, int width, int heigth);
	bool static StringRotation(string s1, string s2);
private:
	int static StringRotationHeuristic(string s1, string s2);
};