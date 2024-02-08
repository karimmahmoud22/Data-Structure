
#include "BSTree.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	BSTree bst;

	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9

	//==============================================================
	//							InsertBST function
	//==============================================================
	cout << "building the tree with sequence 8 13 3 9 1 4" << endl << endl;
	bst.insertBST(8);
	bst.insertBST(13);
	bst.insertBST(3);
	bst.insertBST(9);
	bst.insertBST(1);
	bst.insertBST(4);
	/*
	//==============================================================
	//							Traversal
	//==============================================================
	// traverse the tree with different orders
	cout << "The tree pre-order traversal" << endl;
	bst.preorder_traverse();
	cout << endl;

	cout << "The tree in-order traversal" << endl;
	bst.inorder_traverse();
	cout << endl;

	cout << "The tree post-order traversal" << endl;
	bst.postorder_traverse();
	cout << endl;
	*/

	Node* pp =  bst.find_max();
	cout<<pp->getdata()<<endl;

	Node* p = bst.find_min();
	cout << p->getdata() << endl;

	int ppp = bst.max_depth();
	cout << ppp << endl;
	/*
	int nnn;
	cin >> nnn;
	bool test = bst.search(nnn);
	if (test)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	*/

	/*
	int oo;
	cin >> oo;
	int yy = bst.less(oo);
	cout << yy << endl;
	*/

	/*
	//******************************NOT COMPLETED YET***************************
	int uu;
	cin >> uu;
	bool tt = bst.PrintSmallerEq(uu);
	*/

	//==============================================================
	//							Destroy
	//==============================================================
	cout << "Destroying tree " << endl;
	bst.destroy_tree();
	char c;
	cin >> c;
	return 0;
}
