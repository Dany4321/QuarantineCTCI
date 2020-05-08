#include "Chapter3.h"
#include "ThreeStacksInOne.h"
#include "MyStack.h"
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
