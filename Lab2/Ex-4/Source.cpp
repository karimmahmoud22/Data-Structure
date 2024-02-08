#include "myPair.h"
#include "myMap.h"
#include <iostream>
#include <string>
using namespace std;

//Credit -- Yehia Zakaria

int GetAction()
{

	int action;

	cout << "Choose The Action Number \n";
	cout << "1- Add New Pairs \n";
	cout << "2- Update Existing Pair \n";
	cout << "3- Search For A Value Given Key \n";
	cout << "4- Delete A Certain Pair \n";
	cout << "5- Print Map Content \n";
	cout << "6- Exit \n";
	cin >> action;
	return action;
}

int main()
{


	int Action = 0;

	myMap<int, string, 200> d;

	while (Action != 6)
	{
		string value = "";
		int key;
		Action = GetAction();
		bool added = false;
		bool get = false;
		bool updated = false;
		switch (Action)
		{
		case 1:
			cout << "Enter Key: ";
			cin >> key;
			cout << "Enter Value: ";
			cin >> value;
			added = d.addPair(myPair<int, string>(key, value));
			if (added)
				cout << "Pair Added Succefully \n";
			else
				cout << "No Space In The Map \n";
			break;
		case 3:
			cout << "Enter Key: ";
			cin >> key;
			get = d.getValue(key, value);
			if (get)
				cout << "Value: " << value << '\n';
			else
				cout << "This Key Isn't In The Map \n";
			break;
		case 2:
			cout << "Enter Key To Updat It's Value: ";
			cin >> key;
			cout << "Enter New Value: ";
			cin >> value;
			updated = d.updateValue(key, value);
			if (updated)
				cout << "Updated \n";
			else
				cout << "Key Not Found \n";
			break;
		case 4:
			cout << "Enter Key To delete: ";
			cin >> key;
			cout << "Enter Value: ";
			cin >> value;
			d.deletePair(myPair<int, string>(key, value));
			break;
		case 5:
			d.displayMap();
			break;
		default:
			break;
		}
	}
	d.displayMap();
}