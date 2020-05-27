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
	BinaryTreeNode<T>* AppendNode(T value) override {
		AVLTreeNode<T>* tmp = new AVLTreeNode<T>(this,value);
		AppendNode(tmp);
		return tmp;
	}
	void AppendNode(BinaryTreeNode<T>* node) override {
		if (this->_value <= ((AVLTreeNode<T>*)node)->_value) {
			if (this->_rightChild != nullptr) {
				this->_rightChild->AppendNode(node);
			}
			else {
				this->_rightChild = node;
				((AVLTreeNode<T>*)this->_rightChild)->_parent = this;
				this->IncreaseRightHeight();
			}
		}
		else {
			if (this->_leftChild != nullptr) {
				this->_leftChild->AppendNode(node);
			}
			else {
				this->_leftChild = node;
				((AVLTreeNode<T>*)this->_leftChild)->_parent = this;
				this->IncreaseLeftHeight();
			}
		}
	}
	bool IsBalanced() {
		return abs(this->leftHeight - this->rightHeight) < 2;
	}
private:
	void IncreaseLeftHeight() {
		++this->leftHeight;
		if (this->_parent != nullptr) {
			if (this->_parent->_leftChild == this) {
				this->_parent->IncreaseLeftHeight();
			}
			else {
				this->_parent->IncreaseRightHeight();
			}
		}
	}
	void IncreaseRightHeight() {
		++this->rightHeight;
		if (this->_parent != nullptr) {
			if (this->_parent->_leftChild == this) {
				this->_parent->IncreaseLeftHeight();
			}
			else {
				this->_parent->IncreaseRightHeight();
			}
		}
	}
	void DecreaseLeftHeight() {
		if (this->leftHeight > 0) {
			--this->leftHeight;
		}
		else {
			return;
		}
		if (this->_parent != nullptr) {
			if (this->_parent->_leftChild == this) {
				this->_parent->DecreaseLeftHeight();
			}
			else {
				this->_parent->DecreaseRightHeight();
			}
		}
	}
	void DecreaseRightHeight() {
		if (this->rightHeight > 0) {
			--this->rightHeight;
		}
		else {
			return;
		}
		if (this->_parent != nullptr) {
			if (this->_parent->_leftChild == this) {
				this->_parent->DecreaseLeftHeight();
			}
			else {
				this->_parent->DecreaseRightHeight();
			}
		}
	}

	int leftHeight = 0;
	int rightHeight = 0;
	AVLTreeNode<T>* _parent = nullptr;
};