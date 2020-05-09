#pragma once
#include "ThreeStacksInOne.h"
#include "MyStack.h"
#include "SetOfStacks.h"
#include "QueueByStacks.h"
using namespace std;
class Chapter3 {
public:
	static void ThreeInOne();
	static void StackMin();
	static void StackOfPlates();
	static void QueueViaStacks();
	static void SortStack(MyStack<int>& stack);
private:
	static void InsertValueInOrderedStack(int val, MyStack<int>& stack);
};