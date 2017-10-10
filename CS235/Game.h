#ifndef GAME_H
#define GAME_H
#include <vector>
enum Activity {SEEDING, HARVESTING, MOVING, IDLE};
class Tractor{
    int x,y;
    unsigned short size;
    Activity activity;
  public:
    //constructors
    Tractor();
    Tractor(int x_, int y_, unsigned short size_, Activity activity_);
    
    //accessors
    int getX();
    int getY();
    int getSize();
    Activity getActivity();
    
    //mutators
    void setX(int const x_);
    void setY(int const y_);
    void setSize(int const size_);
    void setActivity(Activity const activity_);
};

class Game{
    unsigned int map_size;
    std::vector<Tractor> all;
    std::vector<int> selected;
  public:
    //constructor
    Game(unsigned int new_size);
    //select tractors
    int GetTractor(int x, int y);
    void SelectTractor(int x, int y);
    void SelectTractors(int x1, int y1, int x2, int y2);
    //change tractors
    void AddTractor(Tractor new_unit);
    bool MoveTractors(int i, int new_x, int new_y);
    void AssignTractorsActivity(Activity new_activity);
    //print tractors
    void PrintTractor(int i);
    void PrintSelectedTractors();
    void PrintAllTractors();
};
#endif