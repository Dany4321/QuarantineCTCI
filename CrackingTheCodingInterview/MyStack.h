#pragma once
#include"MyNode.h"
using namespace std;
template <typename T> class SetOfStacks;
template<class T>
class MyStack {
	friend class SetOfStacks<T>;
public:
	MyStack() {
	}
	~MyStack() {
		while (this->_currentNode != nullptr) {
			MyNode<T>* next = this->_currentNode->GetNext();
			delete this->_currentNode;
			this->_currentNode = next;
		}
		 this->_min = nullptr;
	}
	T Top() {
		return this->_currentNode->GetValue();
	}
	void Pop() {
		if (this->_currentNode != nullptr) {
			if (this->_currentNode== this->_min) {
				this->_min = this->_min->GetPrevious();
			}
			this->_currentNode = this->_currentNode->GetNext();
			--_count;
		}
	}
	void Push(T value) {
		MyNode<T>* node = new MyNode<T>(value);
		if (this->_min != nullptr) {
			if (this->_min->GetValue() >= node->GetValue()) {
				node->SetPrevious(this->_min);
				this->_min = node;
			}
		}
		else {
			this->_min = node;
		}
		if (this->_currentNode == nullptr) {
			this->_currentNode = node;
		}
		else {
			node->SetNext(this->_currentNode);
			this->_currentNode = node;
		}
		++_count;
	}
	bool IsEmpty() {
		return (this->_currentNode == nullptr);
	}
	T GetMin() {
		return this->_min->GetValue();
	}
private:
	MyNode<T>* _currentNode = nullptr;
	MyNode<T>* _min = nullptr;
	long _count = 0;
};