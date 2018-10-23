/*************************************
*Modified by Gizem Gezici
*Date: 05.03.2012
*Modified by Gizem Gezici on 13.03.2012 (Bug fix on addToEnd member function)
*************************************/

#include <iostream>
#include "linkedList.h"

using namespace std;

linkedlist::linkedlist()
{
	head = nullptr;
}

//TODO: implement the following function 
//If the list is empty print  "List is empty"
//Otherwise print each node's content to a different line
void linkedlist::printList()
{	
	//TODO: implement this 
}

void linkedlist::addToEnd(string n)
{
	strnode *ptr = head;
	strnode *temp = new strnode(n, nullptr, nullptr);
	//List is empty
	if(head == nullptr)
	{
		head = temp;
	}
	else
	{
		while(ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void linkedlist::addToBeginning(string n)
{
	//List is empty
	if(head == nullptr)
	{
		strnode *ptr = new strnode(n, nullptr, nullptr);
		head = ptr;
		head->next = nullptr;
	}
	else
	{
		strnode *ptr = new strnode(n, head, nullptr);
		head = ptr;
	}
}

void linkedlist::addtoDown(string n, int i)
{
	strnode *ptr = head;
	intnode *ptr2 = nullptr;
	intnode *prev = nullptr;
	intnode *temp = new intnode(i, nullptr, nullptr);
	while(ptr != NULL)
	{
		if (ptr->data == n)
		{
			if (ptr->down == NULL) //first doc number
			{
                void *tempptr;
                tempptr = ptr->down;
                tempptr = temp;
			}
			else	 // if the list is not empty
			{
                void *tempptr2;
                tempptr2 = ptr2;
				tempptr2 = ptr->down;

				while (i > ptr2->data)	 //find its place according to data	
				{  
					if(ptr2-> down == NULL){
						ptr2->down = temp;
					}	
					else
					{prev = ptr2;
					ptr2 = ptr2->down; }			
				}

				prev->down = temp;
				temp->down = ptr2;
			}
			
			ptr = ptr->down;
			
		}

   		ptr=ptr->next;
	}
}

/*
Delete Function could be implemented here.
*/

void linkedlist::printListInverse()
{
	if(head != NULL)
	{
		printListInverse(head);
	}
}

void linkedlist::printListInverse(strnode *n)
{
	if(n->next != NULL)
	{
		printListInverse(n->next);
	}
	cout << n->data << endl;
}

