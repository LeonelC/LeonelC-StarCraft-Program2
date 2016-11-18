///////////////////////////////////////////////////////////////////////
//
//      vessel.cpp   Class Functions for the vessel Class (Base Class)
//
//      Created by Will McWhorter, Ph.D.
// 
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "infantry.h"


// initialize total_ships to zero
int vessel::total_blue_ships = 0;
int vessel::total_red_ships = 0;



// constructors

vessel::vessel()
{
    set_name("Unknown");
    set_type("Unknown"); 
    

}


vessel::vessel(string vname, string vteam, string vtype)
{
    set_name(vname);
    set_type(vtype);
    set_team(vteam);
    
    if(get_team()=="Blue")
       total_blue_ships++;
    else if(get_team()=="Red")
       total_red_ships++;
    

}       


// set and get functions

void vessel::set_name(string vname)
{
    name = vname;
}
        
        
string vessel::get_name() const
{
    return name;
}
        
void vessel::set_type(string vtype)
{
    type = vtype;
}


string vessel::get_type() const
{
    return type;
}        


void vessel::set_health(int h)
{
    health = h;
}


int vessel::get_health() const
{
    return health;
}
    

void vessel::set_team(string vteam)
{
    team = vteam;
}
        
        
string vessel::get_team() const
{
    return team;
}



int vessel::get_total_blue_ships()
{
    return total_blue_ships;
}


int vessel::get_total_red_ships()
{
    return total_red_ships;
}



// Below are the hit functions that are used to deduct health from vessels
// that are attacked.

void vessel::torpedo_hit()
{
    health = health - 50;  
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
          
       health = 0; 
    }
}


void vessel::battery_gun_hit()
{
    health = health - 1;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}

void vessel::main_gun_hit()
{
    health = health - 30;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}

void vessel::cruise_missile_hit()
{
    health = health - 40;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}

void vessel::nuclear_missile_hit()
{
    health = health - 500;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}

 
void vessel::fighter_plane_hit()
{
    health = health - 20;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}    
       
void vessel::laser_hit()
{
    health = health - 250;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 
    }
}   

void vessel::plasma_cluster_nuke_hit()
{
    health = health - 2000;
    if(health < 0)
    {
       if(get_team()=="Blue")
          total_blue_ships--;
       else if(get_team()=="Red")
          total_red_ships--;
    
       health = 0; 

    }
}           
  
         
              
              
// print is a general output function 
                                     
void vessel::print() const
{
    cout << endl;
    cout << "Vessel Name: " << get_name() << endl;
    cout << "Vessel Type: " << get_type() << endl;
    cout << "Vessel Health: " << get_health() << endl;
}


// display is an output function that is used to output attributes in the game display table

void vessel::display() const
{
    cout << left << setw(17) << get_name()
         << left << setw(19) << get_type()
         << right << setw(6) << get_health();   
    
}

