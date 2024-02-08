#include "LinkedList.h"

int main()
{
	// TEST 1: InsertBeg()

	cout << "\n.... TESTING InsertBeg() ..." << endl;

	LinkedList<int> MyList;

	MyList.InsertBeg(1);
	MyList.InsertBeg(2);
	MyList.InsertBeg(3);
	MyList.InsertBeg(4);

	MyList.PrintList();

	// TEST 2: InsertEnd()

	cout << "\n.... TESTING InsertEnd() ..." << endl;

	LinkedList<int> MyList2;

	MyList2.InsertEnd(1);
	MyList2.InsertEnd(2);
	MyList2.InsertEnd(3);
	MyList2.InsertEnd(4);

	MyList2.PrintList();

	// TEST 3: RemoveLast()

	cout << "\n.... TESTING RemoveLast() ..." << endl;

	LinkedList<int> MyList3 ( 3 ); // this constructor will create n random nodes (data from 0 to 9)
	
	MyList3.PrintList();

	Node<int> * removed = MyList3.RemoveLast();

	MyList3.PrintList();
	cout << "the removed node" << removed->getItem() << endl;

	// TEST 4: DeleteNodesVal()

	cout << "\n.... TESTING  DeleteNodesVal() ..." << endl;

	// -- test 4.1

	cout << "\n*** TEST 4.1:" << endl;

	int arr_1 [] = {6, 6, 8, 6, 9};

	LinkedList<int> MyList4 ( arr_1, 5 ); // this constructors builds the linked list from the passed array

	MyList4.PrintList();

	MyList4.DeleteNodesVal(6);

	MyList4.PrintList();

	// -- test 4.2
	cout << "\n*** TEST 4.2:" << endl;

	int arr_2 [] = {6, 6, 8, 6};

	LinkedList<int> MyList5 ( arr_2, 4 ); // this constructors builds the linked list from the passed array

	MyList5.PrintList();

	MyList5.DeleteNodesVal(6);

	MyList5.PrintList();

	// -- test 4.3
	cout << "\n*** TEST 4.3:" << endl;

	int arr_3 [] = {6, 6, 6};

	LinkedList<int> MyList6 ( arr_3, 3 ); // this constructors builds the linked list from the passed array

	MyList6.PrintList();

	MyList6.DeleteNodesVal(6);

	MyList6.PrintList();

	// -- test 4.4
	cout << "\n*** TEST 4.4:" << endl;

	int arr_4 [] = {6};

	LinkedList<int> MyList7 ( arr_4, 1 ); // this constructors builds the linked list from the passed array

	MyList7.PrintList();

	MyList7.DeleteNodesVal(6);

	MyList7.PrintList();

	// -- test 4.5
	cout << "\n*** TEST 4.5:" << endl;

	int arr_5 [] = {2, 3, 4};

	LinkedList<int> MyList8 ( arr_5, 3 ); // this constructors builds the linked list from the passed array

	MyList8.PrintList();

	MyList8.DeleteNodesVal(6);

	MyList8.PrintList();

}