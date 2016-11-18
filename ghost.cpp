/////////////////////////////////////////////////////////////////////////////
//
//    destroyer.cpp  Class Functions for the destroyer Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

#include "ghost.h"


destroyer::destroyer(string vname, string vteam, string vtype, int battery)
                       : vessel(vname, vteam, vtype)
{
    set_battery_gun(battery);
    set_health(2000);
    //cout << "I'm a destroyer"<<endl;
}
        
void destroyer::set_battery_gun(int battery)
{
    battery_gun = battery;
}

int destroyer::get_battery_gun() const
{
    return battery_gun;
}
        
void destroyer::fire_battery_gun(vessel* attacked_vessel)
{
    if(battery_gun!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        battery_gun--;
        attacked_vessel->battery_gun_hit();
    }    
}    

void destroyer::light_attack(vessel* attacked_vessel)
{
    
    int x;
 
    for(x=1;x<=15;x++)
       fire_battery_gun(attacked_vessel);
       
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
 
}    

void destroyer::heavy_attack(vessel* attacked_vessel)
{
    int x;

    for(x=1;x<=50;x++)
       fire_battery_gun(attacked_vessel);
       
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();

    
}  

void destroyer::sink()
{
    set_battery_gun(0);
}  

void destroyer::print() const
{
    cout << endl;
    vessel::print();
    cout << "Battery Gun Rounds: " << get_battery_gun() << endl;
    
} 


void destroyer::display() const
{
    //if(this->get_health()==0)
        //this->sink();
         
    vessel::display();
    cout << right << setw(5) << get_battery_gun()
         << endl;
     
} 

