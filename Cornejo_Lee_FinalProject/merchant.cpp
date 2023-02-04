// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Merchant class implementation

#include <iostream>
#include <iomanip>
#include <string>
#include "merchant.h"

using namespace std;

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
