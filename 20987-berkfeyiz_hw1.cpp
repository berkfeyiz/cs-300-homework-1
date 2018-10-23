#include <iostream>
#include <string>
#include <fstream>
#include "linkedList.h"

using namespace std;

void addtolist(string s ,int i){
cout << s << i << endl;

}

int main()
{
    string read;
    string word;
    int count = 0;
    int number = 0;
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
           
            number = stoi(read);
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
    strings.printList();
    return 0;
}
