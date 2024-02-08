#include <iostream>\
#include <string>
#include "MYPAIR.h"
#include "myMap.h"

using std::cout;
using std::cin;

void Take_Suitable_Action(int choice, myMap<int, std::string>& test);

//the following is better because the two pair need not hold the same key-value types .
//Example : i might need to compare <int,int> pair with a <double,float> one and this should be allowed
template<typename keyT, typename valueT, typename differentKeyT, typename differentValueT>
 bool operator==(mypair<keyT, valueT>,
	             mypair<differentKeyT, differentValueT>);

 
int main() {

		myMap<int, std::string> test;
		cout << "Enter A choice from the following Menu :\n";
		cout << "1- Add new pairs\n";
		cout << "2- Update existing pair\n";
		cout << "3- Search for a value given a key\n";
		cout << "4- Delete a certain pair\n";
		cout << "5- Print map contents\n";
		int choice;
		cin >> choice;


		Take_Suitable_Action(choice, test);
		cout << "Wish to Enter Another choice? y/n";
		char decision;
		while (1) {
			cin >> decision;
			if (decision == 'y') {
				cin >> choice;
				Take_Suitable_Action(choice, test);
			}
			else break;
		}
}

void Take_Suitable_Action(int choice, myMap<int, std::string>& M)
{
	switch (choice) {
	case 1: {
		cout << "\n\nEnter a pair in the form: number string ";
		int num; std::string str;
		cin >> num >> str;
		M.addPair(mypair<int, std::string>(num, str));
		break;
	}
	case 2: {
		cout << "\n\nEnter the number of the pair you want to update : ";
		int num;
		cin >> num;
		cout << "\nEnter the new string value :";
		std::string value;
		cin >> value;

		bool succcessful = M.updateValue(num, value);
		if (!succcessful) {
			cout << "ERROR: NO SUCH KEY EXISTS";
		}
		else cout << "Pair Updated Successfully";
		break;
	}
	case 3: {
		cout << "\n\nEnter the ID of the Value you want to search for : ";
		int ID;
		cin >> ID;

		mypair<std::string, bool> result = M.getValue(ID);
		if (result.getValue() == true) cout << "\nVALUE FOUND! The name is  " << result.getKey();
		else cout << "\nERROR: NO SUCH ID EXISTs";
		break;
	}
	case 4: {
		cout << "\n\nEnter the pair you want to delete in the form: Number string :";
		int i;
		std::string S;
		cin >> i >> S;

		M.deletePair(mypair<int, std::string>(i, S));
		break;
	}
	case 5: {
		cout << "\n\nHere Is the Map :\n";
		M.displayMap();
		break;
	}

	default: cout << "\nERROR: NO SUCH ACTION EXISTS";
	}
}

template<typename keyT, typename valueT, typename differentKeyT, typename differentValueT> 
inline bool operator==(mypair<keyT,valueT> one, mypair<differentKeyT, differentValueT> another)
{
	return another.K == one.K && another.V == one.V;
}