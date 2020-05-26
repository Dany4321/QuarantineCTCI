#pragma once
#include "Visited.h"
#include"MyStringBuilder.h"
template <typename T> class BinarySearchTree;
template<class T>
class BinaryTreeNode : public Visited<T> {
	friend class BinarySearchTree<T>;
public:
	BinaryTreeNode(T value) :_value(value) {

	}
	~BinaryTreeNode() {
		delete this->_leftChild;
		delete this->_rightChild;
		this->_leftChild = nullptr;
		this->_rightChild = nullptr;
	}
	virtual void AppendNode(T value) {
		BinaryTreeNode* tmp = new  BinaryTreeNode(value);
		AppendNode(tmp);
	}
	virtual void AppendNode(BinaryTreeNode* node) {
		if (this->_value <= node->_value) {
			if (this->_rightChild != nullptr) {
				this->_rightChild->AppendNode(node);
			}
			else {
				this->_rightChild = node;
			}
		}
		else {
			if (this->_leftChild != nullptr) {
				this->_leftChild->AppendNode(node);
			}
			else {
				this->_leftChild = node;
			}
		}
	}
	void PreOrderVisit(Visitor<T> visitor) {
		if (this->_leftChild != nullptr) {
			this->_leftChild->PreOrderVisit(visitor);
		}
		if (this->_rightChild != nullptr) {
			this->_rightChild->PreOrderVisit(visitor);
		}
		this->Accept(visitor);
	}
	void PostOrderVisit(Visitor<T> visitor) {
		this->Accept(visitor);
		if (this->_leftChild != nullptr) {
			this->_leftChild->PostOrderVisit(visitor);
		}
		if (this->_rightChild != nullptr) {
			this->_rightChild->PostOrderVisit(visitor);
		}
	}
	void InOrderVisit(Visitor<T> visitor) {
		if (this->_leftChild != nullptr) {
			this->_leftChild->InOrderVisit(visitor);
		}
		this->Accept(visitor);
		if (this->_rightChild != nullptr) {
			this->_rightChild->InOrderVisit(visitor);
		}
	}
	string toString() {
		MyStringBuilder* sb1 = new MyStringBuilder();
		MyStringBuilder* sb2 = new MyStringBuilder();
		string res= this->toString(sb1, true, sb2)->ToString();
		delete sb1;
		delete sb2;
		return res;
	}
protected:
	// I found this one on stackoverflow...:https://stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram
	    MyStringBuilder* toString(MyStringBuilder* prefix, bool isTail, MyStringBuilder* sb) {
		if (this->_rightChild != nullptr) {
			MyStringBuilder* tmp1 = new MyStringBuilder();
			this->_rightChild->toString(tmp1->Append(prefix->ToString())->Append(isTail ? "!   " : "    "), false, sb);
			delete tmp1;
		}
		sb->Append(prefix->ToString())->Append("--- ")->Append(std::to_string(this->_value))->Append("\n");
		if (this->_leftChild != nullptr) {
			MyStringBuilder* tmp2 = new MyStringBuilder();
			this->_leftChild->toString(tmp2->Append(prefix->ToString())->Append(isTail ? "    " : "!   "), true, sb);
			delete tmp2;
		}
		return sb;
	} 
	T _value;
	BinaryTreeNode<T>* _leftChild = nullptr;
	BinaryTreeNode<T>* _rightChild = nullptr;
};
