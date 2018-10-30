#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "linkedList.h"

using namespace std;

void intersect(vector<string>& words, strnode<string>* head)
{
    strnode<string> *ptr = head;
    vector<string> foundwords;
    
    for(unsigned int i= 0; words.size()>i; i++)
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (words[i] == ptr->data)
            {
                foundwords.push_back(words[i]);
            }
            ptr = ptr->next;
        }
    }
    
    ptr = head;
    
    strnode<string> *downptr = nullptr;
    strnode<string> *downptrforcomp = nullptr;
    
    vector <int> intersecting;
    int count = 0;
    if(foundwords.size() == 0)
    {
      
        for(unsigned int i= 0; words.size()>i; i++)
        {
            cout << words[i] << " ";
        }
          cout << "0 ";
        cout << endl;
    }
    else if(foundwords.size() == 1)
    {
        ptr = head;
        while(ptr != NULL)
        {
            if(foundwords[0] == ptr->data)
            {
                downptr = ptr->down;
                cout << foundwords[0];
                
                downptr = ptr;
                while(downptr != NULL)
                {
                    downptr = downptr ->down;
                    count ++;
                }
                cout << " " << count-1 << " ";
                downptr = ptr -> down;
                while(downptr ->down != NULL)
                {
					downptr = downptr ->down;
					cout << downptr->data << " ";
                }
				cout << endl;
            }
            ptr = ptr->next;
        }
    }
    else if(foundwords.size() == 2)
    {
        for(unsigned int i= 0; 2>i; i++)
        {
            ptr = head;
            while (ptr != NULL)
            {
                if (foundwords[i] == ptr->data)
                {
                    if(downptr == nullptr)
                    {
                        downptr = ptr->down;
                    }
                    else if (downptrforcomp == nullptr)
                    {
                        downptrforcomp = ptr->down;
                    }
                    if (downptr != nullptr && downptrforcomp != nullptr)
                    {
                        while(downptr != NULL && downptrforcomp != NULL)
                        {
                            if(downptr->data == downptrforcomp->data)
                            {
                                intersecting.push_back(stoi(downptr->data));
                                downptr = downptr->down;
                                downptrforcomp = downptrforcomp ->down;
                            }
                            else if (stoi(downptr->data) > stoi(downptrforcomp->data))
                            {
                                downptrforcomp = downptrforcomp->down;
                            }
                            else if (stoi(downptr->data) < stoi(downptrforcomp->data))
                            {
                                downptr = downptr ->down;
                            }
                        }
                    }
                                   }
                ptr = ptr->next;
                
            }
        }
        
        for(unsigned int i= 0; words.size()>i; i++)
        {
            cout << words[i] << " ";
        }
        cout << intersecting.size();
        
        for(unsigned int i= 0; intersecting.size()>i; i++)
        {
            cout << " " << intersecting[i] << " ";
        }
		cout << endl;
    }
    if(foundwords.size() >2)
    {
        for(unsigned int i= 0; 2>i; i++)
        {
            ptr = head;
            while (ptr != NULL)
            {
                if (foundwords[i] == ptr->data)
                {
                    if(downptr == nullptr)
                    {
                        downptr = ptr->down;
                    }
                    else if (downptrforcomp == nullptr)
                    {
                        downptrforcomp = ptr->down;
                    }
                    if (downptr != nullptr && downptrforcomp != nullptr)
                    {
                        while(downptr != NULL && downptrforcomp != NULL)
                        {
                            if(downptr->data == downptrforcomp->data)
                            {
                                intersecting.push_back(stoi(downptr->data));
                                downptr = downptr->down;
                                downptrforcomp = downptrforcomp ->down;
                            }
                            else if (stoi(downptr->data) > stoi(downptrforcomp->data))
                            {
                                downptrforcomp = downptrforcomp->down;
                            }
                            else if (stoi(downptr->data) < stoi(downptrforcomp->data))
                            {
                                downptr = downptr ->down;
                            }
                           // if(downptr == NULL || downptrforcomp == NULL){break;}
                        }
                        
                    }
                }
                ptr = ptr->next;
                
            }
        }
        
        bool isitthere = false;
        
        for (unsigned int i = 2; foundwords.size() > i; i ++)
        {
           ptr = head;
            while (ptr != NULL)
            {
                if (foundwords[i] == ptr->data)
                {
                    downptr = ptr->down;
                    for(unsigned int j = 0; intersecting.size() >j; j++)
                    {
                       isitthere = false;
                        while(downptr != NULL)
                        {
                            if(stoi(downptr->data) == intersecting[j])
                            {isitthere = true;downptr = ptr->down;break;}
                            
                             downptr = downptr->down;
                        }
                        if(!isitthere)
                        {intersecting.erase(intersecting.begin()+j);}
                      
                    }
                   
                }
                ptr = ptr->next;
            }
        }
        
        for(unsigned int i= 0; foundwords.size()>i; i++)
        {
            cout << words[i] << " ";
        }
        cout << intersecting.size();
        
        for(unsigned int i= 0; intersecting.size()>i; i++)
        {
            cout << " " << intersecting[i] << " ";
        }
		cout << endl;
    }
}

vector<string> input(linkedlist<string> strings)
{
    
    string inputs, f;
    int numberofwords = 0;
    int breakcount = 0;
    vector<string> words;
    cout << "your node made it until here!" << endl;
    
    while (getline(cin, f))
    {
        istringstream gg(f);
        while (gg >> inputs)
        {
            if(inputs == "0")
            { cout << "the program was killed" << endl;
					system("pause");
						exit(0);
                breakcount++; break;
			}
            else if(numberofwords == 0)
            {
                numberofwords = stoi(inputs);
                vector<string> words;
            }
            else
            {
                words.push_back(inputs);
            }
            if(words.size() == numberofwords)
            {breakcount++;}
        }
       if (breakcount == 1)
       {break;}
    }
    
	return words;
}

int main()
{

	
	system("cls");
	system("title berk feyiz");			// just for estetics
	
	string read;
    string word;
    int count = 0;
    string number;
    ifstream inFile;
    inFile.open("docdb.txt");
    linkedlist<string> strings;
	vector<string> words;
    
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> read) {
        
        if (count == 0)//strings
        {
            
            word = read;
            count++;
        }
        else if (count == 1)//integers
        {
            
            number = read;
            count++;
        }
        if (count == 2)
        {
            
            strings.addToEnd(word);
            strings.addtoDown(word, number);
            
            count--;
            count--;
            
        }
        
    }
    
     words = input(strings);
	 intersect(words, strings.gethead());
    return 0;
}