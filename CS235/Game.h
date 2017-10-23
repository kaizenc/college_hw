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
    void setX(int const &x_); //take care not to change parameter
    void setY(int const &y_);
    void setSize(int const &size_);
    void setActivity(Activity const &activity_);
};

class Game{
    unsigned int map_size;
    std::vector<Tractor> all;
    std::vector<int> selected;
  public:
    //constructor
    Game(unsigned int const &new_size);
    //select tractors
    int GetTractor(int x, int y) const; 
    void SelectTractor(int const &x, int const &y); 
    void SelectTractors(int const &x1, int const &y1, int const &x2, int const &y2); 
    //change tractors
    void AddTractor(Tractor const &new_unit);
    bool MoveTractor(int i, int new_x, int new_y); 
    void AssignTractorsActivity(Activity new_activity);
    //print tractors
    void PrintTractor(int const &i);
    void PrintSelectedTractors(); 
    void PrintAllTractors(); 
};
#endif