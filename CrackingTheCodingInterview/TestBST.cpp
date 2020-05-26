#include "TestBST.h"
void TestBST::AddTest() {
	BinarySearchTree<int> tree = BinarySearchTree<int>(10);
	tree.InsertValue(5);
	tree.InsertValue(2);
	tree.InsertValue(6);
	tree.InsertValue(15);
	tree.InsertValue(12);
	tree.InsertValue(16);
	tree.Print();
}
void TestBST::RemoveTest() {

}
void TestBST::SucessorTest() {

}
void TestBST::RunAllTests() {
	AddTest();
}