// CrackingTheCodingInterview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringPermutationsSearch.h"
#include "TestMyArray.h"
#include "TestStringBuilder.h"
#include "Chapter1.h"
int main()
{
	// StringPermutationsSearch::Search("abc", "aaaaaaaa");
	//TestStringBuilder::RunAllTests();
	/*int N = 4;
	int** newImage = new int*[N];
	int c = 0;
	for (int k = 0; k < N; k++) {
		newImage[k] = new int[N];
		for (int l = 0; l < N; l++) {
			newImage[k][l] = c++;
			cout << newImage[k][l]  << " ";
		}
		cout << endl;
	}
	int** result = Exercice::ZeroMatrix(newImage, N,N);
	 cout << endl;
	 for (int k = 0; k < N; k++) {
		 for (int l = 0; l < N; l++) {
			 cout << result[k][l] << " ";
		 }
		 cout << endl;
	 }*/
	bool t = Chapter1::StringRotation("waterbottle", "erbottlewat");
		system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
