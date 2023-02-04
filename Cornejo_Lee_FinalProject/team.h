// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Team class

#ifndef TEAM_H
#define TEAM_H
#include <string> 

using namespace std;

class team 
{
    private:
        int ingredients;
        int weapons[5];
        int armor;
        int roomNum;
        int cookware[100];
        int fullness[5]; 
        int coins;
        bool teamLife[4];
        string members[4];
        string name;
        bool key;
    
    public:

        team();
        team(string name, string members[4], int fullness[5]);
        
        void setName(string name);
        string getName();
        string getMembersAt(int index);
        
        void setFullness(int fullness,int index);
        int getFullness(int index);
        
        int getIngredients();
        void setIngredients(int ingredients);

        int getweapons(int index);
        void setWeapons(int weapons, int index);

        int getArmor();
        void setArmor(int weapons);

        int getCookware(int index);
        void setCookware(int cookware,int index);

        int getCoins();
        void setCoins(int newCoins);

        int getroomNum();
        void setroomNum(int room);

        bool getTeamLifeAt(int index);
        void setTeamLifeAt(int index, bool value);
        
        bool getKey();
        void setKey(bool Key);
};

#endif