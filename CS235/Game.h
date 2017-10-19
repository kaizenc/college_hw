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
    int getX() const; //read-only function, use const
    int getY() const;
    int getSize() const;
    Activity getActivity() const;
    
    //mutators
    void setX(int const x_); //take care not to change parameter, use const
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
    Game(unsigned int const new_size);
    //select tractors
    int GetTractor(int x, int y) const; //returns index, -1 if not found
    void SelectTractor(int const &x, int const &y); //throw into selected vector
    void SelectTractors(int const &x1, int const &y1, int const &x2, int const &y2); //rectangle drag and select
    //change tractors
    void AddTractor(Tractor new_unit);
    bool MoveTractor(int i, int new_x, int new_y); //takes index, changes coords to new_x, new_y
    void AssignTractorsActivity(Activity &new_activity);
    //print tractors
    void PrintTractor(int const &i); //takes index, prints out ???
    void PrintSelectedTractors(); //take a look at selected vector
    void PrintAllTractors(); //what do you think this means
};
#endif