#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
using namespace std;

template <class T>
struct strnode
{
	T data;
	strnode <T> *next;
	strnode <T> *down;

	strnode<T>()
	{}

	strnode<T>(const T &s, strnode * link, strnode * docs)
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

template <class T>
class linkedlist
{
private:
	strnode<T> *head;		//Head node, start of LinkedList
	void printListInverse(strnode<T> *n);


public:
	linkedlist<T>();			//Constructor	
    strnode<T> * gethead(){return head;}
	void addToEnd(T n);	//Inserts new node at the end of the LinkedList with given data
	void addtoDown(T n,T i);
};

template <class T>
linkedlist<T>::linkedlist()
{
    head = nullptr;
}

template <class T>
void linkedlist<T>::addToEnd(T n)
{
    strnode<T> *ptr = head;
    strnode<T> *temp = new strnode<T>(n, nullptr, nullptr);
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

template <class T>
void linkedlist<T>::addtoDown(T n, T i)
{
    strnode<T> *ptr = head;
    strnode<T> *ptr2 = nullptr;
    strnode<T> *prev = nullptr;
    strnode<T> *temp = new strnode<T>(i, nullptr, nullptr);
	bool entered = false;
    while(ptr != NULL)
    {
        if (ptr->data == n)
        {
            if (ptr->down == NULL) //first doc number case 2
            {
                ptr->down = temp;
            }
            else if(stoi(ptr->down->data) > stoi(i))  // if the listis not empty case 4
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
                    if(stoi(prev->data) < stoi(i) && stoi(i) <
                       stoi(ptr2->data)) // case 1
                    {
                        prev-> down = temp;
                        temp->down = ptr2;
                        entered = true;
                    }
                }
				if(!entered)
				{ptr2->down = temp;} //case 3
            }
        }
        
        
        ptr=ptr->next;
        
    }
}

#endif