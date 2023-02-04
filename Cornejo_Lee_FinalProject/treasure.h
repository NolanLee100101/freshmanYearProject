// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Treasure class 

#define TREASURE_H
#ifdef TREASURE_H
#include <iostream>
#include <fstream>

using namespace std; 


class treasure{
    public:
    treasure();
    treasure(string File);
    string getTreasure(string File, int room);

    private:
    string file;

};
#endif

