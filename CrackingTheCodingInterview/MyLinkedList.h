#pragma once
#include"MyNode.h"
#include "MyListIterator.h"
using namespace std;
template<class T>
class MyLinkedList {
public:
	typedef MyListIterator<T> iterator;
public:
	MyLinkedList(bool isDoubleLinked = false):_isDoubleLinked(isDoubleLinked) {

	}
	~MyLinkedList() {
		MyNode<T>* node = this->_root;
		while (node != nullptr) {
			MyNode<T>* next = node->GetNext();
			delete node;
			node = next;
		}
	}
	void Push_Front(T value) {
		MyNode<T>* n = new MyNode<T>(value);
		this->Push_Front(n);
	}
	void Push_Front(MyNode<T>* value) {
		value->SetNext(this->_root);
		if (this->_isDoubleLinked && this->_root != nullptr) {
			this->_root->SetPrevious(value);
			this->_last = this->_root;
		}
		this->_root = value;
	}
	// Remove all occurence of value
	void Remove(T value) {
		MyNode<T>* node = this->_root;
		MyNode<T>* previous = nullptr;
		while (node != nullptr) {
			if (node->GetValue() == value) {
				MyNode<T>* next = node->GetNext();
				if (previous != nullptr) {
					previous->SetNext(next);
					if (this->_isDoubleLinked && next != nullptr) {
						next->SetPrevious(previous);
					}
				}
				else {
					this->_root = next;
					if (this->_root != nullptr) {
						this->_root->SetPrevious(nullptr);
					}
				}
				delete node;
				node = previous;
			}
			previous = node;
			node = node->GetNext();
		}
	}
	void RemoveDuplicates() {
		MyNode<T>* node = this->_root;
		MyNode<T>* previous = nullptr;
		while (node != nullptr) {
			MyNode<T>* tmp = node->GetNext();
			MyNode<T>* previous = node;
			while (tmp != nullptr) {
				MyNode<T>* nextNext = tmp->GetNext();
				if (tmp->GetValue() == node->GetValue()) {
					previous->SetNext(nextNext);
					if (this->_isDoubleLinked && nextNext != nullptr) {
						nextNext->SetPrevious(previous);
					}
					delete tmp;
				}
				else {
					previous = tmp;
				}
				tmp = previous->GetNext();
			}
			node = node->GetNext();
			if (node != nullptr) {
				this->_last = node;
			}
		}
	}
	iterator GetKthToLast(int k) {
		iterator it = this->Begin();
		int count = 0;
		while(it._referedNode != nullptr && ++count < k){
			it = ++it;
		}
		return it;
	}
	void DeleteMiddleNode(T value) {
		int count = 0;
		iterator it = this->Begin();
		while (it._referedNode != nullptr) {
			it = ++it;
			++count;
		}
		int middle = count / 2;
		if (middle > 0 && middle < count) {
			it = this->Begin();
			MyNode<T>* previousNode = nullptr;
			while (it._referedNode != nullptr && count < middle) {
				previousNode = it._referedNode;
				it = ++it;
				++count;
			}
			if (it._referedNode->GetValue() == value) {
				MyNode<T>* middleNode = it._referedNode;
				MyNode<T>* nextNode = it._referedNode->GetNext();
				previousNode->SetNext(nextNode);
				if (this->_isDoubleLinked) {
					nextNode->SetPrevious(previousNode);
				}
				delete middleNode;
			}
		}
	}
	void Partition(T value) {
		MyNode<T>* node = this->_root;
		MyNode<T>* lastPreviousOfMedian = nullptr;
		MyNode<T>* lastNext= nullptr;
		MyNode<T>* medianNode = nullptr;
		while (node != nullptr) {
			MyNode<T>* next = node->GetNext();
			if (node->GetValue() < value) {
				if (lastPreviousOfMedian != nullptr) {
					if (this->_isDoubleLinked) {
						node->SetPrevious(lastPreviousOfMedian);
					}
					lastPreviousOfMedian->SetNext(node);
				}
				else {
					this->_root = node;
					this->_root->SetPrevious(nullptr);
				}
				lastPreviousOfMedian = node;
				lastPreviousOfMedian->SetNext(medianNode);
				if (this->_isDoubleLinked && medianNode != nullptr) {
					medianNode->SetPrevious(lastPreviousOfMedian);
				}
			}
			else {
				if (medianNode == nullptr) {
					medianNode = node;
				}
				node->SetNext(nullptr);
				if (lastNext != nullptr) {
					if (this->_isDoubleLinked) {
						node->SetPrevious(lastNext);
					}
					lastNext->SetNext(node);
				}
				lastNext = node;
			}
			node = next;
		}
		this->_last = lastNext;
	}
	bool IsEmpty() {
		return this->_root == nullptr;
	}
	iterator Begin() {
		if (this->_root != nullptr) {
			return    iterator(this->_root);
		}
		return nullptr;
	}
	iterator End() {
		return iterator(nullptr);
	}
	MyNode<T>* GetRoot() {
		return this->_root;
	}
private:
	bool _isDoubleLinked;
	MyNode<T>* _root = nullptr;
	MyNode<T>* _last = nullptr;
};