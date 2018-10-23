
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
using namespace std;

struct strnode
{
	string data;
	strnode *next;
	strnode *down;

	strnode()
	{}

	strnode(const string &s, strnode * link, strnode * docs)
		: data(s), next(link), down(docs)
	{}
};

/*struct intnode
{
	int data;
	intnode *next;
	intnode *down;

	intnode()
	{}

	intnode(const int &i, intnode * link, intnode * docs)
		: data(i), next(link), down(docs)
	{}
};*/

class linkedlist
{
private:
	strnode *head;		//Head node, start of LinkedList
	void printListInverse(strnode *n);


public:
	linkedlist();			//Constructor
	void printList();		//Prints the given LinkedList from head to end
	void printListInverse();//Prints the given LinkedList from end to head

	void addToBeginning(string n);	//Inserts new node at the beginning of the LinkedList with given data
	void addToEnd(string n);	//Inserts new node at the end of the LinkedList with given data
	void addtoDown(string n,string i);
};


#endif
