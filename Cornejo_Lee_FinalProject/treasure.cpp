// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Treasure class implementation

#include <iostream>
#include <fstream>
#include "treasure.h"

using namespace std; 

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