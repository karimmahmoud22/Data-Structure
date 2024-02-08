#pragma once
#include <iostream>
#include "myMap.h"

using std::cout;


struct position {
	int x, y;
};

class Creature {
public :
	Creature() {
	}
};

class Monster : public Creature {
public:
	Monster() {
		cout << "MONSTER !!";
	}
};
class Dragon : public Creature {
public:
	Dragon() {
		cout << "Dragon !!";
	}
};
class Player : public Creature {
public:
	Player() {
		cout << "Player !!";
	}
};
class Soldier : public Creature {
public:
	Soldier() {
		cout << "Soldier !!";
	}
};

// 1--) Like this
void mapping() {
	myMap<Creature*, position> MAP;
}
//2--) The following functions And operators 

/*
bool operator==(Creature*, Creature*);
bool operator==(position, position);


 As Many instances as needed of :
   virtual void operator=(Creature*,Creature*);   
 to take care of copying for each class 

(ALSO, we need to override the operator= for myPair<Creature*,Position> to copy correctly )



ostream& operator<<(Creature*) ; to take Care of Printing (Makes use of polymorphism to display derieved classes correctly)
ostream& operator<<(position) ;  


*/
