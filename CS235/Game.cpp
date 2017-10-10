#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

//------------Tractor Class Definitions-----------//
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
//accessors
int Tractor::getX(){
    return x;
}
int Tractor::getY(){
    return y;
}
int Tractor::getSize(){
    return size;
}
Activity Tractor::getActivity(){
    return activity;
}
//mutators
void const Tractor::setX(int x_){
    x = x_;
}
void const Tractor::setY(int y_){
    y = y_;
}
void const Tractor::setSize(int size_){
    size = size_;
}
void const Tractor::setActivity(Activity activity_){
    activity = activity_;
}

//------------Game Class Definitions-----------//



int main(){
    cout << "C L O U T" << endl;
    Tractor trac;
    Tractor trac2(1, 1, 2, MOVING);
    cout << trac.getX() << endl;
    cout << trac2.getSize() << endl;
    trac2.setSize(4);
    cout << trac2.getSize() << endl;
}
