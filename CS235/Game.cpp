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
Tractor::Tractor(int const &x_, int const &y_, unsigned short const &size_, Activity const &activity_){
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
void Tractor::setX(int const &x_){
    x = x_;
}
void Tractor::setY(int const &y_){
    y = y_;
}
void Tractor::setSize(int const &size_){
    size = size_;
}
void Tractor::setActivity(Activity const &activity_){
    activity = activity_;
}

//------------Game Class Definitions-----------//
//----Constructor----//
Game::Game(unsigned int const &new_size){
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
//Puts the index of the Tractor at the given coordinates into the selected vector
void Game::SelectTractor(int const &x, int const &y){
    selected.clear();
    int trac = GetTractor(x,y);
    if(trac != -1) selected.push_back(trac);
}
//Puts the index of the Tractors within the given coordinates into the selected vector
void Game::SelectTractors(int const &x1, int const &y1, int const &x2, int const &y2){
    selected.clear();
    int x_1 = x1;
    int y_1 = y1;
    int x_2 = x2;
    int y_2 = y2;
    if (x2 < x1){
        x_2 = x1;
        x_1 = x2;
    }
    if(y2 < y1){
        y_2 = y1;
        y_1 = y2;
    }
    
    for(int i = x_1;i < x_2;i++){
        for(int j = y_1;j<y_2;j++){
            int trac = GetTractor(i,j);
            if(trac != -1) selected.push_back(trac);
        }
    }
    /*
    for(Tractor item = all.begin(); item != all.end(); item++){
        if(true){//check if tractor is in range
            selected.push_back(trac);
        }
    }
    */
}
//----Change Tractors----//
//Adds tractor to the all vector
void Game::AddTractor(Tractor new_unit){
    all.push_back(new_unit);
}
//Move i to coordinates if possible, returns true if successful, false otherwise
bool Game::MoveTractor(int i, int new_x, int new_y){
    return true;
}
//Assigns Activity to selected tractors
void Game::AssignTractorsActivity(Activity &new_activity){
    int i = 0;
    for(vector<int>::iterator item = selected.begin();item != selected.end(); item++){
        all[*item].setActivity(new_activity);
        i++;
    }
}
//----Print Tractors----//
void Game::PrintTractor(int const &i){
    Tractor & trac = all[i];
    cout << "Coords: (" << trac.getX() << ", " << trac.getY() << ") | ";
    cout << "Size: " << trac.getSize() << " | ";
    cout << "Activity: " << trac.getActivity() << endl;
}
void Game::PrintSelectedTractors(){
    for(vector<int>::iterator item = selected.begin();item != selected.end(); item++){
        PrintTractor(*item);
    }
}
void Game::PrintAllTractors(){
    int i = 0;
    for(vector<Tractor>::iterator item = all.begin();item != all.end(); item++){
        PrintTractor(i);
        i++;
    }
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
    cout << game1.GetTractor(1, 2) << endl;
    game1.PrintTractor(2);
    game1.PrintAllTractors();
}
