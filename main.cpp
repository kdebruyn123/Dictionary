#include <iostream>
#include "dictionary.h"
#include <string>
#include <algorithm>

int main()
{
    std::string Word;
    dictionary d;
    d.ReadTextfile();
    
    while(true)
    {
        std::cout << "Please enter a word to see if it exsists in the dictionary: " << std::endl;
        std::cin >> Word;
        std::transform(Word.begin(), Word.end(), Word.begin(), ::tolower);

        if(Word == "exit")
            break;
        
        if(d.FindWord(Word) == true)
            std::cout << "Found word: " << Word << std::endl;
        else if(d.FindWord(Word) == false)
            std::cout << "We could not find the word: " << Word << std::endl;
    }
}
                                      