#pragma once
#include"MyNode.h"
using namespace std;
template<class T>
class MyQueue {
public:
	~MyQueue() {
		while (this->_currentNode != nullptr) {
			MyNode<T>* next = this->_currentNode->GetNext();
			delete this->_currentNode;
			this->_currentNode = next;
		}
	}
	void Add(T value) {
		MyNode<T>* node = new MyNode<T>(value);
		if (this->_currentNode == nullptr) {
			this->_currentNode = node;
		}
		else {
			this->_currentNode->SetNext(node);
		}
	}
	void Pop() {
		if (this->_currentNode != nullptr) {
			this->_currentNode = this->_currentNode->GetNext();
		}
	}
	bool IsEmpty() {
		return (this->_currentNode == nullptr);
	}
	T Peek() {
		return this->_currentNode->GetValue();
	}
private:
	MyNode* _currentNode = nullptr;
};