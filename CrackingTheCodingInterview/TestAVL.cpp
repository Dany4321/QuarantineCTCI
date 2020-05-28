#include "TestAVL.h"
// https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct
void TestAVL::AddTest() {
	////////////////////////
	int elems[2] = { 6, 8};
	MyAVLTree<int>* tree = new MyAVLTree<int>(4);
	for (int i = 0; i < 2; i++) {
		tree->InsertValue(elems[i]);
	}
	tree->Print();
	///////////////////////
	delete tree;
	tree = new MyAVLTree<int>(4);
	elems[0] = 8;
	elems[1] = 6;
	for (int i = 0; i < 2; i++) {
		tree->InsertValue(elems[i]);
	}
	tree->Print();
	//////////////////////
	delete tree;
	tree = new MyAVLTree<int>(8);
	elems[0] = 6;
	elems[1] = 4;
	for (int i = 0; i < 2; i++) {
		tree->InsertValue(elems[i]);
	}
	tree->Print();
	//////////////////////
	delete tree;
	tree = new MyAVLTree<int>(6);
	elems[0] = 4;
	elems[1] = 5;
	for (int i = 0; i < 2; i++) {
		tree->InsertValue(elems[i]);
	}
	tree->Print();
	////////////////////
	int finalElems[49] = { 
67,
34,
0 ,
69,
24,
78,
58,
62,
64,
5 ,
45,
81,
27,
61,
91,
95,
42,
27,
36,
91,
4 ,
2 ,
53,
92,
82,
21,
16,
18,
95,
47,
26,
71,
38,
69,
12,
67,
99,
35,
94,
3 ,
11,
22,
33,
73,
64,
41,
11,
53,
68 };
	// 41,
	delete tree;
	tree = new MyAVLTree<int>(41);
	for (int i = 0; i < 49; i++) {
		tree->InsertValue(finalElems[i]);
	}
	tree->Print();
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