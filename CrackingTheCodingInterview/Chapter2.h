#pragma once
#include <string>
#include<map>
#include <algorithm>
#include "MyLinkedList.h"
class Chapter2 {
public:
	long SumList(MyLinkedList<int> L1, MyLinkedList<int> L2);
	bool IsAPalindrome(MyLinkedList<char> L1);
	MyNode<int>* Intersection(MyLinkedList<int> L1, MyLinkedList<int> L2);
	MyNode<int>* LoopDetection(MyLinkedList<int> L1);
private:
};
