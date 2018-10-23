#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "linkedList.h"

using namespace std;

void scan(vector<string>& words, linkedlist strings)
{
    linkedlist *ptr = &strings;
    
    
    for(unsigned int i= 0; words.size()>i; i++)
    {
        while(ptr !=NULL)
        {
       
    
           // ptr = ptr->next;
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
                { cout << "the program was killed" << endl; breakcount++; break;}
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
