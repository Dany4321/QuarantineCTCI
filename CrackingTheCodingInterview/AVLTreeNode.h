#pragma once
#include "BinaryTreeNode.h"
template <typename T> class MyAVLTree;
template<typename T>
class AVLTreeNode : public BinaryTreeNode<T> {
	friend class MyAVLTree<T>;
public:
	AVLTreeNode() {
		this->_parent = nullptr;
		this->_value = 0;
	}
	AVLTreeNode(AVLTreeNode<T>* parent, T value):BinaryTreeNode<T>(value){
		this->_parent;
	}
	~AVLTreeNode() {
		this->_parent = nullptr;
	}
	void SetParent(AVLTreeNode<T>* parent) {
		this->_parent = parent;
		if (parent != nullptr) {
			if (parent->_value > this->_value) {
				this->_parent->_leftChild = this;
			}
			else {
				this->_parent->_rightChild = this;
			}
		}
	}
	BinaryTreeNode<T>* AppendNode(T value) override {
		AVLTreeNode<T>* tmp = new AVLTreeNode<T>(this,value);
		AppendNode(tmp);
		return tmp;
	}
	void AppendNode(BinaryTreeNode<T>* node) override {
		if (this->_value < ((AVLTreeNode<T>*)node)->_value) {
			if (this->_rightChild != nullptr) {
				((AVLTreeNode<T>*)this->_rightChild)->AppendNode(node);
			}
			else {
				((AVLTreeNode<T>*)node)->SetParent(this);
			}
		}
		else if (this->_value == ((AVLTreeNode<T>*)node)->_value) {
			this->nbOccurence++;
		}
		else {
			if (this->_leftChild != nullptr) {
				((AVLTreeNode<T>*)this->_leftChild)->AppendNode(node);
			}
			else {
				((AVLTreeNode<T>*)node)->SetParent(this);
			}
		}
	}
	int GetHeight() {
		int l = 1;
		int r = 1;
		if (this->_leftChild != nullptr) {
			l += ((AVLTreeNode<T>*)this->_leftChild)->GetHeight() ;
		}
		if (this->_rightChild != nullptr) {
			r += ((AVLTreeNode<T>*)this->_rightChild)->GetHeight() ;
		}
		if (l > r) {
			return l;
		}
		return r;
	}
	bool IsBalanced() {
		AVLTreeNode<T>* tmpL = (AVLTreeNode<T>*)this->_leftChild;
		int Lcounter = 0;
		if (tmpL != nullptr) {
			Lcounter =  tmpL->GetHeight();
		}
		AVLTreeNode<T>* tmpR = (AVLTreeNode<T>*)this->_rightChild;
		int Rcounter = 0;
		if (tmpR != nullptr) {
			Rcounter =  tmpR->GetHeight();
		}
		return abs(Lcounter - Rcounter) < 2;
	}
	AVLTreeNode<T>* GetLeftChild() const {
		return (AVLTreeNode<T>*)this->_leftChild;
	}
	AVLTreeNode<T>* GetRightChild() const {
		return (AVLTreeNode<T>*)this->_rightChild;
	}
	AVLTreeNode<T>* GetParent() const {
		return (AVLTreeNode<T>*)this->_parent;
	}
	int GetNbOccurence() const{
		return this->nbOccurence;
	}
private:
	AVLTreeNode<T>* _parent = nullptr;
	int nbOccurence = 1;
};