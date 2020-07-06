// CrackingTheCodingInterview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringPermutationsSearch.h"
#include "TestMyArray.h"
#include "TestStringBuilder.h"
#include "Chapter3.h"
#include "TestLinkedList.h"
#include "TestBST.h"
#include "TestAVL.h"
#include "Chapter8.h"
#include <limits>
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
	/*MyStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(2);
	stack.Push(0);
	stack.Push(68);
	stack.Push(40);

	MyStack<int>* res =Chapter3::SortStack(stack);*/
	// cout << Chapter8::TripleStep(50) << endl;
	// cout << Chapter8::TripleStepIter(50) << endl;
	double** grid = new double*[5]; 
	/*{
						  0, 0, 0, 0, 0, -1,-1,
						  0, 0, 0, 0, 0, -1, 0,
						  0,-1, 0, 0, 0,  0, 0,
						  0, 0, 0, 0, -1,-1, 0,
						  0, 0,-1, 0,  0, 0, 0
						};*/
	for(int o = 0; o<5;o++)
	{
		grid[o] = new double[7];
		for (int m = 0; m < 7; m++) 
		{
			grid[o][m] = 0;
		}
	}
	grid[0][5] = -1;
	grid[0][6] = -1;
	grid[1][5] = -1;
	grid[2][1] = -1;
	grid[3][4] = -1;
	grid[3][5] = -1;
	grid[4][2] = -1;
	for (int i = 0; i < 5; i++)
	{
		for(int k = 0; k< 7; k++)
		{
			if (grid[i][k] == -1) 
			{
				cout << " #";
			}
			else {
				cout << " _";
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	double max = std::numeric_limits<double>::max();
	double** result = Chapter8::RobotInAGrid(grid, 5, 7);
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (result[i][k] == max)
			{
				cout << " X";
			}
			else {
				cout << " _";
			}
		}
		cout << endl;
	}
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
