#pragma once
#include "BinaryTreeNode.h"
#include "MyStack.h"
template<class T>
class BinarySearchTree {
public:
	BinarySearchTree() {
		this->_root = nullptr;
	}
	BinarySearchTree(T root) {
		this->_root = new  BinaryTreeNode<T>(root);
	}
	BinaryTreeNode<T>& GetRoot()const {
		return this->_root;
	}
	bool IsABinarySearchTree(const BinaryTreeNode<T>& node) const { // O(n)
		if (node._leftChild != nullptr && node._leftChild->_value > this->_value) {
			return false;
		}
		if (node._rightChild != nullptr && node._rightChild->_value < this->_value) {
			return false;
		}
		bool result = true;
		if (this->_root->_leftChild != nullptr) {
			result &= IsABinarySearchTree(node._leftChild);
		}
		if ( result && this->_root->_rightChild != nullptr) {
			result &= IsABinarySearchTree(node._rightChild);
		}
		return result;
	}
	 void InsertValue(T value) {
		this->_root->AppendNode(value);
	}
	 void InsertNode(BinaryTreeNode<T>* node) {
		this->_root->AppendNode(node);
	}
	 void RemoveNode(BinaryTreeNode<T>* node) {
		// If the node doesnt have children we simply remove it from the tree
		if (node->_leftChild == nullptr && node->_rightChild == nullptr) {
			BinaryTreeNode<T>* current = this->_root;
			BinaryTreeNode<T>* previous = nullptr;
			while (current != nullptr) {
				if (current == node) {
					if (previous != nullptr) {
						if (previous->_leftChild == node) {
							previous->_leftChild = nullptr;
						}
						else if (previous->_rightChild == node) {
							previous->_rightChild = nullptr;
						}
					}
					delete node;
					node = nullptr;
					return;
				}
				else {
					previous = current;
					if (current->_value > node->_value) {
						current = current->_leftChild;
					}
					else {
						current = current->_rightChild;
					}
				}
			}
		}
		// If the node have only one child we remove it and bind its children to its parent
		else if ((node->_leftChild == nullptr && node->_rightChild != nullptr) ||
			(node->_leftChild != nullptr && node->_rightChild == nullptr)) {
			BinaryTreeNode<T>* current = this->_root;
			BinaryTreeNode<T>* previous = nullptr;
			while (current != nullptr) {
				if (current == node) {
					BinaryTreeNode<T>* child = node->_leftChild;
					if (child == nullptr) {
						child = node->_rightChild;
					}
					if (previous != nullptr) {
						if (previous->_leftChild == node) {
							previous->_leftChild = child;
						}
						else if (previous->_rightChild == node) {
							previous->_rightChild = child;
						}
					}
					delete node;
					node = nullptr;
					return;
				}
				else {
					previous = current;
					if (current->_value > node->_value) {
						current = current->_leftChild;
					}
					else {
						current = current->_rightChild;
					}
				}
			}
		}
		// If the node have 2 children , we find its successor, and we replace the node by its successor
		else {
			BinaryTreeNode<T>* current = this->_root;
			BinaryTreeNode<T>* previous = nullptr;
			BinaryTreeNode<T>* successor = this->FindSuccessor(node);
			while (current != nullptr) {
				if (current == successor) {
					BinaryTreeNode<T>* child = successor->_leftChild;
					if (child == nullptr) {
						child = successor->_rightChild;
					}
					if (previous != nullptr) {
						if (previous->_leftChild == successor) {
							previous->_leftChild = child;
						}
						else if (previous->_rightChild == successor) {
							previous->_rightChild = child;
						}
					}
					node->_value  = successor ->_value;
					successor->_leftChild = nullptr;
					successor->_rightChild = nullptr;
					delete successor;
					successor = nullptr;
					return;
				}
				else {
					previous = current;
					if (current->_value > successor->_value) {
						current = current->_leftChild;
					}
					else {
						current = current->_rightChild;
					}
				}
			}
		}
	}
	BinaryTreeNode<T>* FindSuccessor(BinaryTreeNode<T>* node) {
		if (node == nullptr) {
			return nullptr;
		}
		// we find the smallest biggest
		if (node->_rightChild != nullptr) {
			BinaryTreeNode<T>* current = node->_rightChild;
			while (current->_leftChild != nullptr) {
				current = current->_leftChild;
			}
			return current;
		}
		else if (node->_leftChild != nullptr) {
			// we search for the less far parent for which the node is in its left subtree
			BinaryTreeNode<T>* current = this->_root;
			MyStack< BinaryTreeNode<T>*> parentsStack;
			while (current != nullptr) {
				if (current == node) {
					BinaryTreeNode<T>* tmp = node;
					while (!parentsStack.IsEmpty() && parentsStack.Top()->_rightChild == tmp) {
						tmp = parentsStack.Top();
						parentsStack.Pop();
					}
					if (!parentsStack.IsEmpty()) {
						return parentsStack.Top();
					}
					else {
						return nullptr;
					}
				}
				else {
					parentsStack.Push(current);
					if (current->_value > node->_value) {
						current = current->_leftChild;
					}
					else {
						current = current->_rightChild;
					}
				}
			}
		}
		return nullptr;
	}
	void Print() {
		std::cout << this->_root->toString() << endl;;
	}
private:
	BinaryTreeNode<T>* _root = nullptr;
};