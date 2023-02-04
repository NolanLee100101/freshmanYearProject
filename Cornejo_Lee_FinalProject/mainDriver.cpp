// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Main function



#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "team.h"
#include "merchant.h"
#include "room.h"
#include "treasure.h"

void change(int a, int b)  //part of sorting function
{ 
    int count = a; 
    a = b; 
    b = count; 
} 

void MintoMaxSorting(int array[], int size)  //sorting function
{ 
 int index; 
   
    for (int i = 0; i < size-1; i++) {  
        index = i; 
        for (int j = i+1 ; j < size; j++) 
        if (array[j] < array[index]) 
            index = j; 
            change(array[index],  array[i]); 
 } 
} 



int randomNumberGenerator (int rand_min, int rand_max){
    srand(time(0));
    return rand() % rand_max + rand_min;
}


void menu(team Team, merchant Merchant, room Room){
int cauldron =0;
int cast_iron = 0;
int pot = 0;
int club = 0;
int spear = 0;
int crossbow = 0;
int axe = 0;
int longsword = 0;
for(int i = 0; i < 5; i++){
    if(Team.getweapons(i) == 1){
        club++;
    }
    else if(Team.getweapons(i) == 2){
        spear++;
    }
    else if(Team.getweapons(i) == 3){
        crossbow++;
    }
    else if(Team.getweapons(i) == 4){
        axe++;
    }
    else if(Team.getweapons(i) == 5){
        longsword++;
    }
    else{
        continue;
    }
}

for(int i = 0; i < 100; i++){
if(Team.getCookware(i) == 1){
    cauldron++;
}
else if(Team.getCookware(i) == 2){
    cast_iron++;
}
else if(Team.getCookware(i) == 3){
    pot++;
}
else{
    continue;
}
}
cout << "---Status Update---" << endl;
cout << "Current room: " << Room.getroomNum() << endl;
cout << "Current room name: " << Room.getroomName() << endl;
cout << "Room Key Found: " <<  boolalpha << Team.getKey() << endl;
cout << "Sorcerer Anger Level: " << Room.getwizardAnger() << " out of 100" << endl;
cout << "---------------------" << endl;
cout << "===Party Members===" << endl;
cout << Team.getName() << ": " <<  Team.getFullness(0) << " fullness points." << endl;
cout << Team.getMembersAt(0) << ": " <<  Team.getFullness(1) << " fullness points." << endl;
cout << Team.getMembersAt(1) << ": " <<  Team.getFullness(2) << " fullness points." << endl;
cout << Team.getMembersAt(2) << ": " <<  Team.getFullness(3) << " fullness points." << endl;
cout << Team.getMembersAt(3) << ": " <<  Team.getFullness(4) << " fullness points." << endl;
cout << "---------------------" << endl;
cout << "===Materials===" << endl;
cout << "Ingredients: " << Team.getIngredients() << endl;
cout << "Cookware: " << cauldron << " CAULDRON(S), " << cast_iron << " CAST IRON PAN(S), " << pot << " CERAMIC POT(S)" << endl;
cout << "Weapons: " << club << " CLUB(S), " << spear << " SPEAR(S), " << crossbow << " CROSSBOW(S), " << axe << " BATTLEAXE(S), " << longsword << " LONGSWORD(S)" << endl;
cout << "Armor: " << Team.getArmor() << " SET(S)" << endl;
cout << "Gold: " << Team.getCoins() << " COINS" << endl;
cout << "Treasure Items: " << endl;
}

team initialMerchant(team Team, merchant Merchent){
double ingredientsBill = 0.0;
double weaponsBill = 0.0;
double armorBill = 0.0;
double cookwareBill = 0.0;
int choice = 0;
double total;

while(choice != 5){
double totalBill = cookwareBill + armorBill + weaponsBill + ingredientsBill;
    cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
        cout << "         Merchant 1         " << endl;
        cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
        cout << "1. INGERDIENTS                        " << ingredientsBill << " coins" << endl;
        cout << "2. WEAPONS                            " << weaponsBill << " coins" << endl;
        cout << "3. ARMOR                              " << armorBill << " coins" << endl;
        cout << "4. COOKWARE                           " << cookwareBill << " coins" << endl;
        cout << "5. Exit and purchase" << endl;
        cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
        cout << "                      Total bill: " << totalBill << " coins" << endl;
        cout << endl;
        cout << "Amount you have: " << Team.getCoins() - totalBill << " coins" << endl;
        cout << endl;
        cout << "Which items would you like to purchase?" << endl;
        cin >> choice;


switch(choice){
case 1:
cout << "I recommend that each player should purchase at least 10 kg of ingredients per person, at 1 gold piece per kg of food" << endl;
cout << "How many kg of ingerdients do you wish to purchase" << endl;
int num;
cin >> num;
if(num >= 0 && (num <= Team.getCoins()) ){
ingredientsBill = num * Merchent.getIngredientPrice();
Team.setIngredients(num);
break;
}

else if(num > Team.getCoins()){
cout << "Don't have enough to purchase this many ingredients." << endl;
break;
}

else{
    cout <<  "Invalid input, enter a different amount" << endl;
    break;
}


case 2:
cout << "You need weapons to be able to fend off monsters, otherwise, you can only run!" << endl;
cout << "Equipping your team with the maximum number of weapons (1 weapon per person) and" << endl;
cout << "buying upgraded weapons that are worth 5 gold pieces will maximize your chances of" << endl;
cout << "survival during an attack. You can have a maximum of 5 weapons. These are the" << endl;
cout << "different types of weapons:" << endl;
cout << "1. A club costs 2 gold pieces" << endl;
cout << "2. A spear costs 2 gold pieces." << endl;
cout << "3. A crossbow costs 5 gold pieces" << endl;
cout << "4. A battle-axe costs 5 gold pieces." << endl;
cout << "5. A longsword costs 5 gold pieces." << endl;
cout << " " << endl;
cout << "Which weapons would you like to purchase" << endl;
int weapon;
for(int i = 0; i < 5; i++){
cout << "Player " << i + 1 << ": " << endl;
cin >> weapon;
weaponsBill += Merchent.getWeaponPrice(weapon);
Team.setWeapons(weapon, i);
}
break;



case 3:
cout << "A set of armor costs 5 gold coins. Armor protects you from monsters. Equipping your" << endl;
cout << "team with the maximum amount of armor (1 armor per person) will maximize your" << endl;
cout << "chances of survival during an attack. Adding more armor on top of the maximum" << endl;
cout << "amount will not increase your chances further." << endl;
cout << "" << endl;
cout << "How many armors would you like to purchase" << endl;
int number;
cin >> number;
if(number >= 0 && (number <= Team.getCoins()) ){
armorBill = number * Merchent.getArmorPrice();
Team.setArmor(number);
break;
}
else if((number * 5) > Team.getCoins()){
cout << "Don't have enough to purchase this much armor." << endl;
break;
}
else{
    cout <<  "Invalid input, enter a different amount" << endl;
    break;
}



case 4: 
cout << "A cauldron costs 20 gold pieces. You can use a cauldron to stew and boil ingredients. It is" << endl;
cout << "made of thick sturdy metal, so it only has a 2% chance of breaking each time you use it." << endl;
cout << "A cast iron pan costs 10 gold pieces. You can use a frying pan to sizzle ingredients. It is" << endl;
cout << "not as sturdy as a cauldron, with a 10% chance of breaking each time you use it." << endl;
cout << "A ceramic pot costs 5 gold pieces. You can use a ceramic pot to stew and boil" << endl;
cout << "ingredients. It is made from weaker material, so it has a 25% chance of breaking each" << endl;
cout << "time you use it." << endl;
cout << "" << endl;
cout << "Which cookware would you like to buy?" << endl;
cout << "1. Cauldron" << endl;
cout << "2. Iron Pan" << endl;
cout << "3. A ceramic pot" << endl;
cout << "4. Quit" << endl;
int numb;
while(numb != 4){
int i = 0;
cin >> numb;
if(numb == 1){
cookwareBill += Merchent.getCookwarePrice(1);
Team.setCookware(1, i);
i++;
}

else if(numb == 2){
cookwareBill += Merchent.getCookwarePrice(2);
Team.setCookware(2, i);
i++;
}

else if(numb == 3){
cookwareBill += Merchent.getCookwarePrice(3);
Team.setCookware(3, i);
i++;
}

else if(numb == 4){
cout << "Thanks for purchasing!" << endl;
}

else{
cout << "Inavlid input, try again" << endl;
}
}
break;


case 5:
Team.setCoins(Team.getCoins() - totalBill);
cout << "Thank you for purchasing!" << endl;
cout << "Your total bill is " <<  totalBill << "." << endl;
cout  << "Your remaining coins are " << Team.getCoins() << endl;
total = totalBill;
break;


default:
cout << "Invalid input. Enter a number on the menu." << endl;
break;

}
}

Team.setCoins(100 - total);
return Team;
}


team attackMonster(room Room, team Team)
{
    int weapon1 = Team.getweapons(0);
    int weapon2 = Team.getweapons(1);
    int weapon3 = Team.getweapons(2);
    int weapon4 = Team.getweapons(3);
    int weapon5 = Team.getweapons(4);
    int w = 0;
    int d;
    int a;
    int c;
    int r1;
    int r2;
    int outcome;
    int chance;
    int keyChance;
    int bonusPoints = 0;
    

    if(weapon1 == 1 || weapon1 == 2)
    {
        w++;
    }
    else if(weapon1 == 3 || weapon1 == 4 || weapon1 == 5)
    {
        bonusPoints++;
        w++;
    }
    if(weapon2 == 1 || weapon2 == 2)
    {
        w++;
    }
    else if(weapon2 == 3 || weapon2 == 4 || weapon2 == 5)
    {
        bonusPoints++;
        w++;
    }
    if(weapon3 == 1 || weapon3 == 2)
    {
        w++;
    }
    else if(weapon3 == 3 || weapon3 == 4 || weapon3 == 5)
    {
        bonusPoints++;
        w++;
    }
    if(weapon4 == 1 || weapon4 == 2)
    {
        w++;
    }
    else if(weapon4 == 3 || weapon4 == 4 || weapon4 == 5)
    {
        bonusPoints++;
        w++;
    }
    if(weapon5 == 1 || weapon5 == 2)
    {
        w++;
    }
    else if(weapon5 == 3 || weapon5 == 4 || weapon5 == 5)
    {
        bonusPoints++;
        w++;
    }

    w = w + bonusPoints;

    if(weapon1 == weapon2 || weapon1 == weapon3 || weapon1 == weapon4 || weapon1 == weapon5)
    {
        d = 0;
    }
    else
    {
        d = 1;
    }

    a = Team.getArmor();
    c = Room.getroomNum();
    r1 = randomNumberGenerator(1,6);
    r2 = randomNumberGenerator(1,6);

    if(a == 0){
        a =1;
    }

    if(a == 0 && w == 0)
    {
        cout << "You cannot attack because you do not have at least one set of armor or 1 weapon." << endl;
    }
    else
    {
        outcome = (r1 * w + d) - ( r2 * c * (1/a));

        if(outcome > 0)
        {
            cout << "You have defeted the monster, 50 gold pieces and 20 kg of food will be added to your inventory! Be cautious the monster might have dropped a key!" << endl;
            Team.setCoins(Team.getCoins() + 50);
            Team.setIngredients(Team.getIngredients() + 20);
            keyChance = randomNumberGenerator(0,100);
            if(keyChance >= 0 && keyChance <=33)
            {
                Team.setKey(true);
                cout << "The monster dropped a key!" << endl;
            }
            

        }
        else if(outcome <= 0)
        {
            cout << "You have been defeated by the monster, you lose a quarter of your gold reserves and 30 kg of food... be careful someone might die :(" << endl;
            Team.setCoins(Team.getCoins() - (Team.getCoins() * .25));
            Team.setIngredients(Team.getIngredients() - 30);
        
            for(int i = 0; i < 5; i++)
            {
                chance = randomNumberGenerator(0,100);
                if(chance >= 0 && chance <= 10)
                {
                        Team.setTeamLifeAt(i , false);
                        if(i == 0)
                        {
                            cout << "The team member " << Team.getName() << " has been slain :(" << endl;
                        }
                        else
                        {
                            cout << "The team member " << Team.getMembersAt(i) << " has been slain :(" << endl;
                        }

                }
            }
        }
    }
    return Team;
}

team exploreRoom(team Team, merchant Merchant, room Room, treasure Treasure,  string file){
int chance = randomNumberGenerator(0,100);
if(chance >= 0 && chance < 20){
    Team.setKey(true);
    cout << "You have found the key!" << endl;
}

else if(chance >= 20 && chance < 40){
int room = Room.getroomNum();
cout << "Congrats you have managed to find a(n) " << Treasure.getTreasure(file, room) << "!" << endl;
}

else if(chance >= 40 && chance < 60){
attackMonster(Room, Team);
}
else{
    cout << "You have not found anything bum(IS YOU BLIND!)" << endl;
}

for(int i =0; i < 5; i++){
Team.setFullness(Team.getFullness(i) - 1, i);
}
return Team;
}

team replenish(merchant Merchant, team Team, room Room){
cout << "If you have ingredients then you can cook, and replenish your team" << endl;
cout << "You may choose which cookware you would like to use" << endl;
cout << "Be aware a cauldron is the least likely to break, while a ceramic pot is the most likely." << endl;
int count = 0;
int ingredients = Team.getIngredients();
for(int i = 0; i < 100; i++){
    if(Team.getCookware(i) != 0){
        count++;
    }
    {
    }

}

if(count == 0 || ingredients == 0){
    cout << "You dont have any cookware and/or ingredients to cook ingredients unfortunately" << endl;
}
else{
cout << "How many of your ingredients woould you like to use, knowing that every 5 ingredients increases your cookware by 1, so only choose in 5s." << endl;
cout << "You have " << Team.getIngredients() << " ingredients" << endl;
int chosen_ingredients;
int choice2;
cin >> choice2;
chosen_ingredients = choice2;

cout << "You have:" << endl;
for(int i = 0; i < 100; i++){
if(Team.getCookware(i) == 1){
    cout << "Cauldron" << endl;
}
else if(Team.getCookware(i) == 2){
    cout << "Cast iron pot" << endl;
}
else if(Team.getCookware(i) == 3){
    cout << "Ceramic pot" << endl;
}
}

cout << "Please select the cookware you wish to serve" << endl;
cout << "1. Cauldron" << endl;
cout << "2. Cast iron pot" << endl;
cout << "3. Ceramic pot" << endl;

int choice;
bool working = true;
cin >> choice;
int chance = randomNumberGenerator(0,100);
if(choice == 1){
if(chance >= 0 && chance <=2){
    working = false;
    Team.setIngredients(Team.getIngredients() - chosen_ingredients);
    for(int i = 0; i < 5; i++){
        Team.setFullness(Team.getFullness(i)- 1, i);
    }
    for(int i = 0; i < count; i++){
        if(Team.getCookware(i) == 1){
            Team.setCookware(0, i);
        }
    }
}
}
else if(choice == 2){
    if(chance >= 0 && chance <= 10){
        working = false;
        Team.setIngredients(Team.getIngredients() - chosen_ingredients);
    for(int i = 0; i < 5; i++){
        Team.setFullness(Team.getFullness(i)- 1, i);
    }
    for(int i = 0; i < count; i++){
        if(Team.getCookware(i) == 2){
            Team.setCookware(0, i);
        }
    }
    }
}
else if(choice == 3){
    if(chance >= 0 && chance <= 25){
        working = false;
        Team.setIngredients(Team.getIngredients() - chosen_ingredients);
    for(int i = 0; i < 5; i++){
        Team.setFullness(Team.getFullness(i)- 1, i);
    }
    for(int i = 0; i < count; i++){
        if(Team.getCookware(i) == 3){
            Team.setCookware(0, i);
        }
    }
    }
    return Team;
}

if(working == true){
int fullness = chosen_ingredients/5;
for(int i = 0; i < 5;i++){
Team.setFullness(Team.getFullness(i) + fullness, i);
Team.setIngredients(Team.getIngredients() - chosen_ingredients);
}
cout << "You have succesfully cooked your ingredients! Good Luck!"<< endl;
}
else{
    cout << "Your cookware has broke, sucks for you fam." << endl;
}
}
return Team;
}

team misfortune(team Team)
{
    if(randomNumberGenerator(1,100) <= 40)
    {
        int choice = randomNumberGenerator(1,3);

        if(choice == 1)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits!";
            int robbed = randomNumberGenerator(1,3);
            if(robbed == 1)
            {
                Team.setIngredients(0);
                cout << " You have no food left!" << endl;
            }
            else if(robbed == 2)
            {   
                for(int i = 0; i < 100; i++)
                {
                    Team.setCookware(0, i);
                    cout << " You have no cookware left!" << endl;
                }
            }
            else if(robbed == 3)
            {
                Team.setArmor(0);
                cout << " You have no armor left!" << endl;;
            }
        }
        else if(choice == 2)
        {
            cout << "OH NO! One of your ";
            int mfb = randomNumberGenerator(1,2);
            if(mfb == 1)
            {
                int randomWeapon = randomNumberGenerator(0,4);
                Team.setWeapons(0, randomWeapon);
                cout << "weapons broke" << endl;
            }
            if(mfb == 2)
            {
                Team.setArmor(Team.getArmor() -1);
                cout << "armor broke" << endl;
            }
        }
        else if(choice == 3 && Team.getKey() == true)
        {
            int randomTeamMember = randomNumberGenerator(1,4);
            Team.setFullness(0, randomTeamMember);
            cout << "OH NO! Your teammate " << Team.getMembersAt(randomTeamMember) << "is trapped in the previous room, and is unable to get through." << endl;
            cout << "You must continue without him." << endl;
        }

    }
    else
    {
        cout << "You got lucky and no misfortunes have occurred!" << endl;
    }
    return Team;
}

    

 
 
team misfortuneDoor(team Team)
{
    if(randomNumberGenerator(1,100) <= 40)
    {
        int choice = randomNumberGenerator(1,3);

        if(choice == 1)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits!";
            int robbed = randomNumberGenerator(1,3);
            if(robbed == 1)
            {
                Team.setIngredients(0);
                cout << " You have no food left!" << endl;
            }
            else if(robbed == 2)
            {   
                for(int i = 0; i < 100; i++)
                {
                    Team.setCookware(0, i);
                    cout << " You have no cookware left!" << endl;
                }
            }
            else if(robbed == 3)
            {
                Team.setArmor(0);
                cout << " You have no armor left!" << endl;;
            }
            Team.setKey(false);
            
        }
        else if(choice == 2)
        {
            cout << "OH NO! One of your ";
            int mfb = randomNumberGenerator(1,2);
            if(mfb == 1)
            {
                int randomWeapon = randomNumberGenerator(0,4);
                Team.setWeapons(0, randomWeapon);
                cout << "weapons broke" << endl;
            }
            if(mfb == 2)
            {
                Team.setArmor(Team.getArmor() -1);
                cout << "armor broke" << endl;
            }
            Team.setKey(false);
        }
        else if(choice == 3 && Team.getKey() == true)
        {
            int randomTeamMember = randomNumberGenerator(1,4);
            Team.setFullness(0, randomTeamMember);
            cout << "OH NO! Your teammate " << Team.getMembersAt(randomTeamMember) << "is trapped in the previous room, and is unable to get through." << endl;
            cout << "You must continue without him." << endl;
            Team.setKey(true);
        }
    }
    else
    {
        cout << "You got lucky and no misfortunes have occurred!" << endl;
        Team.setKey(true);
    }
    return Team;
}


bool doorPuzzle(team Team)
{
    int userChoice;
    int doorChoice;
    int attempts = 0;
    while(attempts != 3){
        cout << "Choose rock, paper, or scissors" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cin >> userChoice;
        doorChoice = randomNumberGenerator(1,3);
        if(userChoice == 1 && doorChoice == 3)
        {
            cout << "You have beat the puzzle you may move on" << endl;
            return true;
        }
        else if(userChoice == 1 && doorChoice == 2)
        {
            cout << "You have lost please try again" << endl;
            attempts++;
            cin.clear();
            cin.ignore();
        }
        else if(userChoice == 2 && doorChoice == 1)
        {
            cout << "You have beat the puzzle you may move on" << endl;
            return true;
        }
        else if(userChoice == 2 && doorChoice == 3)
        {
            cout << "You have lost please try again" << endl;
            attempts++;
            cin.clear();
            cin.ignore();
        }
        else if(userChoice == 3 && doorChoice == 2)
        {
            cout << "You have beat the puzzle you may go to the next room" << endl;
            return true;
        }
        else if(userChoice == 3 && doorChoice == 1)
        {
            cout << "You have lost please try again" << endl;
            attempts++;
            cin.clear();
            cin.ignore();
        }
        else if(userChoice == doorChoice)
        {
            cout << "You have tied, try again" << endl;
            attempts++; 
        }
        if(attempts >= 3)
        {
            cout << "You have reached the maximum number of attempts without winning, one of your teammates has died" << endl;
            int randomTeamMember = randomNumberGenerator(1,4);
            Team.setFullness(0, randomTeamMember);
            cout << Team.getMembersAt(randomTeamMember) << " has died :(" << endl;
        }
    }
    return false;
}

team openDoor(team Team){
if(Team.getKey() == true){
    Team = misfortuneDoor(Team);
   if(Team.getKey() == true){
       return Team;
   }
   else{
       doorPuzzle(Team);
       Team.setKey(false);
       return Team;
   }
}

else{
    if(doorPuzzle(Team) == true){
        Team.setKey(true);
        return Team;
    }
    else{
        cout << "Don't open the door if you don't have a key!!" << endl;
    return Team;
    }
}
return Team;
}

team SpeakToNPC(team Team, room Room, merchant Merchant)
{
    int chance = randomNumberGenerator(1,100);
    int i = 0;
    if(chance >= 1 || chance < 33)
    {
        if(doorPuzzle(Team) == true)
        {
            cout << "The NPC was good and is willing to sell you items!" << endl;
            cout << "" << endl;
            Team = initialMerchant(Team, Merchant);
        }
        else
        {
            cout << "You failed the puzzle and the NPC will not sell to you." << endl;
        }
    }
    else if(chance >= 33 || chance < 66)
    {
        doorPuzzle(Team);
        cout << "This NPC was neutral so no matter the outcome of the puzzle nothing happens." << endl;
    }
    else if(chance >=66 || chance < 100)
    {
        cout << "The NPC is evil and you now have to fight a monster!" << endl;
        attackMonster(Room, Team);
    }
    return Team;
}



int main(){
    cout << "Enter your name" << endl;
    string leaderName;
    getline(cin, leaderName);
    int fullness[5];
    for(int i = 0; i < 5; i++){
        fullness[i] = 10;
 }

    cout << "Enter the names of your traveling companions" << endl;
    string teamMemberNames[4];
    cout << "1.";
    getline(cin, teamMemberNames[0]);
    cout << "2.";
    getline(cin, teamMemberNames[1]);
    cout << "3.";
    getline(cin, teamMemberNames[2]);
    cout << "4.";
    getline(cin, teamMemberNames[3]);

    team Team = team(leaderName, teamMemberNames, fullness);
    merchant Merchant = merchant();
    room Room = room();
    treasure Treasure = treasure();

    cout << "Between the 5 of you, you have 100 gold coins and 5" << endl;
    cout << "weapons. You will need to spend the rest of your money on" << endl;
    cout << "the following items:"  << endl;

    cout << "INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "COOKWARE. If you want to cook, you have to have cookware first" << endl;
    cout << "WEAPONS. You’ll want at least one weapon per party member to fend off monsters." << endl;
    cout << "ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    
    cout << "You can spend all of your money here before you start your journey, or you" << endl;
    cout << "can save some to spend on merchants along the way. But beware, some of the" << endl;
    cout << "merchants in this dungeon are shady characters, and they won’t always give you a fair price..."  << endl;
    cout << "Would you like to visit the first merchant to buy the objects above?" << endl;
    cout << "Enter Y or N" << endl;
    string choice;
    getline(cin, choice);
    if(choice == "Y" || choice == "y"){
        initialMerchant(Team , Merchant);
        Team = initialMerchant(Team , Merchant);
    }
    else if(choice == "N" || choice == "n"){
        cout << "You can visit merchants in the rest of the rooms, but be aware the prices get larger down the road." << endl;
    }
int total_life;
int choice2 = 0;
int turn = 0;
while(choice2 != 6){
if(Room.getwizardAnger() == 100){
    cout << "You died to the WIZARD" << endl;
    ofstream myfile;
myfile.open("results.txt");
if(myfile.is_open()){
    for(int i = 0; i < 5; i++){
        myfile << Team.getMembersAt(i) << " had a fullness of " << Team.getFullness(i) << endl;
        myfile << Treasure.getTreasure("rooms.txt", i);
    }
}
int arr[5];
for(int i = 0; i < 5; i ++){
    arr[i] = Team.getFullness(i);
}
MintoMaxSorting(arr, 5);
  
    for (int i=0; i < 5; i++) {
        cout << Team.getMembersAt(i) << ": "  << arr[i] << " fullness " << endl;
    }
    return 0;
}

if(Room.getroomNum() == 6){
    cout << "Thanks for playing, you have beaten the dungeon!" << endl;
    ofstream myfile;
myfile.open("results.txt");
if(myfile.is_open()){
    for(int i = 0; i < 5; i++){
        myfile << Team.getMembersAt(i) << " had a fullness of " << Team.getFullness(i) << endl;
        myfile << Treasure.getTreasure("rooms.txt", i);
    }
}
int arr[5];
for(int i = 0; i < 5; i ++){
    arr[i] = Team.getFullness(i);
}
MintoMaxSorting(arr, 5);
  
    for (int i=0; i < 5; i++) {
        cout << Team.getMembersAt(i) << ": "  << arr[i] << " fullness " << endl;
    }
    return 0;
}

if(Team.getFullness(0) == 0 && Team.getFullness(1) == 0 && Team.getFullness(2) == 0 && Team.getFullness(3) == 0 && Team.getFullness(4) == 0){
    cout << "OH NO, YOUR WHOLE TEAM HAS DIED" << endl;
    ofstream myfile;
myfile.open("results.txt");
if(myfile.is_open()){
    for(int i = 0; i < 5; i++){
        myfile << Team.getMembersAt(i) << " had a fullness of " << Team.getFullness(i) << endl;
        myfile << Treasure.getTreasure("rooms.txt", i) << endl;
    }
}
int arr[5];
for(int i = 0; i < 5; i ++){
    arr[i] = Team.getFullness(i);
}
MintoMaxSorting(arr, 5);
  
    for (int i=0; i < 5; i++) {
        cout << Team.getMembersAt(i) << ": "  << arr[i] << " fullness " << endl;
    }
    return 0;
 }

menu(Team, Merchant, Room);
cout << "" << endl;
cout << "--------------------------------------------" << endl;
cout << "" << endl;
cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
cout << "          Room Options                      " << endl;
cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
cout << "1. Fight a monster                          " << endl;
cout << "2. Speak to NPC                             " << endl;
cout << "3. Cook and eat                             " << endl;
cout << "4. Explore the room                         " << endl;
cout << "5. Open the door                            " << endl;
cout << "6. Quit                                      " << endl;
cout << "=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^=^==^=^=^=^=^=" << endl;
cin >> choice2;

switch (choice2){

case 1:
for(int i = 0; i < 5;i++){
    Team.setFullness(Team.getFullness(i) - 1, i);
}
Room.setwizardAnger(Room.getwizardAnger() + 2);
cout << "" << endl;
cout << "" << endl;
Team = attackMonster(Room, Team);
Team = misfortune(Team);
cout << "" << endl;
cout << "" << endl;
break;

case 2:
for(int i = 0; i < 5;i++){
    Team.setFullness(Team.getFullness(i) - 1, i);
}
Room.setwizardAnger(Room.getwizardAnger() + 2);
cout << " " << endl;
Team = SpeakToNPC(Team, Room, Merchant);
misfortune(Team);
Team = misfortune(Team);
break;

case 3:
for(int i = 0; i < 5;i++){
    Team.setFullness(Team.getFullness(i) - 1, i);
}
Room.setwizardAnger(Room.getwizardAnger() + 2);
cout << "" << endl;
cout << "" << endl;
Team = replenish(Merchant, Team, Room);
Team = misfortune(Team);
cout << "" << endl;
cout << "" << endl;
break;

case 4:
for(int i = 0; i < 5;i++){
    Team.setFullness(Team.getFullness(i) - 1, i);
}
Room.setwizardAnger(Room.getwizardAnger() + 2);
cout << "" << endl;
cout << "" << endl;
Team = exploreRoom(Team, Merchant, Room, Treasure, "rooms.txt");
Team = misfortune(Team);
cout << "" << endl;
cout << "" << endl;
break;

case 5:
for(int i = 0; i < 5;i++){
    Team.setFullness(Team.getFullness(i) - 1, i);
}
Room.setwizardAnger(Room.getwizardAnger() + 2);
Team = openDoor(Team);
if(Team.getKey() == true){
Room.setroomNum(Room.getroomNum() + 1);
Room.setroomName(Room.getroomNum());
Team.setKey(false);
}
else{
    Team.setKey(true);
}
break;

case 6:
cout << "Thanks for playing better luck next time!" << endl;
break;

default:
cout << "" << endl;
cout << "" << endl;
cout << "Invalid input, try again please." << endl;
cout << "" << endl;
cout << "" << endl;
break;
}
}
return 0;
}

