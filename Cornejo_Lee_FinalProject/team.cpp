// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Team class implementation

#include <iostream>
#include <string>
#include "team.h"

using namespace std;

team::team()
{
    name = "";
    for(int i = 0; i < 5; i++){
        fullness[i] = 10;
    }
    for(int i = 0; i < 4; i++){
        members[i] = "";
    }
    for(int i = 0; i < 5; i++){
        weapons[i] = 0;
    }
    for(int i = 0; i < 100; i++){
        cookware[i] = 0;
    }
}

team::team(string newName, string newMembers[4], int newFullness[5])
{
    name = newName;
    for(int i = 0; i < 5; i++){
        newFullness[i] = 10;
    }
    for(int i = 0; i < 5; i++){
        fullness[i] = 10;
    }

    for (int i =0; i < 4; i++)
    {
        members[i] = newMembers[i];
    }
    coins = 100;
    roomNum = 1;
    key = false;
    ingredients = 0;
    for(int i = 0; i < 5; i++){
        weapons[i] = 0;
    }
    for(int i = 0; i < 100; i++){
        cookware[i] = 0;
    }
    armor = 0;

}
void team::setName(string newName)
{
    name = newName;
}
string team::getName()
{
    return name;
}
string team::getMembersAt(int index)
{
    return members[index];
}
        
void team::setFullness(int newFullness, int index)
{   

    fullness[index] = newFullness;
    if(fullness[index] < 0){
        fullness[index] = 0;
    }
    if(fullness[index] > 10){
        fullness[index] = 10;
    }
    
}
int team::getFullness(int index)
{
    return fullness[index];
}
        
int team::getIngredients()
{
    return ingredients;
}
void team::setIngredients(int newIngredients)
{
    ingredients = newIngredients;
    if(ingredients < 0){
        ingredients = 0;
    }
}

int team::getweapons(int index)
{
    return weapons[index];
}

void team::setWeapons(int newWeapons, int index)
{
    
    weapons[index] = newWeapons;
    
}
int team::getArmor()
{
    return armor;
}
void team::setArmor(int newArmor)
{
    armor = newArmor;
    if(armor < 0){
        armor = 0;
    }
}
int team::getCookware(int index)
{
    return cookware[index];
}
void team::setCookware(int newCookware, int index)
{
    cookware[index] = newCookware;
}
int team::getCoins()
{
    return coins;
}
void team::setCoins(int newCoins)
{
    coins = newCoins;
    if(coins < 0){
        coins = 0;
    }
}
bool team::getTeamLifeAt(int index)
{
    return teamLife[index];
}
void team::setTeamLifeAt(int index, bool value)
{
    teamLife[index] = value;
}

void team :: setroomNum(int room){
     if(room == 2){
         roomNum = 2;
     }
     else if(room == 3){
        roomNum = 3;
     }
     else if(room == 4){
         roomNum = 4;
     }
     else if(room == 5){
         roomNum = 5;
     }
 }

 int team :: getroomNum(){
     return roomNum;
 }

bool team :: getKey(){
    return key;
}

void team :: setKey(bool Key){
    key = Key;
}