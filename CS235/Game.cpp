/**
    CS-235 Assignment 1, Game.cpp

    @author Kaizen Castanos
    @version 1.0 10/31/2017
*/

#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

//------------Tractor Class Definitions-----------//
//Constructors
Tractor::Tractor(){
    x = y = 0;
    size = 1;
    activity = IDLE;
}
Tractor::Tractor(int x_, int y_, unsigned short size_, Activity activity_){
    x = x_;
    y = y_;
    size = size_;
    activity = activity_;
}
//Accessors
int Tractor::getX() const{
    return x;
}
int Tractor::getY() const{
    return y;
}
int Tractor::getSize() const{
    return size;
}
Activity Tractor::getActivity() const{
    return activity;
}
//Mutators
void Tractor::setX(int const x_){
    x = x_;
}
void Tractor::setY(int const y_){
    y = y_;
}
void Tractor::setSize(int const size_){
    size = size_;
}
void Tractor::setActivity(Activity const activity_){
    activity = activity_;
}

//------------Game Class Definitions-----------//
Game::Game(unsigned int new_size){
    map_size = new_size;
}
//Returns index of a tractor in "all" at the specified location, returns -1 if doesn't exist
int GetTractor(int x, int y){
    //loop through "all" 
    //return index in "all" of Tractor
    //else return -1
    return -1;
}



//------------Main Function-----------//
int main(){
    Tractor trac;
    Tractor trac2(1, 1, 2, MOVING);
    cout << trac.getX() << endl;
    cout << trac2.getSize() << endl;
    trac2.setSize(4);
    cout << trac2.getSize() << endl;
}
