#pragma once
using namespace std;
 class Chapter8
{
public:
	static long long int TripleStep(int n);
	static long long int TripleStepIter(int n);
	static double** RobotInAGrid(double** grid, int height, int width);// -1 in the grid where there is an obstacle
};