#include "Chapter8.h"
#include <limits>
#include <iostream>
using namespace std;
long long int Chapter8::TripleStep(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	//Remaining step for 1,2,3 steps
	return TripleStep(n - 1) + TripleStep(n - 2) + TripleStep(n - 3);
}

long long int Chapter8::TripleStepIter(int n)
{
	long long int* buffer = new  long long int[3];
	buffer[0] = 1;
	buffer[1] = 0;
	buffer[2] = 0;
	int i = 0;
	while (i < n)
	{
		long long int tmp0 = buffer[0];
		long long int tmp1 = buffer[1];
		long long int tmp2 = buffer[2];
		buffer[2] += tmp1 + tmp0;
		buffer[1] = tmp2;
		buffer[0] = tmp1;
		++i;
	}
	return buffer[2] + buffer[1] + buffer[0];
}
double**  Chapter8::RobotInAGrid(double** grid, int height, int width)
{
	//defining dangerousness weigth
	for (int i = height - 1; i >= 0; i--) 
	{
		for (int j = width - 2; j >= 0; j--)
		{
			if (i == height - 1) 
			{
				grid[i][j] += grid[i][j + 1];
			}
			else
			{
				grid[i][j] += (grid[i][j + 1] + grid[i + 1][j]) / 2;
			}
		}
	}
	double max = std::numeric_limits<double>::max();
	int currentI = 0;
	int currentJ = 0;
	double bestChoice = grid[currentI][currentJ];
	while((currentI != (height -1)) || (currentJ != (width - 1)))
	{
		if (grid[currentI][currentJ + 1] >= grid[currentI + 1][currentJ])
		{
			currentJ += 1;
		}
		else if(grid[currentI][currentJ + 1] <= grid[currentI + 1][currentJ])
		{
			currentJ += 1;
		}
		if ((currentI >= height) || (currentJ >= width))
		{
			cout << "No Path available" << endl;
			break;
		}
		grid[currentI][currentJ] = max;
	}
	return grid;
}