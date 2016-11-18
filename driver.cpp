//////////////////////////////////////////////////////////////////////////////
//
//   Driver Code
//
//   This file contains the main client code that drives the game processes.
//       
//   Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using std::vector;

using namespace std;


// include all the class definition files

#include "vessel.h"
#include "battleship.h"
#include "destroyer.h"
#include "carrier.h"
#include "submarine.h"
#include "submarine_carrier.h"
#include "super_ship.h"

// function prototypes
void display_vessels(vessel* my_destroyer, vessel* my_battleship,
                     vessel* my_carrier, vessel* my_submarine,
                     vessel* my_submarine_carrier,
                     vessel* my_super_ship);


int main()
{
    int x;
    
    // declare ships of different types for blue team
    destroyer b1("Blue Destroyer","Blue");
    battleship b2("Blue Battleship","Blue");
    carrier b3("Blue Carrier","Blue");
    submarine b4("Blue Submarine","Blue"); 
    submarine_carrier b5("Blue Sub Carrier","Blue");
    super_ship b6("Blue Super Ship","Blue");
      
    
    
    // declare ships of different types for red team
    destroyer r1("Red Destroyer","Red");
    battleship r2("Red Battleship","Red");
    carrier r3("Red Carrier","Red");
    submarine r4("Red Submarine","Red");  
    submarine_carrier r5("Red Sub Carrier","Red");
    super_ship r6("Red Super Ship","Red");    
     
        
     // declare base class pointers for vessels
     vessel* blue_destroyer;
     vessel* blue_battleship;
     vessel* blue_carrier;
     vessel* blue_submarine;
     vessel* blue_submarine_carrier;
     vessel* blue_super_ship;
     
     vessel* red_destroyer;
     vessel* red_battleship;
     vessel* red_carrier;
     vessel* red_submarine; 
     vessel* red_submarine_carrier;
     vessel* red_super_ship;             
     
     // point the base class pointers at their corresponding derived class objects     
     blue_destroyer = &b1;
     blue_battleship = &b2;
     blue_carrier = &b3;
     blue_submarine = &b4;
     blue_submarine_carrier = &b5;
     blue_super_ship = &b6;
     
     red_destroyer = &r1;
     red_battleship = &r2;
     red_carrier = &r3;
     red_submarine = &r4; 
     red_submarine_carrier = &r5;
     red_super_ship = &r6;        
     
         
     // beginning of the main game processes      
     
     // set up some stuff needed by the game processes   
     int turn;
     bool invalid;
     vessel* attacking_ship;
     vessel* ship_being_attacked;
     string choice;
     
     turn = 0;

     // for loop to control the turn
     for(turn=0;turn<40;turn++)
     {
     
         if(turn%2==0)   // if it's blue team's turn
         {
             system("cls");
                 
             display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
             display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                              
          
           // blue team select attacking vessel
           
           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "Blue Team, Enter your attacking vessel. (BD, BB, BC, BS, BSC, BSS): ";
             cin >> choice;
             
             if(choice=="BD")
                 attacking_ship = blue_destroyer;
             else if(choice=="BB")
                 attacking_ship = blue_battleship;
             else if(choice=="BC")
                 attacking_ship = blue_carrier;
             else if(choice=="BS")
                 attacking_ship = blue_submarine;
             else if(choice=="BSC")
                 attacking_ship = blue_submarine_carrier;
             else if(choice=="BSS")
                 attacking_ship = blue_super_ship;
             else
             {
                 invalid=true;
                 cout << "Invalid Vessel" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                                    
             }  // end if
                      
            } // end while    
         

           // blue team decide which vessel to attack

           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "Blue Team, Enter the vessel you want to attack. (RD, RB, RC, RS, RSC, RSS): ";
             cin >> choice;
             
             if(choice=="RD")
                 ship_being_attacked = red_destroyer;
             else if(choice=="RB")
                 ship_being_attacked = red_battleship;
             else if(choice=="RC")
                 ship_being_attacked = red_carrier;
             else if(choice=="RS")
                 ship_being_attacked = red_submarine;
             else if(choice=="RSC")
                 ship_being_attacked = red_submarine_carrier;
             else if(choice=="RSS")
                 ship_being_attacked = red_super_ship;
             else
             {
                 invalid=true;
                 cout << "Invalid Vessel" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while            
          
          
          
            attacking_ship->heavy_attack(ship_being_attacked);
            
            if(vessel::get_total_red_ships()==0)
            {
                system("cls");
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << "                        ";
                cout << "        BLUE TEAM WINS!!!!!      " << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << endl << endl << endl << endl << endl;
                system("pause");
                return 0;
            }
            
            
          
          
          }  // end if (end of blue team's turn)
         
         
          else if(turn%2==1)  // else if it's red team's turn
          {
              
             system("cls");
             
             display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
             display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
               
           
           // red team select attacking vessel
           
           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter your attacking vessel. (RD, RB, RC, RS, RSC, RSS): ";
             cin >> choice;
             
             if(choice=="RD")
                 attacking_ship = red_destroyer;
             else if(choice=="RB")
                 attacking_ship = red_battleship;
             else if(choice=="RC")
                 attacking_ship = red_carrier;
             else if(choice=="RS")
                 attacking_ship = red_submarine;
             else if(choice=="RSC")
                 attacking_ship = red_submarine_carrier;
             else if(choice=="RSS")
                 attacking_ship = red_super_ship;
             else
             {
                 invalid=true;
                 cout << "Invalid Vessel" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while    
         

           // red team decide which vessel to attack

           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter the vessel you want to attack. (BD, BB, BC, BS, BSC, BSS): ";
             cin >> choice;
             
             if(choice=="BD")
                 ship_being_attacked = blue_destroyer;
             else if(choice=="BB")
                 ship_being_attacked = blue_battleship;
             else if(choice=="BC")
                 ship_being_attacked = blue_carrier;
             else if(choice=="BS")
                 ship_being_attacked = blue_submarine;
             else if(choice=="BSC")
                 ship_being_attacked = blue_submarine_carrier;
             else if(choice=="BSS")
                 ship_being_attacked = blue_super_ship;
             else
             {
                 invalid=true;
                 cout << "Invalid Vessel" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_vessels(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_vessels(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while            
          
            attacking_ship->heavy_attack(ship_being_attacked);         
 
            if(vessel::get_total_blue_ships()==0)
            {
                system("cls");
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << "                        ";
                cout << "        RED TEAM WINS!!!!!      " << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << endl << endl << endl << endl << endl;                system("pause");
                return 0;
            }        
         
     
          }  // end if (end red team's turn)
          
                          
        }  // end for
                                 
                                                             

    cout << endl;
    system("pause");
    return 0;
       
}



//  Below is a general display function that outputs a team's vessels and their attributes

void display_vessels(vessel* my_destroyer, vessel* my_battleship,
                     vessel* my_carrier, vessel* my_submarine,
                     vessel* my_submarine_carrier, vessel* my_super_ship)
{
    
    cout << endl;
    cout << left
         << setw(17) << "Vessel Name"
         << setw(18) << "Vessel Type"
         << right
         << setw(7) << "Health"
         << setw(5) << "BGun"
         << setw(5) << "MGun"
         << setw(4) << "CM"
         << setw(4) << "FP"
         << setw(4) << "TP"
         << setw(4) << "NM"
         << setw(4) << "LZ"
         << setw(4) << "PCN"
         << endl;
         
    cout << "------------------------------------------------------------------------------" << endl;
    
    my_destroyer -> display();
    my_battleship -> display();
    my_carrier -> display();
    my_submarine -> display();    
    my_submarine_carrier -> display();
    my_super_ship -> display();
     
    cout << endl;
    
    if(my_destroyer -> get_team() == "Blue")
        cout << "Total Blue Ships Remaining: " << vessel::get_total_blue_ships() << endl << endl;
    else if(my_destroyer -> get_team() == "Red")
        cout << "Total Red Ships Remaining: " << vessel::get_total_red_ships() << endl << endl;
        

}    



     
