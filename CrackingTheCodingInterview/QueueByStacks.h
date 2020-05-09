#pragma once
#include "MyStack.h"
template<class T>
class QueueByStacks {
public:
	void Add(T value) {
		this->_stackOfNews.Push(value);
	}
	void Pop() {
		TransferNewStackIntoOld();// It will do it if it s needed
		this->_stackOfOlds.Pop();
	}
	
	T Peek() {
		TransferNewStackIntoOld();// It will do it if it s needed
		return this->_stackOfOlds.Top();
	}
	bool IsEmpty() {
		return this->_stackOfNews.IsEmpty() && this->_stackOfOlds.IsEmpty();
	}
private:
	void TransferNewStackIntoOld() {
		if (this->_stackOfOlds.IsEmpty()) {
			while (!this->_stackOfNews.IsEmpty()) {
				this->_stackOfOlds.Push(this->_stackOfNews.Top());
				this->_stackOfNews.Pop();
			}
		}
	}
	MyStack<T> _stackOfNews;
	MyStack<T> _stackOfOlds;
};