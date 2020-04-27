#ifndef TestMyArray_H
#define TestMyArray_H
#include "MyArray.h"
#include <iostream>
using namespace std;

class TestMyArray {
public:
	static void RunAllTests();
	static void AddTest();
	static void RemoveTest();
	static void InsertAtTest();
	static void GetSizeTest();
	static void GetCapacityTest();
	static void OperatorTest();
};
#endif