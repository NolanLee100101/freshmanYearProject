// CSCI1300 Spring 2021
// Author: Diego Cornejo and Nolan Lee
// Project 3 - Room class implementation

#include "room.h"

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