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
    Tractor(int const &x_, int const &y_, unsigned short const &size_, Activity const &activity_);
    
    //accessors
    int getX() const; //read-only function
    int getY() const;
    int getSize() const;
    Activity getActivity() const;
    
    //mutators
    void setX(int x_); //take care not to change parameter
    void setY(int y_);
    void setSize(int size_);
    void setActivity(Activity activity_);
};

class Game{
    unsigned int map_size;
    std::vector<Tractor> all;
    std::vector<int> selected;
  public:
    //constructor
    Game(unsigned int new_size);
    //select tractors
    int GetTractor(int x, int y) const; 
    void SelectTractor(int x, int y); 
    void SelectTractors(int x1, int y1, int x2, int y2); 
    //change tractors
    void AddTractor(Tractor const &new_unit);
    bool MoveTractor(int i, int new_x, int new_y); 
    void AssignTractorsActivity(Activity new_activity);
    //print tractors
    void PrintTractor(int i) const;
    void PrintSelectedTractors() const; 
    void PrintAllTractors() const; 
};
#endif