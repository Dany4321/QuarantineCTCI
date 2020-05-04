#pragma once
#include"MyNode.h"
using namespace std;
template<class T>
class MyLinkedList {
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
	MyNode<T>* GetRoot() {
		return this->_root;
	}
private:
	bool _isDoubleLinked;
	MyNode<T>* _root = nullptr;
	MyNode<T>* _last = nullptr;
};