#include "Chapter5.h"
#include "iostream"
#include <bitset>
#include"MyArray.h";
void Chapter5::Insertion(int N, int M, int i, int j) {
	// we assume i and j are coherents
	int mask_j = (1 << j) - 1;// 0001111
	int mask_i = ~((1 << i) - 1);//111111100
	int finalMask = mask_j & mask_i;//0001100
	finalMask = ~finalMask; // 1110011
	//N: 1011111
	N = N & finalMask; // 1010011
	int shifted_M = M << (j - i + 1);// for example M : 0000010 , we'll have 0001000
	N = N | shifted_M;
}
string Chapter5::BinaryToString(double n) {
	MyStringBuilder builder;
	if (n >= 0 && n <= 1) {
		if (n == 0) {
			return "0";
		}
		if (n == 1) {
			return "1";
		}
		int loopCounter = 0;
		do {
			n = n * 2;
			builder.Append(std::to_string((int)n));
			if (n > 1) {
				n -= 1;
			}
			if (++loopCounter == 32) {
				std::cout << "ERROR" << endl;
				break;
			}

		} while (n != 1);
	}
	return builder.ToString();
}
int Chapter5::FlipBitToWin(int N) {
	string nBinarized = bitset<32>(N).to_string();
	int size = nBinarized.length();
	MyArray<short> zerosPositions;
	for (int i = 0; i < size; ++i) {
		if (nBinarized[i] == '0') {
			zerosPositions.Add(size-i-1);
		}
	}
	int bestPosition = 0;
	int maxNBits = 0;
	for (int j = 0; j < zerosPositions.GetSize(); ++j) {
		int nBits = zerosPositions[j];
		if (j + 1 < zerosPositions.GetSize()) {
			nBits += zerosPositions[(j + 1)] + 1;
		}
		if (j == 0) {
			nBits = size - nBits;
		}
		else {
			nBits = zerosPositions[(j - 1)] - nBits;
		}
		if (nBits > maxNBits) {
			maxNBits = nBits;
			bestPosition = j;
		}
	}
	return bestPosition;
}
void  Chapter5::NextNumber(unsigned int N) {
	string nBinarized = bitset<32>(N).to_string();
	string tmp = nBinarized;
	int size = tmp.length();
	int first1Idx = -1;
	// smallest search
	for (int i = 0; i <size; ++i) {
		if (tmp[i] == '1') {
			first1Idx = size -i -1;
			break;
		}
	}
	int last1Idx = first1Idx;
	int validSwitch1Idx = -1;
	int validSwitch0Idx = -1;
	for (int j = first1Idx; j <size; ++j) {
		if (tmp[j] == '1') {
			last1Idx = j;
		}
		else if (tmp[j] == '0') {
			validSwitch1Idx = last1Idx;
			validSwitch0Idx = j;
		}
	}
	if (validSwitch0Idx >= 0 && validSwitch1Idx >= 0) {
		tmp[validSwitch0Idx] = '1';
		tmp[validSwitch1Idx] = '0';
		cout << "Smallest : " << tmp << endl;
	}
	// largest search
	tmp = nBinarized;
	validSwitch1Idx = -1;
	validSwitch0Idx = -1;
	for (int k = size - 1; k >= 0; --k) {
		if (tmp[k] == '1' && validSwitch1Idx < 0) {
			validSwitch1Idx = k;
		}
		else if (tmp[k] == '0') {
			if (validSwitch1Idx >= 0) {
				validSwitch0Idx = k;
				break;
			}
		}
	}
	if (validSwitch0Idx >= 0 && validSwitch1Idx >= 0) {
		tmp[validSwitch0Idx] = '1';
		tmp[validSwitch1Idx] = '0';
		cout << "Largest : " << tmp << endl;
	}
}