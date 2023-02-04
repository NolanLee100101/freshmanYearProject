// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Code Skeleton

#include "team.h"
#include "treasure.h"
#include "room.h"
#include "merchant.h"

int split(string arr, char sep, string array[], int size){ 
int length = arr.length();
int i =0 ;                              
string word = "";
int position = 0;

while(i != length && position != size){     
    if(arr[i] == sep){   
        array[position] = word;     
        position ++;                
        word = "";
    }
    else{
        word += arr[i];    
    }
    if(i == length -1){
        if(word != ""){                 
            array[position] = word;     
            position ++;               
            word = "";
        }

    }
    i++;
}
if(i != length && position == size){       
    return -1;
}
else{
    return position; 
}
}

treasure :: treasure(){
file = "";
}

treasure :: treasure(string File){
file = File;
}

string treasure :: getTreasure(string File, int room){

ifstream file;
file.open(File);
string line;
string temp;
string treasure;
string arr[50];
int check =0;
if(file.is_open()){
while(getline(file,line)){
for(int i = 0; i < line.length(); i++){
    if(line[i] == ','){
    check++;
    split(line, ',', arr, 3);
    temp = arr[0];
     }
}
if(check == room){
treasure = temp;
     }
}
}

else{
    return "couldn't open file";
}
return treasure;
}

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

room :: room(){
roomNum = 1;
roomName = "Red room";
anger = 0;

}

room :: room(int newroomNum, string newroomName, int newanger){
roomNum = newroomNum;
roomName = newroomName;
anger = newanger;
}

 int room :: getroomNum(){
     return roomNum;
 }

 string room :: getroomName(){
     return roomName;
 }

 int room :: getwizardAnger(){
     return anger;
 }

 void room :: setroomNum(int room){
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

 void room :: setroomName(int name){
     if(name == 1){
        roomName = "Red room";
     }
     else if(name == 2){
         roomName = "Blue room";
     }
     else if(name == 3){
         roomName = "Green room";
     }
     else if(name == 4){
         roomName = "Yellow room";
     }
     else if(name == 5){
         roomName = "Final room";
     }
 }

 void room :: setwizardAnger(int newanger){
     anger = newanger;
 }

merchant::merchant()
{

        merchantNum = 0;
        ingredientPrice = 1;
        weaponPrice[0] = 2;
        weaponPrice[1] = 2;
        weaponPrice[2] = 5;
        weaponPrice[3] = 5;
        weaponPrice[4] = 5;
        cookwarePrice[0] = 20;
        cookwarePrice[1] = 10;
        cookwarePrice[2] = 5;
        armorPrice = 5;

}

merchant::merchant(int newMerchantNum){

    merchantNum = newMerchantNum;

    merchantNum = 0;
    ingredientPrice = 1;
    weaponPrice[0] = 2;
    weaponPrice[1] = 2;
    weaponPrice[2] = 5;
    weaponPrice[3] = 5;
    weaponPrice[4] = 5;
    cookwarePrice[0] = 20;
    cookwarePrice[1] = 10;
    cookwarePrice[2] = 5;
    armorPrice = 5;
}

int merchant::getMerchantNum(){

    return merchantNum;
}

double merchant::getIngredientPrice(){

    return ingredientPrice * (1 + (0.25 * merchantNum));
}

double merchant::getWeaponPrice(int num)
{
    if(num == 1)
    {
        double price1;
        price1 = weaponPrice[0];
        return price1 * (1 + (0.25 * merchantNum));
    }
    else if(num == 2)
    {
        double price2;
        price2 = weaponPrice[1];
        return price2 * (1 + (0.25 * merchantNum));
    }
    else if(num == 3)
    {
        double price3;
        price3 = weaponPrice[2];
        return price3 * (1 + (0.25 * merchantNum));
    }
    else if(num == 4)
    {
        double price4;
        price4 = weaponPrice[3];
        return price4 * (1 + (0.25 * merchantNum));
    }
    else if(num == 5)
    {
        double price5;
        price5 =weaponPrice[4];
        return price5 * (1 + (0.25 * merchantNum));
    }
    else 
    {
        return -1;
    }
}

double merchant::getCookwarePrice(int num)
{
    if(num == 1)
    {
        return cookwarePrice[0] * (1 + (0.25 * merchantNum));
    }
    else if(num == 2)
    {
        return cookwarePrice[1] * (1 + (0.25 * merchantNum));
    }
    else if(num == 3)
    {
        return cookwarePrice[2] * (1 + (0.25 * merchantNum));
    }
    else
    {
        return -1; 
    }
}

int merchant::getArmorPrice()
{

    return armorPrice * (1 + (0.25 * merchantNum));
}


void merchant::setMerchantNum(int index){
    merchantNum = index;
}

