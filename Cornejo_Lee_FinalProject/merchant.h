// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Merchant class

#define MERCHANT_H
#ifdef MERCHANT_H
#include <iostream>

using namespace std; 


class merchant{
    public:
        
        merchant();
        merchant(int storeNum);

        int getMerchantNum();

        void setMerchantNum(int index);

        double getIngredientPrice();

        double getWeaponPrice(int num);

        double getCookwarePrice(int num);

        int getArmorPrice();

    private:
        int merchantNum;
        double ingredientPrice;
        double weaponPrice[5] = {2,2,5,5,5};
        double cookwarePrice[3] = {20,10,5};
        double armorPrice;
};
#endif

