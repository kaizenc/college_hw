/**
    CS-235 Assignment 1, Game.cpp
    Framework for RTS-style "Little Farm" game

    @author Kaizen Castanos
    @version 1.0 10/31/2017
**/

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
//----Constructor----//
Game::Game(unsigned int new_size){
    map_size = new_size;
}
//----Select Tractors----//
//Returns index of a tractor in "all" at the specified location, returns -1 if doesn't exist
int Game::GetTractor(int x, int y) const{
    for(int i = 0;i<all.size();i++){
        if(all[i].getX() == x and all[i].getY() == y){
            return i;
        }
    }
    return -1;
}
void Game::SelectTractor(int const x, int const y){
    int trac = GetTractor(x,y);
    if(trac != -1) selected.push_back(trac);
}
//----Change Tractors----//
//Adds tractor to all, check position?
void Game::AddTractor(Tractor new_unit){
    all.push_back(new_unit);
}



//------------Main Function-----------//
int main(){
    Tractor trac;
    Tractor trac2(1, 1, 2, MOVING);
    Tractor trac3(1, 2, 2, MOVING);
    Game game1(4);

    game1.AddTractor(trac);
    game1.AddTractor(trac2);
    game1.AddTractor(trac3);
    cout << game1.GetTractor(1, 1) << endl;
}
