#include"Game.h"
#include<iostream>

using namespace std;

int main()
{
    Game g(100);
    Tractor trt1(10,10,4,IDLE);
    Tractor trt2(50,50,4,IDLE);
    Tractor trt3(90,90,4,IDLE);

    g.AddTractor(trt1);
    g.AddTractor(trt2);
    g.AddTractor(trt3);

    g.PrintAllTractors(); // all three tractors should be printed out

    cout<<"Clicking (9,9) found the tractor number "<<g.GetTractor(9,9)<<endl; // should be tractor number 0
    g.SelectTractor(89,90);
    g.PrintSelectedTractors(); // should print 2

    g.PrintSelectedTractors(); // should print 2

    g.SelectTractors(11,49,49,11);
    g.PrintSelectedTractors(); // should print 0 1

    g.AssignTractorsActivity(HARVESTING);
    g.PrintAllTractors(); // Tractors 0 and 1 should be HARVESTING. Tractor 2 should be IDLE.

    if(!g.MoveTractor(2,99,99)) cout<<"Cannot move tractor 2 to coordinates (99,99)"<<endl; // You should see this message
    if(!g.MoveTractor(2,13,13)) cout<<"Cannot move tractor 2 to coordinates (13,13)"<<endl; // You should see this message

    g.MoveTractor(2,80,50);
    g.PrintTractor(2); // should be the IDLE tractor of size 4 at coordinates (80,50)

    return 0;
}