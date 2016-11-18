///////////////////////////////////////////////////////////////////
//
//       vessel.h  Class Definition for vessel (base class)
//
//       Created by Will McWhorter, Ph.D.
//  
///////////////////////////////////////////////////////////////////

#ifndef INFANTRY_H
#define INFANTRY_H


#include <string>
#include <iomanip>

using namespace std;

class vessel
{
    public:
        vessel();
        vessel(string, string, string);
        
        void set_name(string);
        string get_name() const;
        
        void set_type(string);
        string get_type() const;
        
        void set_health(int);
        int get_health() const;
        
        void set_team(string);
        string get_team() const;
        
        static int get_total_blue_ships();
        static int get_total_red_ships();
                
        virtual void torpedo_hit();
        virtual void battery_gun_hit();
        virtual void main_gun_hit();
        virtual void cruise_missile_hit();
        virtual void nuclear_missile_hit();
        virtual void fighter_plane_hit();
        virtual void laser_hit();
        virtual void plasma_cluster_nuke_hit();
                
        virtual void light_attack(vessel*)=0;
        virtual void heavy_attack(vessel*)=0;
        virtual void sink()=0;
                
        virtual void print() const;
        virtual void display() const;
              
    private:
        string name;
        string type;
        string team;
        int health;
        
        static int total_blue_ships;
        static int total_red_ships;

};    


#endif

