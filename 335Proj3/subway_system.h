/*******************************************************************************
  Title          : subway_system.h
  Author         : Kaizen Castanos
  Created on     : April 19, 2018
  Description    : The interface file for the subway_system class
  Purpose        : Used to store information about all subway_entrance, uses
                   several hash tables to store and retreive data. Also contains
                   functions used to respond to commands
  Usage          : Include this file with client code
  Build with     : No building
  Modifications  : 
 
*******************************************************************************/

#ifndef __SUBWAY_SYSTEM_H__
#define __SUBWAY_SYSTEM_H__
#include <iostream>
#include <string>
#include <vector>
#include "subway_entrance.h"
using namespace std;

class subway_system{
private:
  vector<subway_entrance> entrances; //actual entrances
  vector<int> entrance_p_tree; //parent tree
  vector<int> stations; //contains **indices** of stations
  
  vector<int> stations_hash_table; //contains **indices** of stations, but at hashed values
  vector<double> stations_long; //contains longitudes of the centroids of the stations, indexed same as entrances
  vector<double> stations_lat; //contains latitudes of the centroids of the stations, indexed same as entrances

  int line_hash(string x); //simple line hash
  unsigned int station_hash(string x); //more compilcated station hash, uses probing
  void quad_probe(int &hashval, int &k); //probing function used for station hash

  bool is_connected(subway_entrance &e1, subway_entrance &e2);
  bool is_exit_only(string x);

  void sanitize(string &x); //cleans up the string so that we get single spaces, lowercased, etc.
  void calculate_centroid(int index_to_use); //calculates the centroid of a station using its entrances, stores in long/lat vectors
  
public:
  //Constructor, populates the hash table and long/lat vectors with -1
  subway_system();

  /** insert_entrance(subway_entrance e): inserts the subway_entrance
    *   into the system's hash tables, automatically doing any required
    *   unions and hashing. 
    * @return void
    */
  void insert_entrance(subway_entrance e);
  /** insert_entrance(): creates a hash table of stations, as well as 
    *   calculating centroids and storing them.
    * @pre No more entrances need to be added 
    * @return void
    */
  void build_station_hash_table();

  //commands, automatically prints/uses cout
  void list_line_stations(string x);
  void list_all_stations();
  void list_entrances(string x);
  void nearest_station(double long_, double lat_);
  void nearest_lines(double long_, double lat_);
  void nearest_entrance(double long_, double lat_);
};





#endif