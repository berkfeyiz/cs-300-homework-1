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
    int same = 0;
	//List is empty
	if(head == nullptr)
	{
		head = temp;
	}
	else
	{
		while(ptr->next != nullptr)
		{
            if(ptr->next->data == n || ptr->data == n){same++;}
            
			ptr = ptr->next;
		}
        if(same == 0){ptr->next = temp;}
		
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

void linkedlist::addtoDown(string n, string i)
{
	strnode *ptr = head;
	strnode *ptr2 = nullptr;
	strnode *prev = nullptr;
	strnode *temp = new strnode(i, nullptr, nullptr);
	while(ptr != NULL)
	{
		if (ptr->data == n)
		{
			if (ptr->down == NULL) //first doc number case 2
			{
                ptr->down = temp;
			}
            else if(stoi(ptr->down->data) > stoi(i))  // if the list is not empty case 4
            {
                ptr2 = ptr-> down;
                ptr->down = temp;
                temp->down =ptr2;
            }
			else //between two nodes or at the end
			{
                ptr2 = ptr->down;
                while(ptr2->down != NULL)
                {
                    prev = ptr2;
                    ptr2 = ptr2->down;
                    if(stoi(prev->data) < stoi(i) && stoi(i) < stoi(ptr2->data)) // case 1
                    {
                           prev-> down = temp;
                           temp->down = ptr2;
                          
                    }
                }
            ptr2->down = temp; //case 3
            }
			
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

