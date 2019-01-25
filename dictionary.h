#include "node.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


class dictionary
{
public:
    dictionary ()
    {
        rootNode = new node();  //root node is created and it is set to null
        rootNode->value = '\0';
    }

    void AddWord(std::string newWord)
    {
        
         tempPtr =  rootNode; //declares tempPtr and makes it assigned to root node which is equal to nullptr

        for(int i = 0; i < newWord.size(); i++) //starts a for loop which strats at 0 and ends at the end of the "newWord" entered (basically runs through the whole function)
        {
            bool foundChar = false; 
            while(tempPtr != nullptr) // declares a for loop that runs while tempPtr is not equal to nullPtr
            {
                if(tempPtr->value == newWord[i])  //IF CASE 1: If tempPtr.value is equal to the entered words current letter in the loop
                {
                    if(tempPtr->bottom == nullptr) // if tempPtr.bottom = nullPtr then ...
                    {
                        tempPtr->bottom = new node();   //  tempPtr.bottom is assigned to new node 
                        tempPtr->bottom->value = newWord[i + 1];  //  tempPtr.bottom.value is assigned to the letter after the current letter in "newWord"
                    }
                    tempPtr = tempPtr->bottom;    // tempPtr is assigned to tempPtr.bottom 
                    foundChar = true;   //the boolean variable 'foundchar' is now assigned to true 
                    break;        //while loop ended
                }

                if(tempPtr->next == nullptr)  //IF CASE 2: If tempPtr.next is equal to nullPtr
                     break; //while loop ended
                else
                     tempPtr = tempPtr->next; //IF CASE 3: tempPtr is assigned to tempPr.next
            }

            if(tempPtr->next == nullptr && foundChar == false) // if tempPtr.next is equal to [ nullPtr AND foundchar is equal to false ]
            {
                node* newNode = new node(); //newNode is assigned to a new created node 
                newNode->value = newWord[i]; //newNode.value is assigned to the current letter of newWord
                tempPtr->next = newNode; //tempPtr.next is assigned to newNode
                --i; //decrement i
            }
        }
    }

    void ReadTextfile()
    {
        std::ifstream in("english.txt");
        

        if(!in)
        {
             std::cout<< "Cannot open input file. \n" ;  
        }

        char str[2000];

        while(in)
        {
             in.getline(str, 2000);
             if(in)
             {
               AddWord(str);
               //std::cout << str << std::endl;
             } 
        }

        in.close();
 
    }

  /* void printDict()
    {
        node* tempPtr = rootNode;
        tempPtr = tempPtr->next;

        if (tempPtr == nullptr)
            return;

        while (tempPtr != nullptr)
        {
            std::cout << tempPtr->value << std::endl;
            tempPtr = tempPtr->bottom; 
        }
    } */

    bool FindWord(std::string Word)
    {
        node* current = rootNode;
        current = current->next;

        for(int i = 0; i < Word.size(); i++)
        {
            bool foundletter = false;

         
            while(current != nullptr)
            {  
                if (current->value == Word[i])
                {
                    current = current->bottom;
                   
                    break;
                }
                else 
                {
                    if (current->next == nullptr)
                    {
                        return false;
                    }
                    current = current->next;
                }
            }      
         
        }
        if(current->value == '\0')
            return true;

         int length = Word.length();
        
        if(current->value != Word[length])
        {
            return false;
        } 
    }

    node* rootNode;
    node* tempPtr;

};