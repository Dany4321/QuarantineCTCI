#pragma once
#include "AVLTreeNode.h"
#include <map>
#include "MyStack.h"
template<typename T>
class MyAVLTree {
	friend class TestAVL;
public:
	MyAVLTree(T rootValue) {
		this->_root =  new AVLTreeNode<T>(nullptr, rootValue);
	}
	MyAVLTree() {
		this->_root = nullptr;
	}
	~MyAVLTree() {
		std::function<void(Visited<T>*)> func = [](Visited<T>* visited)
		{
			delete  (AVLTreeNode<T>*)visited;
			visited = nullptr;
		};
		Visitor<T> visitor = Visitor<T>(func);
		this->_root->PostOrderVisit(visitor);
	}
	void setRoot(T value) {
		this->_root = new AVLTreeNode<T>(nullptr, value);
	}
	bool IsABinarySearchTree(const AVLTreeNode<T>& node) const { // O(n)
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
		if (result && this->_root->_rightChild != nullptr) {
			result &= IsABinarySearchTree(node._rightChild);
		}
		return result;
	}
	int Count() {
		AVLTreeNode<T>* node = this->_root;
		int c = 0;
		std::function<void(Visited<T>*)> func = [&c](Visited<T>* visited)
		{
			AVLTreeNode<T>* node =(AVLTreeNode<T>*)visited;
			if (visited != nullptr) {
				c += node->GetNbOccurence();
			}
		};
		Visitor<T> visitor = Visitor<T>(func);
		this->_root->PostOrderVisit(visitor);
		return c;
	}
	bool IsAnAVL() const { // O(n)
		AVLTreeNode<T>* node = this->_root;
		MyStack< AVLTreeNode<T>*> nodeStack;
		std::map< AVLTreeNode<T>*, int> previousHeights;
		node->IsBalanced();
		std::function<void(Visited<T>*)> func = [&nodeStack](Visited<T>* visited)
		{
			if (visited != nullptr) {
				nodeStack.Push((AVLTreeNode<T>*)visited);
			}
		};
		Visitor<T> visitor = Visitor<T>(func);
		this->_root->PostOrderVisit(visitor);
		while (!nodeStack.IsEmpty() && nodeStack.Top()->IsBalanced()) {
			nodeStack.Pop();
		}
		return nodeStack.IsEmpty();
	}
	AVLTreeNode<T>* InsertValue(T value) {
		AVLTreeNode<T>* res = (AVLTreeNode<T>*)this->_root->AppendNode(value);
		this->_lastInserted = res;
		Rebalance(res);
		this->ParentLinksUpdate();
		return res;

	}
	void InsertNode(AVLTreeNode<T>* node) {
		this->_root.AppendNode(node);
		Rebalance(node);
	}
    // https://www.youtube.com/watch?v=g4y2h70D6Nk
	//http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Trees/AVL-delete.html
	void RemoveNode(AVLTreeNode<T>* node) {
		--(node->nbOccurence);
		if (node->nbOccurence > 0)
			return;
		AVLTreeNode<T>* parent = node->_parent;
		// If the node doesnt have children we simply remove it from the tree
		if (node->_leftChild == nullptr && node->_rightChild == nullptr) {
			if (node->_parent->_leftChild == node) {
				parent->_leftChild = nullptr;
			}
			else {
				parent->_rightChild = nullptr;
			}
			delete node;
			node = nullptr;
		}
		// If the node have only one child we remove it and bind its children to its parent
		else if ((node->_leftChild == nullptr && node->_rightChild != nullptr) ||
			(node->_leftChild != nullptr && node->_rightChild == nullptr)) {
			AVLTreeNode<T>* child = (AVLTreeNode<T>*)node->_leftChild;
			if (child == nullptr) {
				child = (AVLTreeNode<T>*)node->_rightChild;
			}
			if (parent != nullptr) {
				if (parent->_leftChild == node) {
					parent->_leftChild = child;
				}
				else if (parent->_rightChild == node) {
					parent->_rightChild = child;
				}
			}
			delete node;
			node = nullptr;
		}
		// If the node have 2 children , we find its successor, and we replace the node by its successor
		else {
			AVLTreeNode<T>* successor = this->FindSuccessor(node);
			AVLTreeNode<T>* child = (AVLTreeNode<T>*)successor->_leftChild;
			if (child == nullptr) {
				child = (AVLTreeNode<T>*)successor->_rightChild;
			}
			if (successor->_parent != nullptr) {
				if (successor->_parent->_leftChild == successor) {
					successor->_parent->_leftChild = child;
				}
				else if (successor->_parent->_rightChild == successor) {
					successor->_parent->_rightChild = child;
				}
			}
			node->_value = successor->_value;
			successor->_leftChild = nullptr;
			successor->_rightChild = nullptr;
			delete successor;
			successor = nullptr;
		}
		this->Rebalance(parent);
	}
	AVLTreeNode<T>* FindSuccessor(AVLTreeNode<T>* node) {
		if (node == nullptr) {
			return nullptr;
		}
		// we find the smallest biggest
		if (node->_rightChild != nullptr) {
			AVLTreeNode<T>* current = (AVLTreeNode<T>*)node->_rightChild;
			while (current->_leftChild != nullptr) {
				current = (AVLTreeNode<T>*)current->_leftChild;
			}
			return current;
		}
		else if (node->_leftChild != nullptr) {
			// we search for the less far parent for which the node is in its left subtree
			AVLTreeNode<T>* current = this->_root;
			MyStack< AVLTreeNode<T>*> parentsStack;
			while (current != nullptr) {
				if (current == node) {
					AVLTreeNode<T>* tmp = node;
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
						current = (AVLTreeNode<T>*)current->_leftChild;
					}
					else {
						current = (AVLTreeNode<T>*)current->_rightChild;
					}
				}
			}
		}
		return nullptr;
	}
	void Print() {
		std::cout << this->_root->toString() << endl;;
	}
	AVLTreeNode<T>* GetPreviousInserted() {
		return this->_lastInserted;
	}
private:
	void UpdateRoot(AVLTreeNode<T>* insertedNode) {
		AVLTreeNode<T>* tmp = insertedNode;
		while (tmp->_parent != nullptr) {
			tmp = tmp->_parent;
		}
		this->_root = tmp;
	}
	void RightRotation(AVLTreeNode<T>* node) {
		AVLTreeNode<T>* tmp = (AVLTreeNode<T>*)node->_leftChild;
		node->_leftChild = nullptr;
		tmp->SetParent(node->_parent);
		node->_leftChild = tmp->_rightChild;
		tmp->_rightChild = node;
		node->SetParent(tmp);
	}
	void LeftRotation(AVLTreeNode<T>* node) {
		AVLTreeNode<T>* tmp = (AVLTreeNode<T>*)node->_rightChild;
		node->_rightChild = nullptr;
		tmp->SetParent(node->_parent);
		node->_rightChild = tmp->_leftChild;
		tmp->_leftChild = node;
		node->SetParent(tmp);
	}
	/*
		I have watched this course : https://youtu.be/-9sHvAnLN_w?list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk
		and https://www.cise.ufl.edu/~nemo/cop3530/AVL-Tree-Rotations.pdf
	*/
	void loopSearch(AVLTreeNode<T>* node) {
		std::map< AVLTreeNode<T>*, bool>parentsTracking;
		std::function<void(Visited<T>*)> func = [&parentsTracking](Visited<T>* visited)
		{
			if (visited != nullptr) {
				auto it = parentsTracking.find((AVLTreeNode<T>*)visited);
				if (it != parentsTracking.end()) {
					cout << "Loop spotted !" << endl;
				}
				else {
					parentsTracking.insert(pair<AVLTreeNode<T>*, bool>((AVLTreeNode<T>*)visited, false));
				}
			}
		};
		Visitor<T> visitor = Visitor<T>(func);
		this->_root->PostOrderVisit(visitor);
	}
	void ParentLinksUpdate() {
		std::function<void(Visited<T>*)> func = [](Visited<T>* visited)
		{
			if (visited != nullptr) {
				AVLTreeNode<T>* node = (AVLTreeNode<T>*)visited;
				if (node->GetLeftChild() != nullptr) {
					node->GetLeftChild()->SetParent(node);
				}
				if (node->GetRightChild() != nullptr) {
					node->GetRightChild()->SetParent(node);
				}
			}
		};
		Visitor<T> visitor = Visitor<T>(func);
		this->_root->PostOrderVisit(visitor);
	}
	void Rebalance(AVLTreeNode<T>* node) {
		AVLTreeNode<T>* tmp = node;
		bool balanced = true;
		if (tmp != nullptr) {
			std::map< AVLTreeNode<T>*, bool>parentsTracking;
			parentsTracking.insert(pair<AVLTreeNode<T>*, bool>(tmp, false));
			while (tmp != nullptr && balanced) {
				balanced = tmp->IsBalanced();
				auto it = parentsTracking.find(tmp->_parent);
				if (it != parentsTracking.end()) {
					int i = 0;
					cout << "Loop spotted !" << endl;
				}
				else {
					parentsTracking.insert(pair<AVLTreeNode<T>*, bool>(tmp->_parent, false));
				}
				if (balanced) {
					tmp = tmp->_parent;
				}
			}
			if (!balanced) {
				int LHeight = 0;
				int RHeight = 0;
				AVLTreeNode<T>* lChild = (AVLTreeNode<T>*)tmp->_leftChild;
				if (lChild != nullptr) {
					LHeight = lChild->GetHeight();
				}
				AVLTreeNode<T>* rChild = (AVLTreeNode<T>*)tmp->_rightChild;
				if (rChild != nullptr) {
					RHeight = rChild->GetHeight();
				}
				if ((LHeight - RHeight) > 1) {
					AVLTreeNode<T>* llChild = (AVLTreeNode<T>*)lChild->_leftChild;
					AVLTreeNode<T>* lrChild = (AVLTreeNode<T>*)lChild->_rightChild;
					int llHeight = 0;
					int lrHeight = 0;
					if (lrChild != nullptr) {
						lrHeight = lrChild->GetHeight();
					}
					if (llChild != nullptr) {
						llHeight = llChild->GetHeight();
					}
					if ((llHeight - lrHeight) < 0) {
						// left right rotate tmp'
						AVLTreeNode<T>* k1 = (AVLTreeNode<T>*) tmp->_leftChild;
						this->LeftRotation(k1);
					}
					this->RightRotation(tmp);
					this->Rebalance(tmp);
				}
				else if ((LHeight - RHeight) < -1) {
					AVLTreeNode<T>* rlChild = (AVLTreeNode<T>*)rChild->_leftChild;
					AVLTreeNode<T>* rrChild = (AVLTreeNode<T>*)rChild->_rightChild;
					int rlHeight = 0;
					int rrHeight = 0;
					if (rlChild != nullptr) {
						rlHeight = rlChild->GetHeight();
					}
					if (rrChild != nullptr) {
						rrHeight = rrChild->GetHeight();
					}
					if ((rlHeight - rrHeight) < -1) {
						// right left rotate tmp
						AVLTreeNode<T>* k3 = (AVLTreeNode<T>*)  tmp->_rightChild;
						this->RightRotation(k3);
					}
					this->LeftRotation(tmp);
					this->Rebalance(tmp);
				}
				UpdateRoot(node); if (true) {
					
				}
			}
		}
	}
	AVLTreeNode<T>* _root;
	AVLTreeNode<T>* _lastInserted = nullptr;
};
