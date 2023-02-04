// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Room class

#ifndef ROOM_H
#define ROOM_H
#include <string> 

using namespace std;

class room 
{
    private:
    int roomNum;
    string roomName;
    int anger ;
    
    public:
    room();
    room(int roomNum, string roomName, int anger);
    int getroomNum();
    string getroomName();
    int getwizardAnger();

    void setroomNum(int room);
    void setroomName(int name);
    void setwizardAnger(int newanger);
        
};

#endif

