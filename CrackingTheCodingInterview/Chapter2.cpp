#include "Chapter2.h"
#include "MyArray.h"
#include <stack>
long Chapter2::SumList(MyLinkedList<int> L1, MyLinkedList<int> L2){
	long sum = 0;
	int power = 0;
	// reverse order
	for (MyLinkedList<int>::iterator it = L1.Begin(); it != L1.End(); ++it) {
		sum += *it* 10 ^ power;
		++power;
	}
	power = 0;
	for (MyLinkedList<int>::iterator it = L2.Begin(); it != L2.End(); ++it) {
		sum += *it * 10 ^ power;
		++power;
	}
	return sum;
	// forward order
	/*MyArray<int> t1;
	int power2 = 0;
	long sum2 = 0;
	for (MyLinkedList<int>::iterator it = L1.Begin(); it != L1.End(); ++it) {
		t1.Add(*it);
	}
	int t1Size = t1.GetSize();
	for (int i = 0; i < t1Size; ++i) {
		sum2 += t1[i] * 10 ^ (t1Size - i - 1);
	}
	MyArray<int> t2;
	for (MyLinkedList<int>::iterator it = L2.Begin(); it != L2.End(); ++it) {
		t2.Add(*it);
	}
	int t2Size = t2.GetSize();
	for (int i = 0; i < t2Size; ++i) {
		sum2 += t2[i] * 10 ^ (t2Size - i - 1);
	}
	return sum2;
	*/
}
bool  Chapter2::IsAPalindrome(MyLinkedList<char> L1) {
	// we can use the histogram technic here, but I want to explore something new
	stack<MyNode<char>*> s;
	MyNode<char>* node = L1.GetRoot();
	int count = 0;
	while (node != nullptr) {
		s.push(node);
		node = node->GetNext();
		++count;
	}

	MyNode<char>* node1 = L1.GetRoot();
	for (int i = 0; i < count / 2; i++) {
		node = s.top();
		if (node->GetValue() != node1->GetValue()) {
			return false;
		}
		node1 = node1->GetNext();
		s.pop();
	}

}
MyNode<int>* Chapter2::Intersection(MyLinkedList<int> L1, MyLinkedList<int> L2) {
	stack<MyNode<int>*> s1;
	stack<MyNode<int>*> s2;
	MyNode<int>* node1 = L1.GetRoot();
	MyNode<int>* node2 = L2.GetRoot();
	while (node1 != nullptr) {
		s1.push(node1);
		node1 = node1->GetNext();
	}
	while (node2 != nullptr) {
		s2.push(node2);
		node2 = node2->GetNext();
	}
	if (s1.top() != s2.top()) {
		return nullptr; // if the 2 list share a referenced node they must have the same end
	}
	MyNode<int>* prev1 = s1.top();
	MyNode<int>* prev2 = s2.top();
	while (s1.top() == s2.top()) {
		prev1 = s1.top();
		prev2 = s2.top();
		s1.pop();
		s2.pop();
	}
	return prev1;
}

MyNode<int>*  Chapter2::LoopDetection(MyLinkedList<int> L1) {
	// use a map, if a node already exist it is the one
	map< MyNode<int>*, bool> dict;
	MyNode<int>* node1 = L1.GetRoot();
	while (node1 != nullptr) {
		map< MyNode<int>*, bool> ::iterator it = dict.find(node1);
		if (it != dict.end()) {
			return node1;
		}
		dict.insert(pair< MyNode<int>*, bool>(node1, true));
		node1 = node1->GetNext();
	}
	return nullptr;
}