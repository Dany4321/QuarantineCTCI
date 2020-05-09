#include "Chapter3.h"

void Chapter3:: ThreeInOne() {
	ThreeStacksInOne<int> tripleStack;
	tripleStack.Push1(1);
	tripleStack.Push1(1);
	tripleStack.Push1(1);
	tripleStack.Push1(1);

	tripleStack.Push2(2);
	tripleStack.Push2(2);
	tripleStack.Push2(2);
	tripleStack.Push2(2);
	tripleStack.Push2(2);

	tripleStack.Push3(3);
	tripleStack.Push3(3);
	tripleStack.Push3(3);
	tripleStack.Push3(3);
	tripleStack.Push3(3);
	tripleStack.Push3(3);
	tripleStack.Push3(3);

	while (!tripleStack.IsEmpty1()) {
		int i = tripleStack.Top1();
		tripleStack.Pop1();
	}

	while (!tripleStack.IsEmpty2()) {
		int i = tripleStack.Top2();
		tripleStack.Pop2();
	}

	while (!tripleStack.IsEmpty3()) {
		int i = tripleStack.Top3();
		tripleStack.Pop3();
	}

}
void Chapter3::StackMin() {
	// My implementation of min is  in MyStack class
	MyStack<int> stack;
	stack.Push(10);
	stack.Push(56);
	stack.Push(34);
	stack.Push(140);
	stack.Push(100);
	stack.Push(2);
	stack.Push(10);
	stack.Push(3);

	int min = stack.GetMin();

	stack.Pop();
	stack.Pop();
	stack.Pop();
	int min2 = stack.GetMin();
}

void Chapter3::StackOfPlates() {
	// it works ! I have checked the states of the set while debugging
	SetOfStacks<int> set = SetOfStacks<int>(2);
	set.Push(1);
	set.Push(2);
	set.Push(3);
	set.Push(4);
	set.Push(5);
	set.Push(6);
	set.Pop();
	set.Pop();
	set.Pop();
	set.Pop();
	set.Pop();
	set.Pop();
}
void  Chapter3::QueueViaStacks() {
	// Check the class QueueByStacks to see my implementation
	QueueByStacks<int> stack;
	stack.Add(1);
	stack.Add(2);
	stack.Add(3);
	stack.Add(4);
	stack.Add(5);
	stack.Pop();
	int res = stack.Peek();
	stack.Pop();
	stack.Pop();
	res = stack.Peek();
	stack.Pop();
}
void  Chapter3::SortStack(MyStack<int>& stack) {
	MyStack<int> tmpStack;
	while (!stack.IsEmpty()) {
		int top = stack.Top();
		stack.Pop();
		InsertValueInOrderedStack(top, tmpStack);
	}
	stack = tmpStack;
}
void  Chapter3::InsertValueInOrderedStack(int val, MyStack<int>& stack) {
	if (stack.IsEmpty()) {
		stack.Push(val);
	}
	else {
		if (val > stack.Top()) {
			int top = stack.Top();
			stack.Pop();
			InsertValueInOrderedStack(val, stack);
			InsertValueInOrderedStack(top, stack);
		}
		else {
			stack.Push(val);
		}
	}
}