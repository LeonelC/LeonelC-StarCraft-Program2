/////////////////////////////////////////////////////////////////////////////
//
//    submarine.cpp  Class Functions for the submarine Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

#include "medic.h"



submarine::submarine(string vname, string vteam, string vtype, int torp, int nuke)
                       : vessel(vname, vteam, vtype)
{
    set_torpedo(torp);
    set_nuclear_missile(nuke);
    set_health(1000);
}

        
void submarine::set_torpedo(int torp)
{
    torpedo = torp;
}



int submarine::get_torpedo() const
{
    return torpedo;
}

        
void submarine::set_nuclear_missile(int nuke)
{
    nuclear_missile = nuke;
}
    

int submarine::get_nuclear_missile() const
{
    return nuclear_missile;
}


void submarine::fire_torpedo(vessel* attacked_vessel)
{
    if(torpedo!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        torpedo--;   
        attacked_vessel->torpedo_hit();
    }    
}

void submarine::launch_nuclear_missile(vessel* attacked_vessel)
{
    if(nuclear_missile!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        nuclear_missile--;
        attacked_vessel->nuclear_missile_hit();
    }    
}


void submarine::light_attack(vessel* attacked_vessel)
{
    int x;
    
    for(x=1;x<=2;x++)
       fire_torpedo(attacked_vessel);
       
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
       
}    


void submarine::heavy_attack(vessel* attacked_vessel)
{
    int x;
     

    for(x=1;x<=2;x++)
       fire_torpedo(attacked_vessel);
           
    launch_nuclear_missile(attacked_vessel);  
      
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
         
}    


void submarine::sink()
{
     set_torpedo(0);
     set_nuclear_missile(0);
}


void submarine::battery_gun_hit()
{
    // subs can't be damaged by battery gun
}

void submarine::main_gun_hit()
{
    // subs can't be damaged by main gun
}

void submarine::cruise_missile_hit()
{
    // subs can't be damaged by cruise missile
}


void submarine::fighter_plane_hit()
{
    // subs can't be damaged by fighter plane
}



void submarine::print() const
{
    cout << endl;
    vessel::print();
    cout << "Torpedos: " << get_torpedo() << endl;
    cout << "Nuclear Missiles: " << get_nuclear_missile() << endl;
        
}  

void submarine::display() const
{
    vessel::display();
    cout << right << setw(5) << " "
         << right << setw(5) << " "
         << right << setw(4) << " "
         << right << setw(4) << " "
         << right << setw(4) << get_torpedo()
         << right << setw(4) << get_nuclear_missile()
         << endl;
     
} 


