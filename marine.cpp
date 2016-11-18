///////////////////////////////////////////////////////////////////////////////
//
//    battleship.cpp  Class Functions for the battleship Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

#include "marine.h"



battleship::battleship(string vname, string vteam, string vtype, int main, int cruise, int battery)
                       : vessel(vname, vteam, vtype)
{
    set_main_gun(main);
    set_cruise_missile(cruise);
    set_battery_gun(battery);
    set_health(5000);
    //cout << "I'm a battleship." << endl;
}

        
void battleship::set_main_gun(int main)
{
    main_gun = main;
}


int battleship::get_main_gun() const
{
    return main_gun;
}

        
void battleship::set_cruise_missile(int cruise)
{
    cruise_missile = cruise;
}
    

int battleship::get_cruise_missile() const
{
    return cruise_missile;
}

        
void battleship::set_battery_gun(int battery)
{
    battery_gun = battery;
}


int battleship::get_battery_gun() const
{
    return battery_gun;
}

        
void battleship::fire_main_gun(vessel* attacked_vessel)
{
    if(main_gun!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        main_gun--;
        attacked_vessel->main_gun_hit();
    }    
}

void battleship::launch_cruise_missile(vessel* attacked_vessel)
{
    if(cruise_missile!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        cruise_missile--;
        attacked_vessel->cruise_missile_hit();
    }    
}

void battleship::fire_battery_gun(vessel* attacked_vessel)
{
    if(battery_gun!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        battery_gun--;
        attacked_vessel->battery_gun_hit();
    }    
}    

void battleship::light_attack(vessel* attacked_vessel)
{
    int x;

    launch_cruise_missile(attacked_vessel);
        
    for(x=1;x<=15;x++)
       fire_battery_gun(attacked_vessel);
       
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();

}    

void battleship::heavy_attack(vessel* attacked_vessel)
{
    int x;
 
    for(x=1;x<=10;x++)
        fire_main_gun(attacked_vessel);
           
    for(x=1;x<=3;x++)    
        launch_cruise_missile(attacked_vessel);
        
    for(x=1;x<=50;x++)
        fire_battery_gun(attacked_vessel);
        
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
    
}    


void battleship::sink()
{
    set_battery_gun(0);
    set_main_gun(0);
    set_cruise_missile(0);
} 


void battleship::print() const
{
    cout << endl;
    vessel::print();
    cout << "Main Gun Rounds: " << get_main_gun() << endl;
    cout << "Cruise Missiles: " << get_cruise_missile() << endl;
    cout << "Battery Gun Rounds: " << get_battery_gun() << endl;
    
}   


void battleship::display() const
{
    vessel::display();
    cout << right << setw(5) << get_battery_gun()
         << right << setw(5) << get_main_gun()
         << right << setw(4) << get_cruise_missile()
         << endl;
     
}     

