#pragma once
#include "BinaryTreeNode.h"
template<typename T>
class AVLTreeNode : public BinaryTreeNode<T> {
public:
	AVLTreeNode(AVLTreeNode<T>* parent, T value) {
		this->_parent;
		this->_value = value;
	}
	~AVLTreeNode() {
		this->_parent = nullptr;
	}
	
	void AppendNode(T value) override {
		AVLTreeNode* tmp = new AVLTreeNode(this,value);
		AppendNode(tmp);
	}
	void AppendNode(AVLTreeNode* node) override {
		if (this->_value <= node->_value) {
			if (this->_rightChild != nullptr) {
				this->_rightChild->AppendNode(tmp);
			}
			else {
				this->_rightChild = tmp;
				this->_rightChild->_parent = this;
				this->IncreaseRightHeight();
			}
		}
		else {
			if (this->_leftChild != nullptr) {
				this->_leftChild->AppendNode(tmp);
			}
			else {
				this->_leftChild = tmp;
				this->_leftChild->_parent = this;
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