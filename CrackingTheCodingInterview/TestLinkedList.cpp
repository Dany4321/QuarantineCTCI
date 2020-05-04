#include"TestLinkedList.h"
void TestLinkedList::RunAllTest() {
	//AddTest();
	//RemoveTest();
	RemoveDuplicates();
 }
 void TestLinkedList::AddTest() {
	 MyLinkedList<int> list;
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(3);
	 list.Push_Front(4);
	 list.Push_Front(5);
	 MyNode<int>*  node = list.GetRoot();
	 for (int i = 5; i > 0; --i) {
		 if (node->GetValue() != i) {
			 cout << "test failed" << endl;
		 }
		 node = node->GetNext();
	 }
	 
 }
 void TestLinkedList::RemoveTest() {
	 MyLinkedList<int> list = MyLinkedList<int>(true);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(1);
	 list.Push_Front(5);
	 list.Remove(1);
	 MyNode<int>*  node = list.GetRoot();
	 if (node->GetValue() == 4 ) {
		 cout << "test failed" << endl;
	 }
 }
 void TestLinkedList::RemoveDuplicates() {
	 MyLinkedList<int> list = MyLinkedList<int>(true);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(5);

	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(5);

	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(1);
	 list.Push_Front(2);
	 list.Push_Front(5);

	 list.RemoveDuplicates();
	 MyNode<int>*  node = list.GetRoot();
 }