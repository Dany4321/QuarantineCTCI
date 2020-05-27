#include "TestAVL.h"
void TestAVL::AddTest() {
	MyAVLTree<int> tree = MyAVLTree<int>(10);
	tree.InsertValue(5);
	tree.InsertValue(2);
	tree.InsertValue(6);
	tree.InsertValue(15);
	tree.InsertValue(12);
	tree.InsertValue(16);
	tree.Print();
}
void TestAVL::RemoveTest() {
	MyAVLTree<int> tree = MyAVLTree<int>(10);
	tree.InsertValue(5);
	tree.InsertValue(2);
	tree.InsertValue(6);
	tree.InsertValue(15);
	AVLTreeNode<int>* tmp = tree.GetPreviousInserted();
	tree.InsertValue(12);
	tree.InsertValue(16);
	AVLTreeNode<int>* node = tree.GetPreviousInserted();
	tree.RemoveNode(node);
	cout << "Retrait de 16" << endl;
	tree.Print();
	tree.InsertValue(16);
	node = tree.GetPreviousInserted();
	tree.InsertValue(18);
	tree.InsertValue(40);
	tree.InsertValue(14);
	tree.InsertValue(13);
	tree.RemoveNode(node);
	cout << "Retrait de 16" << endl;
	tree.Print();
	tree.RemoveNode(tmp);
	cout << "Retrait de 15" << endl;
	tree.Print();
}
void TestAVL::IsAnAVLTest() {
	MyAVLTree<int> tree = MyAVLTree<int>(10);

	tree.InsertValue(5);
	tree.InsertValue(2);
	tree.InsertValue(6);

	tree.InsertValue(15);

	tree.InsertValue(12);
	tree.InsertValue(16);
	tree.InsertValue(18);
	tree.InsertValue(40);
	tree.InsertValue(14);
	AVLTreeNode<int>* node = tree.GetPreviousInserted();
	tree.InsertValue(13);
	tree.Print();
	cout << "Successeur de 14 " << tree.FindSuccessor(node)->GetValue() << endl;
}
void TestAVL::RunAllTests() {
	AddTest();
	//RemoveTest();
	//SucessorTest();
}