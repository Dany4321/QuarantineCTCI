#include "TestMyArray.h"
 void TestMyArray:: RunAllTests() {
	cout << "Add testing.." << endl;
	TestMyArray::AddTest();
	cout << "Remove testing.." << endl;
	TestMyArray::RemoveTest();
	cout << "InsertAt testing.." << endl;
	TestMyArray::InsertAtTest();
	cout << "GetSize testing.." << endl;
	TestMyArray::GetSizeTest();
	cout << "GetCapacity testing.." << endl;
	TestMyArray::GetCapacityTest();
	cout << "Operator testing.." << endl;
	TestMyArray::OperatorTest();
}
 void TestMyArray:: AddTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	tmp.Add(2);
	tmp.Add(3);
	tmp.Add(4);
	tmp.Add(5);
	if (tmp.GetSize() == 5 && tmp[0] == 1 &&
		tmp[1] == 2 &&
		tmp[2] == 3 &&
		tmp[3] == 4 &&
		tmp[4] == 5) {
		cout << "test succeeded" << endl;
	}
	else {
		cout << "test failed" << endl;
	}
}
 void TestMyArray:: RemoveTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	tmp.Add(2);
	tmp.Add(3);
	tmp.Add(4);
	tmp.Add(5);
	tmp.RemoveAt(3);
	tmp.RemoveAt(0);
	tmp.RemoveAt(10);
	if (tmp.GetSize() == 3 && tmp[0] == 2 && tmp[3] == 5) {
		cout << "test succeeded" << endl;
	}
	else {
		cout << "test failed" << endl;
	}
}
 void TestMyArray:: InsertAtTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	tmp.Add(2);
	tmp.Add(3);
	tmp.Add(4);
	tmp.Add(5);
	tmp.InsertAt(-1, 1);

	try {
		tmp.InsertAt(8, 100);// expect exception
	}
	catch (exception e) {
		if (tmp[1] == -1) {
			cout << "test succeeded" << endl;
			return;
		}
	}
	cout << "Test failed" << endl;;

}
 void TestMyArray:: GetSizeTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	if (tmp.GetSize() == 1) {
		cout << "test succeeded" << endl;
	}
	else {
		cout << "test failed" << endl;
	}
}
 void TestMyArray::GetCapacityTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	if (tmp.GetCapacity() == 2) {
		cout << "test succeeded" << endl;
	}
	else {
		cout << "test failed" << endl;
	}
}
 void TestMyArray::OperatorTest() {
	MyArray<int> tmp;
	tmp.Add(1);
	tmp[0] = 2;
	if (tmp[0] == 2) {
		cout << "test succeeded" << endl;
	}
	else {
		cout << "test failed" << endl;
	}
}