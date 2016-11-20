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

#include "infantry.h"
#include "firebat.h"
#include "ghost.h"


// function prototypes
void display_infantrys(infantry* ghost1, infantry* firebat1,
                     infantry* ghost2, infantry* firebat2,
                     infantry* ghost3,
                     infantry* firebat3);


int main()
{
    int x;
    
    // declare ships of different types for blue team
    ghost b1("Blue Destroyer","ghost");
    firebat b2("Blue Battleship","firebat");
    ghost b3("Blue Carrier","ghost");
    firebat b4("Blue Submarine","firebat"); 
    ghost b5("Blue Sub Carrier","ghost");
    firebat b6("Blue Super Ship","firebat");
      
    
    
    // declare ships of different types for red team
    ghost r1("Red Destroyer","ghost");
    firebat r2("Red Battleship","firebat");
    ghost r3("Red Carrier","ghost");
    firebat r4("Red Submarine","firebat");  
    ghost r5("Red Sub Carrier","ghost");
    firebat r6("Red Super Ship","firebat");    
     
        
     // declare base class pointers for infantrys
     infantry* blue_destroyer;
     infantry* blue_battleship;
     infantry* blue_carrier;
     infantry* blue_submarine;
     infantry* blue_submarine_carrier;
     infantry* blue_super_ship;
     
     infantry* red_destroyer;
     infantry* red_battleship;
     infantry* red_carrier;
     infantry* red_submarine; 
     infantry* red_submarine_carrier;
     infantry* red_super_ship;             
     
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
     infantry* attacking_ship;
     infantry* ship_being_attacked;
     string choice;
     
     turn = 0;

     // for loop to control the turn
     for(turn=0;turn<40;turn++)
     {
     
         if(turn%2==0)   // if it's blue team's turn
         {
             system("cls");
                 
             display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
             display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                              
          
           // blue team select attacking infantry
           
           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "Blue Team, Enter your attacking infantry. (BD, BB, BC, BS, BSC, BSS): ";
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
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                                    
             }  // end if
                      
            } // end while    
         

           // blue team decide which infantry to attack

           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "Blue Team, Enter the infantry you want to attack. (RD, RB, RC, RS, RSC, RSS): ";
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
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while            
          
          
          
            attacking_ship->attack(ship_being_attacked);
            
            if(red_destroyer->getHealth()==0 and red_battleship->getHealth()==0 and red_carrier->getHealth()==0 and red_submarine->getHealth()==0 and red_submarine_carrier->getHealth()==0 and red_super_ship->getHealth()==0)
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
             
             display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
             display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
               
           
           // red team select attacking infantry
           
           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter your attacking infantry. (RD, RB, RC, RS, RSC, RSS): ";
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
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while    
         

           // red team decide which infantry to attack

           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter the infantry you want to attack. (BD, BB, BC, BS, BSC, BSS): ";
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
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_destroyer, blue_battleship, blue_carrier, blue_submarine, blue_submarine_carrier, blue_super_ship);  
                 display_infantrys(red_destroyer, red_battleship, red_carrier, red_submarine, red_submarine_carrier, red_super_ship);  
                    

             }  // end if
                      
            } // end while            
          
            attacking_ship->attack(ship_being_attacked);         
 
            if(blue_destroyer->getHealth()==0 and blue_battleship->getHealth()==0 and blue_carrier->getHealth()==0 and blue_submarine->getHealth()==0 and blue_submarine_carrier->getHealth()==0 and blue_super_ship->getHealth()==0 )
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



//  Below is a general display function that outputs a team's infantrys and their attributes

void display_infantrys(infantry* my_destroyer, infantry* my_battleship,
                     infantry* my_carrier, infantry* my_submarine,
                     infantry* my_submarine_carrier, infantry* my_super_ship)
{
    /*
    cout << edl;
    cout << left
         << setw(17) << "infantry Name"
         << setw(18) << "infantry Type"
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
         */
    cout << "------------------------------------------------------------------------------" << endl;
    
    my_destroyer -> display();
    my_battleship -> display();
    my_carrier -> display();
    my_submarine -> display();    
    my_submarine_carrier -> display();
    my_super_ship -> display();
     
    cout << endl;
   /* 
    if(my_destroyer -> get_team() == "Blue")
        cout << "Total Blue Ships Remaining: " << infantry::get_total_blue_ships() << endl << endl;
    else if(my_destroyer -> get_team() == "Red")
        cout << "Total Red Ships Remaining: " << infantry::get_total_red_ships() << endl << endl;
    */    

}    



     
