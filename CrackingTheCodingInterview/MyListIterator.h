#pragma once
#include <iterator>
#include <iostream>
#include "MyNode.h"
using namespace std;
template <typename T> class MyLinkedList;
template <typename T>
class MyListIterator : public iterator<forward_iterator_tag, T> {
	friend class MyLinkedList<T>;
public:
	T& operator * () {
		return this->_referedNode->_value;
	}
	const MyListIterator<T>& operator ++() {
		if (this->_referedNode != nullptr) {
			this->_referedNode = this->_referedNode->GetNext();
		}
		return *this;
	}
	bool operator != (const MyListIterator<T> & it)const {
		return this->_referedNode != it._referedNode;
	}
private:
	MyNode<T> *_referedNode = nullptr;
	MyListIterator(MyNode<T> * node) :_referedNode(node){}
};
