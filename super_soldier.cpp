//////////////////////////////////////////////////////////////////////////////////////
//
//    super_ship.cpp (Derived Class - Multiple Inheritance)
//                                                                                   
//    NOTE: This class is derived from multiple base classes which are derived 
//          from the same base class (diamond inheritance)
//
//    Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "super_soldier.h"

using namespace std;

super_ship::super_ship(string vname, string vteam, string vtype, 
    int dbgun, int bbgun, int mgun, int bcruise,  
    int fighter, int ccruise, int torp, int nuke)
    :vessel(vname,vteam,vtype),destroyer(vname,vteam,vtype,dbgun),
     battleship(vname,vteam,vtype,mgun,bcruise,bbgun),
     carrier(vname,vteam,vtype,fighter,ccruise),
     submarine(vname,vteam,vtype,torp,nuke)
{
     set_laser(10); 
     set_plasma_cluster_nuke(4);
     set_health(8000);
     //cout << "I'm a super ship" << endl;
}


void super_ship::set_laser(int vlaser)
{
    laser = vlaser;
}
    

int super_ship::get_laser() const
{
    return laser;
}

void super_ship::set_plasma_cluster_nuke(int plasma)
{
    plasma_cluster_nuke = plasma;
}
    

int super_ship::get_plasma_cluster_nuke() const
{
    return plasma_cluster_nuke;
}

void super_ship::fire_laser(vessel* attacked_vessel)
{
    if(this->laser!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        laser--; 
        attacked_vessel->laser_hit();
    }    
}


void super_ship::fire_plasma_cluster_nuke(vessel* attacked_vessel)
{

    if(this->plasma_cluster_nuke!=0 && this->get_health()!=0 && attacked_vessel->get_health()!= 0)
    {
        plasma_cluster_nuke--; 
        attacked_vessel->plasma_cluster_nuke_hit();
    }    
}


void super_ship::light_attack(vessel* attacked_vessel)
{
    int x;
    

    destroyer::light_attack(attacked_vessel);
    battleship::light_attack(attacked_vessel);     
    submarine::light_attack(attacked_vessel);
    carrier::light_attack(attacked_vessel);
    
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
        
}    


void super_ship::heavy_attack(vessel* attacked_vessel)
{
    destroyer::heavy_attack(attacked_vessel);
    battleship::heavy_attack(attacked_vessel);
    submarine::heavy_attack(attacked_vessel);
    carrier::heavy_attack(attacked_vessel);  
    fire_laser(attacked_vessel);  
    fire_plasma_cluster_nuke(attacked_vessel);
    
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();

}   


void super_ship::sink()
{
     destroyer::sink();
     battleship::sink();
     submarine::sink();
     carrier::sink();
     set_laser(0);
     set_plasma_cluster_nuke(0);
}



void super_ship::print() const
{
    cout << endl;
    vessel::print();
    destroyer::print();
    battleship::print();
    submarine::print();
    carrier::print();
    cout << "Laser: " << get_laser();
    cout << "Plasma Cluster Nuke: " << get_plasma_cluster_nuke() << endl;
        
}  

void super_ship::display() const
{
    vessel::display();
    
    cout << right << setw(5) << destroyer::get_battery_gun()+battleship::get_battery_gun()
         << right << setw(5) << get_main_gun()
         << right << setw(4) << battleship::get_cruise_missile()+carrier::get_cruise_missile()
         << right << setw(4) << get_fighter_plane()
         << right << setw(4) << get_torpedo()
         << right << setw(4) << get_nuclear_missile()
         << right << setw(4) << get_laser()
         << right << setw(4) << get_plasma_cluster_nuke()
         << endl;
     
} 
