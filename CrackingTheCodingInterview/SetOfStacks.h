#pragma once
#pragma once
#include"MyNode.h"
#include "MyStack.h"
using namespace std;
template<class T>
class SetOfStacks {
public:
	SetOfStacks(long treshold):_treshold(treshold) {
		MyStack<T>* stack = new MyStack<T>();
		this->_currentStacks = new MyNode<MyStack<T>*>(stack);
		// this->_currentStacks->GetValue()._count;
	}
	~SetOfStacks() {
		while (this->_currentStacks != nullptr) {
			MyNode<MyStack<T>*>* next = this->_currentStacks->GetNext();
			delete this->_currentStacks;
			this->_currentStacks = next;
		}
	}
	T Top() {
		return this->_currentStacks->GetValue().Top();
	}
	void Pop() {
		if (this->_currentStacks != nullptr) {
			this->_currentStacks->GetValue()->Pop();
			if (this->_currentStacks->GetValue()->_count == 0) {
				this->_currentStacks = this->_currentStacks->GetPrevious();
			}
		}
	}
	void PopAt(int index) {
		if (this->_currentStacks != nullptr) {
			MyNode<MyStack<T>*>* node = this->_currentStacks;
			while (index > 0 && node != nullptr) {
				node = node->GetPrevious();
			}
			if (node != nullptr) {
				node->GetValue()->Pop();
			}
		}
	}
	void Push(T value) {
		if (this->_currentStacks->GetValue()->_count == this->_treshold) {
			MyStack<T>* stack = new MyStack<T>();
			MyNode<MyStack<T>*>* node = new MyNode<MyStack<T>*>(stack);
			node->SetPrevious(this->_currentStacks);
			this->_currentStacks = node;
		}
		this->_currentStacks->GetValue()->Push(value);
	}
	bool IsEmpty() {
		if (this->_currentStacks == nullptr) {
			return true;
		}
		else {
			return (this->_currentStacks->GetValue()->Top() == nullptr);
		}
	}
private:
	MyNode<MyStack<T>*>* _currentStacks = nullptr;
	long _treshold;
};