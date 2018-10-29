#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "linkedList.h"

using namespace std;

void scan(vector<string>& words, linkedlist strings)
{
    strnode *ptr = strings.gethead();
    vector<string> foundwords;
    
    for(unsigned int i= 0; words.size()>i; i++)
    {
        ptr = strings.gethead();
        while (ptr != NULL)
        {
            if (words[i] == ptr->data)
            {
                foundwords.push_back(words[i]);
            }
            ptr = ptr->next;
        }
    }
    
    ptr = strings.gethead();
    
    strnode *downptr = nullptr;
    strnode *downptrforcomp = nullptr;
    
    vector <int> intersecting;
    int count = 0;
    if(foundwords.size() == 0)
    {
      
        for(unsigned int i= 0; foundwords.size()>i; i++)
        {
            cout << words[i] << " ";
        }
          cout << "0 ";
        cout << endl;
    }
    else if(foundwords.size() == 1)
    {
        ptr = strings.gethead();
        while(ptr != NULL)
        {
            if(foundwords[0] == ptr->data)
            {
                downptr = ptr->down;
                cout << foundwords[0];
                
                *downptr = *ptr;
                while(downptr != NULL)
                {
                    downptr = downptr ->down;
                    count ++;
                }
                cout << count;
                *downptr = *ptr;
                while(downptr != NULL)
                {
                    downptr = downptr ->down;
                    cout << downptr->data;
                }
            }
            ptr = ptr->next;
        }
    }
    else if(foundwords.size() == 2)
    {
        for(unsigned int i= 0; 2>i; i++)
        {
            ptr = strings.gethead();
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
    }
    if(foundwords.size() >2)
    {
        for(unsigned int i= 0; 2>i; i++)
        {
            ptr = strings.gethead();
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
           ptr = strings.gethead();
            while (ptr != NULL)
            {
                if (foundwords[i] == ptr->data)
                {
                    downptr = ptr->down;
                    for(unsigned int j = 0; intersecting.size() >j; j++)
                    {
                       
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
    }
}

void input(linkedlist strings)
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
                breakcount++; break;}
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
    
    scan(words, strings);
    
}

int main()
{
    string read;
    string word;
    int count = 0;
    string number;
    ifstream inFile;
    inFile.open("docdb.txt");
    linkedlist strings;
    
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
    
    input(strings);
    return 0;
}
