#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include"Dictionary.h"

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	Node<T>* Tail;
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll(); 
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{		
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{

		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		if (!Head) // Empty List
			Tail = R;
		Head = R;
		

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		Tail = nullptr;
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data)// Note that using tail pointer makes addition from last comlexity O(1)
	{
		Node<T>* newNode = new Node<T>(data);
		//newNode->setNext(nullptr); // not necessary --> constructor handle it
		if (!Head) // if the List is empty 
		{
			Head = Tail = newNode; // the only element in the list
		}
		else {
			Tail->setNext(newNode);
			Tail = newNode;
		}
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key) // only traverse and check if the value exist
	{
		Node<T>* CurPtr = Head;			// initial state
		while (CurPtr)					//Condition
		{
			if (CurPtr->getItem() == Key)
				return true;
			CurPtr = CurPtr->getNext(); //Update Condition 
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) //Like Find but traverse and count 
	{
		Node<T>* CurPtr = Head;				// initial state
		int count = 0;						//Condition
		while (CurPtr)
		{
			if (CurPtr->getItem() == value)
				count++;
			CurPtr = CurPtr->getNext();		//Update Condition 
		}
		return count;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst()
	{
		if (!Head) // if the list is empty
			return;
		if (!Head->getNext()) // if the list has only one Node 
			Tail = nullptr;

		Node<T>* FirstNode = Head;
		Head = Head->getNext();		
		FirstNode->setNext(nullptr); // not necessary
		delete FirstNode;
		FirstNode = nullptr;		//not necessary
	}


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() // Note that using tail pointer makes deletion from last comlexity O(1)
	{
		if (!Head) // if the list is already empty
			return;
		if (!Head->getNext()) // if the list has only one element 
		{
			delete Tail;
			Tail = Head = nullptr;
			return;
		}
			
		Node<T>* CurPtr = Head;
		while (CurPtr->getNext() != Tail) // reach to the element berfore the last one
		{
			CurPtr = CurPtr->getNext();
		}
		delete Tail;
		Tail = CurPtr;
		Tail->setNext(nullptr);
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value)
	{
		if (!Head) // if the list is empty
			return false;
		if (Head->getItem() == value) // if the first item is the one to be deleted
		{							 
			DeleteFirst();								
			return true;										
		}
		Node<T>* PrevPtr = Head;
		Node<T>* CurPtr = Head->getNext();
		while (CurPtr) // This also handles the case in which the list has only one element
		{
			if (CurPtr->getItem() == value)
			{
				if (CurPtr == Tail) // if the element to be deleted is the last one 
				{
					DeleteLast();
					return true;
				}
				PrevPtr->setNext(CurPtr->getNext());
				CurPtr->setNext(nullptr);
				delete CurPtr;
				return true;
			}
			PrevPtr = CurPtr;
			CurPtr = CurPtr->getNext();
		}
		return false;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value)
	{
		int IsFound = false;
		if (!Head) // if the list is empty
			return false;
		while(Head->getItem() == value) // deletes all values required to be removed the at first position
		{
			DeleteFirst();
			IsFound = true;
			if (!Head) // if the list become empty 
				return true; // this protect the error that may be generated from the condition of the loop
		}
		
		Node<T>* PrevPtr = Head;
		Node<T>* CurPtr = Head->getNext();
		while (CurPtr) // This also handles the case in which the list has only one element
		{
			
			if (CurPtr->getItem() == value)
			{
				if (CurPtr == Tail) // if the element to be deleted is the last one 
				{
					DeleteLast();
					IsFound = true;
					CurPtr = nullptr; // The last one is removed & it was CurPtr So it become null
				}
				else 
				{
					//Normal deletion
					PrevPtr->setNext(CurPtr->getNext()); //set previous next to the Current next 
					CurPtr->setNext(nullptr);            //Not necessary
					delete CurPtr;
					CurPtr = PrevPtr->getNext();
					IsFound = true;
				}
			}
			else {
				PrevPtr = CurPtr;
				CurPtr = CurPtr->getNext();
			}
		}
		return IsFound;
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L)
	{
		/*
		* Can this be achieved by making the last Node in the current list point to the first Node in list L?
		* Yes may be achived but in this case we will empty the second List
		* Implemented in Method MergeAndRemove
		* This cannot be achived here because L is const
		*/
		Node<T>* IterateOverL = L.Head;
		while (IterateOverL)
		{
			InsertEnd(IterateOverL->getItem());
			IterateOverL = IterateOverL->getNext();
		}
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse()
	{
		if (!Head || !Head->getNext()) // if the list is empty or has one element no need for reverse
			return;
		//PrevPtr Keeps the address of the Node which is disconnected form the List and pointed backward
		Node<T>* PrevPtr = nullptr; 
		Node<T>* CurPtr = Head;
		//NxtPr Keeps the address of the node next to the CurPtr as we cannot access it after pointing the Curptr backward
		Node<T>* NxtPtr = nullptr;
		while (CurPtr)
		{
			//NxtPtr points to the node next to the current
			//This Must be before Pointing CurPtr next backward
			NxtPtr = CurPtr->getNext();
			CurPtr->setNext(PrevPtr);	//Pointing CurPtr next Backward
			PrevPtr = CurPtr;			//Keep address of CurPtr's node after disconnecting it
			CurPtr = NxtPtr;			//shift CurPtr
		}
		
		Node<T>* TempPtr = Head;
		Head = PrevPtr;
		Tail = TempPtr;
	}
	
	void MergeAndRemove(LinkedList& L)
	{
		/*
		* Can this be achieved by making the last Node in the current list point to the first Node in list L?
		* Yes may be achived but in this case we will empty the second List
		* Implemented in Method MergeAndRemove
		*/
		if (!Head)
		{
			Tail = L.Tail;
			Head = L.Head;
			return;
		}
		Tail->setNext(L.Head);
		Tail = L.Tail;
		L.Head = nullptr;
		L.Tail = nullptr;
	}

	void PrintKth(int index)
	{
		Node<T>* CurPtr = Head;
		int i = 0;
		while (CurPtr)
		{
			if (i == index-1)
			{
				cout << CurPtr->getItem();
				return;
			}
			i++;
			CurPtr = CurPtr->getNext();
		}
		cout << "Beyond List Length"; 
	}

	bool insertSorted(T it)
	{
		Node<T>* CurPtr = Head;
		Node<T>* PrevPtr = Head;
		while (CurPtr)
		{
			if (CurPtr->getItem() == it) // if value exist already return
				return false;
			if (CurPtr->getItem() > it)
			{
				if (CurPtr == Head) // if we insert at the begining
				{
					InsertBeg(it);
					return true;
				}
					
				Node<T>* newNodePtr = new Node<T>(it);
				newNodePtr->setNext(CurPtr);
				PrevPtr->setNext(newNodePtr);
				if(CurPtr->getNext() == nullptr) //if CurPtr is the last element
					Tail = CurPtr;
				return true;
			}
			PrevPtr = CurPtr;
			CurPtr = CurPtr->getNext();
		}
		InsertEnd(it); // if no value is greater than it then it will be the last one
		return true;
	}

	//How to sort using RemoveMin and insertSorted 
	//Think about selection sort
	//Find min then place in position
	/*
	* minPtr = RemoveMin();
	* insertSorted(minPtr->getItem();
	*/

	Node<T>* RemoveMin()
	{
		if (!Head) // Empty
			return nullptr;
		Node<T>* MinPtr = Head;
		Node<T>* MinPrevPtr = Head;
		Node<T>* CurPtr = Head;
		Node<T>* PrevPtr = Head;
		while (CurPtr) //get min and its previous
		{
			if (CurPtr->getItem() < MinPtr->getItem())
			{
				MinPtr = CurPtr;
				MinPrevPtr = PrevPtr;
			}
				
			PrevPtr = CurPtr;
			CurPtr = CurPtr->getNext();
		}
		if (MinPtr == Head) //if the min is the first one 
		{
			Head = Head->getNext();
			MinPtr->setNext(nullptr);
			return MinPtr;
		}
		else if (MinPtr == Tail) // if the min is the last one
		{
			Tail = MinPrevPtr;
		}
		MinPrevPtr->setNext(MinPtr->getNext());
		MinPtr->setNext(nullptr);
		//Note No delete
		return MinPtr;
	}

	LinkedList<T>& CloneList()
	{
		//Must be allocated dynamically so that it not deleted when get out of scope
		LinkedList<T> *NewList = new LinkedList<T>(); 
		Node<T>* CurPtr = Head;
		while (CurPtr)
		{
			NewList->InsertEnd(CurPtr->getItem()); // if InsertBeg is used list will be reversed
			CurPtr = CurPtr->getNext();
		}
		return *NewList;
	}
	void SignSplit(LinkedList<T>& Lneg, LinkedList<T>& Lpos)
	{
		Node<T>* CurPtr = Head;
		
		while (CurPtr)
		{
			T it = CurPtr->getItem();
			if (it == 0) //if 0 leave it
			{
				CurPtr = CurPtr->getNext();
				continue;
			}
			if (it < 0)
				Lneg.InsertEnd(it);
			else {
				Lpos.InsertEnd(it);
			}
			CurPtr = CurPtr->getNext(); //shift before delete 
			DeleteNode(it);
		}
	}
	LinkedList<T>& MergeSorted(LinkedList<T>&List)
	{
		//Sort Lists
		LinkedList<T>* NewList = new LinkedList<T>();
		Node<T>* CurPtr = Head;
		Node<T>* ListCurPtr = List.Head;
		while (CurPtr || ListCurPtr)
		{
			if (!ListCurPtr) // if List elements has finished add directly form The original list
			{
				NewList->InsertEnd(CurPtr->getItem());
				CurPtr = CurPtr->getNext();
				continue;
			}
			if (!CurPtr) // if The original list elements has finished add directly form List
			{
				NewList->InsertEnd(ListCurPtr->getItem());
				ListCurPtr = ListCurPtr->getNext();
				continue;
			}
			if (CurPtr->getItem() < ListCurPtr->getItem()) //if both lists still have elements add the smaller
			{
				NewList->InsertEnd(CurPtr->getItem());
				CurPtr = CurPtr->getNext();
			}
			else {
				NewList->InsertEnd(ListCurPtr->getItem());
				ListCurPtr = ListCurPtr->getNext();
			}
		}
		List.DeleteAll();
		DeleteAll();
		return *NewList;
	}

	LinkedList<T>* SumLists(LinkedList<T>& ListRecived)
	{
		Node<T>* CurPtr = Head;
		Node<T>* RecCurPtr = ListRecived.Head;
		LinkedList<T>* NewList = new LinkedList<T>();
		if (!CurPtr && !RecCurPtr) //if two lists are empty
			return nullptr;
		while (CurPtr!=nullptr && RecCurPtr!=nullptr) //Iterate until one reach its end or both of them
		{
			NewList->InsertEnd(CurPtr->getItem() + RecCurPtr->getItem());
			CurPtr = CurPtr->getNext();
			RecCurPtr = RecCurPtr->getNext();

		}
		if (CurPtr || RecCurPtr) // if one of the two lists doesn't reach to its end return nullptr
		{
			delete NewList;
			return nullptr;
		}
		return NewList;
	}
	void Reorder_X(T it)
	{
		Node<T>* CurPtr = Head;
		Node<T>* tempTail= Tail;
		while (CurPtr!=tempTail)
		{
			T TempIt = CurPtr->getItem();
			CurPtr = CurPtr->getNext();
			DeleteNode(TempIt);
			if (TempIt <= it)//if less than or equal insert at the begin
			{
				InsertBeg(TempIt);
			}
			else { //if less than or equal insert at the end
				InsertEnd(TempIt);
			}
		}
	}
	void RemoveDuplicates() 
	{
		Node<T>* CurPtr = Head;
		while (CurPtr)
		{
			T TempIt = CurPtr->getItem();
			CurPtr = CurPtr->getNext();
			Node<T>* TempCurPtr = CurPtr; // Starts from CurPtr
			while (TempCurPtr)
			{
				if (TempIt == TempCurPtr->getItem()) // if found in any other node delete it
				{
					DeleteNode(TempIt);
					break;
				}
				TempCurPtr = TempCurPtr->getNext();
			}
		}
	}
	//This looks like Bubble sort
	void ShiftLargest()
	{
		Node<T>*CurPtr = Head;
		while (CurPtr)
		{
			Node<T>*NewCurPtr = Head;
			while (NewCurPtr->getNext())
			{
				if (NewCurPtr->getItem() > NewCurPtr->getNext()->getItem()) // swap 
				{
					T tempIt = NewCurPtr->getItem();
					NewCurPtr->setItem(NewCurPtr->getNext()->getItem());
					NewCurPtr->getNext()->setItem(tempIt);
				}
				NewCurPtr = NewCurPtr->getNext();
			}
			CurPtr = CurPtr->getNext();
		}
	}
	LinkedList<Dictionary<T>>& MakeDictionary()
	{
		LinkedList<Dictionary<T>>* DictionaryList = new LinkedList<Dictionary<T>>();
		Node<T>* CurPtr = Head;
		Dictionary<T> D;
		while (CurPtr)
		{
			D.setKey(CurPtr->getItem());
			int occurence = CountOccurance(CurPtr->getItem());
			D.setCount(occurence);
			Node<T>* TempPtr = Head;
			bool found = false;
			while (TempPtr != CurPtr)
			{
				if (TempPtr->getItem() == CurPtr->getItem())
				{
					found = true;
					break;
				}
				TempPtr = TempPtr->getNext();
			}
			if (!found)
				DictionaryList->InsertEnd(D);
			CurPtr = CurPtr->getNext();
		}
		return *DictionaryList;
	}
};

#endif