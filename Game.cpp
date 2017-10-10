#include <iostream>
using namespace std;

class Tractor{
    int x,y;
    int size;
    int activity;
  public:
    Tractor(){
        x = y = 0;
        size = 1;
        activity = 1;
    }
    Tractor(int x_, int y_, int size_, int activity_){
        x = x_;
        y = y_;
        size = size_;
        activity = activity_;
    }
    
    //accessors
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getSize(){
        return size;
    }
    int getActivity(){
        return activity;
    }
    
    //mutators
    void const setX(int x_){
        x = x_;
    }
    void const setY(int y_){
        y = y_;
    }
    void const setSize(int size_){
        size = size_;
    }
    void const setActivity(int activity_){
        activity = activity_;
    }
};

class Game{
    unsigned int map_size;
  public:
    int getTractor();
    void selectTractor(int x1, int y1, int x2, int y2);
};

int main(){
    cout << "C L O U T" << endl;
    Tractor trac;
    Tractor trac2(1, 1, 2, 2);
    cout << trac.getX() << endl;
    cout << trac2.getSize() << endl;
    trac2.setSize(4);
    cout << trac2.getSize() << endl;
}
