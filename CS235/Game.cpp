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
        if(all[i].getX() + all[i].getSize() >= x and all[i].getX() - all[i].getSize() <= x and 
           all[i].getY() + all[i].getSize() >= y and all[i].getY() - all[i].getSize() <= y){
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
    
    for(int i = 0;i<all.size();i++){
        Tractor & trac = all[i];
        if(x_1 < trac.getX() + trac.getSize() &&
           x_2 > trac.getX() - trac.getSize() &&
           y_2 > trac.getY() - trac.getSize() &&
           y_1 < trac.getY() + trac.getSize()){
               selected.push_back(i);
        }
    }
}
//----Change Tractors----//
//Adds tractor to the all vector
void Game::AddTractor(Tractor const &new_unit){
    all.push_back(new_unit);
}
//Move i to coordinates if possible, returns true if successful, false otherwise
bool Game::MoveTractor(int i, int new_x, int new_y){
    Tractor & trac1 = all[i];
    for(int j = 0;j<all.size();j++){
        if (j == i) continue;
        Tractor & trac2 = all[j];
        if(new_x - trac1.getSize() < trac2.getX() + trac2.getSize() &&
           new_x + trac1.getSize() > trac2.getX() - trac2.getSize() &&
           new_y + trac1.getSize() > trac2.getY() - trac2.getSize() &&
           new_y - trac1.getSize() < trac2.getY() + trac2.getSize()){
               return false;
        }
    }
    trac1.setX(new_x);
    trac1.setY(new_y);
    return true;
}
//Assigns Activity to selected tractors
void Game::AssignTractorsActivity(Activity new_activity){
    int i = 0;
    for(int i = 0;i<selected.size();i++){
        all[selected[i]].setActivity(new_activity);
    }
}
//----Print Tractors----//
void Game::PrintTractor(int const &i){
    Tractor & trac = all[i];
    cout << "Index: " << i << " | ";
    cout << "Coords: (" << trac.getX() << ", " << trac.getY() << ") | ";
    cout << "Size: " << trac.getSize() << " | ";

    cout << "Activity: ";
    switch(trac.getActivity()){
        case 0: cout << "SEEDING";
        case 1: cout << "HARVESTING";
        case 2: cout << "MOVING";
        case 3: cout << "IDLE";
    }
    cout << endl;
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
    Game g(100);
    Tractor trt1(10,10,4,IDLE);
    Tractor trt2(50,50,4,IDLE);
    Tractor trt3(90,90,4,IDLE);

    g.AddTractor(trt1);
    g.AddTractor(trt2);
    g.AddTractor(trt3);

    g.PrintAllTractors(); // all three tractors should be printed out

    //cout<<"Clicking (9,9) found the tractor number "<<g.GetTractor(9,9)<<endl; // should be tractor number 0
    //g.SelectTractor(89,90);
    //g.PrintSelectedTractors(); // should print 2

    //g.PrintSelectedTractors(); // should print 2

    g.SelectTractors(11,49,49,11);
    //g.PrintSelectedTractors(); // should print 0 1

    g.AssignTractorsActivity(HARVESTING);
    g.PrintAllTractors(); // Tractors 0 and 1 should be HARVESTING. Tractor 2 should be IDLE.

    if(!g.MoveTractor(2,99,99)) cout<<"Cannot move tractor 2 to coordinates (99,99)"<<endl; // You should see this message
    if(!g.MoveTractor(2,13,13)) cout<<"Cannot move tractor 2 to coordinates (13,13)"<<endl; // You should see this message

    g.MoveTractor(2,80,50);
    g.PrintTractor(2); // should be the IDLE tractor of size 4 at coordinates (80,50)

    return 0;
}
