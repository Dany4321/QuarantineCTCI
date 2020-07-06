#pragma once
#include "string.h"
#include "MyStringBuilder.h"
using namespace std;
class Chapter5 {
public:
	static void Insertion(int N, int M, int i, int j);
	static string BinaryToString(double n);
	static int FlipBitToWin(int N);
	static void NextNumber(unsigned int N);
	static int Conversion(int A, int B);
	static int PairwiseSwap(int A);
	static void DrawLine(char* screen, int width, int x1, int x2, int y);
};