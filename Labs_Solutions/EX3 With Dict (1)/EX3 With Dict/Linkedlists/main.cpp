#include "LinkedList.h"
#include <iostream>

using namespace std;

//Function prototypes 

///////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList<int> L;	//create an object of class LinkedList
	int val;

	cout<<"\nPlease enter int values to add to the list (-1 to stop):\n";
	cin>>val;
	while(val != -1)
	{
		L.InsertBeg(val);
		cin>>val;
	}
	L.PrintList();

	cout<<" \n ..............  Lab Requirements .............\n";
	cout<<"\n Check File LinkedList.h and write the required member functions";
	cout<<"\n Then test these functions by calling them from the main()";
	
	cout << "\n\n--------------- Test InsertEnd Method ---------------" << endl;
	cout << "\nPlease enter int values to add to the list From the End (-1 to stop):\n";
	cin >> val;
	while (val != -1)
	{
		L.InsertEnd(val);
		cin >> val;
	}
	L.PrintList();
	cout<<endl;

	cout << "\n\n--------------- Test Find Method ---------------" << endl;
	cout << "Enter Value to search for: ";
	cin >> val;
	cout << "The Value " << val << " is " << (L.Find(val) ? "Found" : "Not found") << endl;

	cout << "\n\n--------------- Test CountOccurance Method ---------------" << endl;
	cout << "Enter Value to count its occurances : ";
	cin >> val;
	cout << "The Value " << val << " Exist " << L.CountOccurance(val)<<" Time(s)" << endl;

	cout << "\n\n--------------- Test DeleteFirst Method ---------------" << endl;
	L.DeleteFirst();
	cout << "List after deletion of first node :-" << endl;
	L.PrintList();

	cout << "\n\n--------------- Test DeleteLast Method ---------------" << endl;
	L.DeleteLast();
	cout << "List after deletion of last node :-" << endl;
	L.PrintList();

	cout << "\n\n--------------- Test DeleteNode Method ---------------" << endl;
	cout << "Enter Value to delete from the list (delete only first occurence): ";
	cin >> val;
	L.DeleteNode(val);
	cout << "List after deletion of "<<val<<" from the list:-" << endl;
	L.PrintList();

	cout << "\n\n--------------- Test DeleteNodes Method ---------------" << endl;
	cout << "Enter Value to delete from the list (delete all occurences): ";
	cin >> val;
	L.DeleteNodes(val);
	cout << "List after deletion of " << val << " from the list:-" << endl;
	L.PrintList();

	LinkedList<int> L2;
	cout << "\nPlease enter int values to add to the new list (-1 to stop):\n";
	cin >> val;
	while (val != -1)
	{
		L2.InsertBeg(val);
		cin >> val;
	}
	L2.PrintList();


	cout << "\n\n--------------- Test Merge Method ---------------" << endl;
	L.Merge(L2);
	cout << "Original List after merge :-" << endl;
	L.PrintList();
	cout << "\nNew list after merge :-" << endl;
	L2.PrintList();

	cout << "\n\n--------------- Test MergeAndRemove Method ---------------" << endl;
	L.MergeAndRemove(L2);
	cout << "Original List after merge :-" << endl;
	L.PrintList();
	cout << "\nNew list after merge :-" << endl;
	L2.PrintList();


	cout << "\n\n--------------- Test Reverse Method ---------------" << endl;
	L.Reverse();
	cout << "Original List after reverse :-" << endl;
	L.PrintList();
	

	cout << "\n\n--------------- Test PrintKth Method ---------------" << endl;
	cout << "ELement enter index of element you want to print: ";
	cin >> val;
	L.PrintKth(val);
	cout << endl;

	cout << "\n\n--------------- Test insertSorted Method ---------------" << endl;
	cout << "ELement enter element you want to insert to sorted list: ";
	cin >> val;
	L.insertSorted(val);
	L.PrintList();
	cout << endl;

	cout << "\n\n--------------- Test RemoveMin Method ---------------" << endl;
	L.RemoveMin();
	L.PrintList();
	cout << endl;

	cout << "\n\n--------------- Test CloneList Method ---------------" << endl;
	LinkedList<int> NewList ;
	NewList = L.CloneList();
	NewList.PrintList();
	cout << endl;

	cout << "\n\n--------------- Test SignSplit Method ---------------" << endl;
	LinkedList<int> posl, negl;
	NewList.SignSplit(negl, posl);
	NewList.PrintList();
	negl.PrintList();
	posl.PrintList();
	cout << endl;

	cout << "\n\n--------------- Test MergeSorted Method ---------------" << endl;
	LinkedList<int> List1, List2,List3;
	for (int i = 0;i < 5;i++)
		List1.InsertEnd(i);
	for (int i = 1;i < 9;i*=2)
		List2.InsertEnd(i);
	List1.PrintList();
	List2.PrintList();
	List3 = List1.MergeSorted(List2);
	List3.PrintList();
	List1.PrintList();
	List2.PrintList();
	cout << endl;

	
	cout << "\n\n--------------- Test SumLists Method ---------------" << endl;
	for (int i = 0;i < 5;i++)
		List1.InsertEnd(i);
	for (int i = 5;i < 10;i++)
		List2.InsertEnd(i);
	List1.PrintList();
	List2.PrintList();
	LinkedList<int> *newListPtr = List1.SumLists(List2);
	if(newListPtr)
		newListPtr->PrintList();

	cout << "\n\n--------------- Test SumLists Method ---------------" << endl;
	List1.DeleteAll();
	for (int i = 0;i < 10;i++)
	{
		List1.InsertEnd(rand() % 10 + 1);
	}
	List1.PrintList();
	List1.Reorder_X(4);
	List1.PrintList();
	
	cout << "\n\n--------------- Test SumLists Method ---------------" << endl;
	List1.RemoveDuplicates();
	List1.PrintList();

	cout << "\n\n--------------- Test ShiftLargest Method ---------------" << endl;
	List1.ShiftLargest();
	List1.PrintList();

	cout << "\n\n--------------- Test MakeDictionary Method ---------------" << endl;
	LinkedList<Dictionary<int>> ListDict;
	ListDict = List3.MakeDictionary();
	ListDict.PrintList();

	/*cout << "\n\n--------------- Test DeleteFirst Method ---------------" << endl;
	List99.DeleteFirst();
	cout << "List after deletion of first node :-" << endl;
	List99.PrintList();

	cout << "\n\n--------------- Test DeleteLast Method ---------------" << endl;
	List99.DeleteLast();
	cout << "List after deletion of last node :-" << endl;
	List99.PrintList();*/
	return 0;
}

