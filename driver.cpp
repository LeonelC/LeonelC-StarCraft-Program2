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
#include "marine.h"
#include "medic.h"
#include "super_soldier.h"

// function prototypes
void display_infantrys(infantry* ghost1, infantry* firebat1,
                     infantry* marine1, infantry* medic,
                     infantry* super);


int main()
{
    int x;
    
    // declare ships of different types for blue team
    ghost b1("Blue Ghost","ghost");
    firebat b2("Blue Firebat","firebat");
    marine b3("Blue Marine","marine");
    medic b4("Blue Medic","medic");
    superSoldier b5("Blue Super","Super Soldier");
      
    
    
    // declare ships of different types for red team
    ghost r1("Red Ghost","ghost");
    firebat r2("Red Firebat","firebat");
    marine r3("Red Marine","marine"); 
    medic r4("Red Medic","medic");
    superSoldier r5("Red Super","Super Soldier");    
     
        
     // declare base class pointers for infantrys
     infantry* blue_Ghost;
     infantry* blue_Firebat;
     infantry* blue_Marine;
     infantry* blue_Medic;
     infantry* blue_Super;
     
     infantry* red_Ghost;
     infantry* red_Firebat;
     infantry* red_Marine;
     infantry* red_Medic;
     infantry* red_Super;             
     
     // point the base class pointers at their corresponding derived class objects     
     blue_Ghost = &b1;
     blue_Firebat = &b2;
     blue_Marine = &b3;
     blue_Medic = &b4;
     blue_Super = &b5;
     
     red_Ghost = &r1;
     red_Firebat = &r2;
     red_Marine = &r3;
     red_Medic = &r4;
     red_Super = &r5;        
     
         
     // beginning of the main game processes      
     
     // set up some stuff needed by the game processes   
     int turn;
     bool invalid;
     bool invalid2;
     infantry* attacking_infantry;
     infantry* infantry_attacked;
     infantry* infantry_healer;
     infantry* healed_infantry;
     string decision;
     string choice;
     
     turn = 0;

     // for loop to control the turn
     for(turn=0;turn<40;turn++)
     {
     
         if(turn%2==0)   // if it's blue team's turn
         {
             //system("cls");
                 
             display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
             display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                        
				invalid2=true;
				while(invalid2)
				{
					invalid2 = false;
					cout << "Blue Team, Would you like to (Attack, Heal, Other):";
			             cin >> decision;
			             for(int i = 0; i< decision.length();i++)
			             {
			             	decision[i] = tolower(decision[i]);
						 }
						if(decision =="attack")
			        		{
				        				
		           // blue team select attacking infantry
		           
					           invalid=true;  // reset bad selection flag
					           
					           while(invalid)
					           {
					             invalid = false;
					             
					             
					             cout << "Enter your attacking infantry. (BG, BFB, BMA, BMD, BSS): ";
					             cin >> choice;
					             
					             if(choice=="BG")
					                 attacking_infantry = blue_Ghost;
					             else if(choice=="BFB")
					                 attacking_infantry = blue_Firebat;
					             else if(choice=="BMA")
					                 attacking_infantry = blue_Marine;
					             else if(choice=="BMD")
					                 attacking_infantry = blue_Medic;
					             else if(choice=="BSS")
					                 attacking_infantry = blue_Super;
					             else
					             {
					                 invalid=true;
					                 cout << "Invalid infantry" << endl;
					                 system("pause");
					                              
					                 //system("cls");
					             
					                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
					                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
					                                    
					             }  // end if
					                      
					            } // end while    
					         
					
					           // blue team decide which infantry to attack
					
					           invalid=true;  // reset bad selection flag
					           
					           while(invalid)
					           {
					             invalid = false;
					             
					        
					             cout << "Blue Team, Enter the infantry you want to attack. (RG, RFB, RMA, RMD, RSS): ";
					             cin >> choice;
					             
					             if(choice=="RG")
					                 infantry_attacked = red_Ghost;
					             else if(choice=="RFB")
					                 infantry_attacked = red_Firebat;
					             else if(choice=="RMA")
					                 infantry_attacked = red_Marine;
					             else if(choice=="RMD")
					                 infantry_attacked = red_Medic;
					             else if(choice=="RSS")
					                 infantry_attacked = red_Super;
					             else
					             {
					                 invalid=true;
					                 cout << "Invalid infantry" << endl;
					                 system("pause");
					                              
					                 //system("cls");
					             
					                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
					                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
					                    
					
					             }  // end if
					                      
					            } // end while            
					          
					          
					          
					            attacking_infantry->attack(infantry_attacked);
					            if(red_Ghost->getHealth()==0 and red_Firebat->getHealth()==0 and red_Marine->getHealth()==0 and red_Medic->getHealth()==0 and red_Super->getHealth()==0)
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
				       		}
//decision == heal				       		
				       	else if(decision == "heal")
				       		{
				       		invalid=true;  // reset bad selection flag
					           
					           while(invalid)
						           {
						             invalid = false;
						             
						             
						             cout << "Enter your healing unit. (BG, BFB, BMA, BMD, BSS): ";
						             cin >> choice;
						             
						             if(choice=="BG")
						                 infantry_healer = blue_Ghost;
						             else if(choice=="BFB")
						                 infantry_healer = blue_Firebat;
						             else if(choice=="BMA")
						                 infantry_healer = blue_Marine;
						             else if(choice=="BMD")
						                 infantry_healer = blue_Medic;
						             else if(choice=="BSS")
						                 infantry_healer = blue_Super;
						             else
						             {
						                 invalid=true;
						                 cout << "Invalid infantry" << endl;
						                 system("pause");
						                              
						                 //system("cls");
						             
						                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
						                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
						                                    
						             }  // end if
						                      
						            }
						        invalid = true;
								while(invalid)
						           {
						             invalid = false;
						             
						             
						             cout << "Enter your unit to be healed. (BG, BFB, BMA, BMD, BSS): ";
						             cin >> choice;
						             
						             if(choice=="BG")
						                 healed_infantry = blue_Ghost;
						             else if(choice=="BFB")
						                 healed_infantry = blue_Firebat;
						             else if(choice=="BMA")
						                 healed_infantry = blue_Marine;
						             else if(choice=="BMD")
						                 healed_infantry = blue_Medic;
						             else if(choice=="BSS")
						                 healed_infantry = blue_Super;
						             else
						             {
						                 invalid=true;
						                 cout << "Invalid infantry" << endl;
						                 system("pause");
						                              
						                 //system("cls");
						             
						                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
						                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
						                                    
						             }  // end if
						                      
						            }
								infantry_healer->renderAid(healed_infantry);		
							}
						else if(decision == "other")
							{
								break;
							}
						else
							{
								invalid2=true;
						                 cout << "Invalid Entry" << endl;
						                 system("pause");
						                              
						                 //system("cls");
						             
						                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
						                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);
							}
				}
            
            
            
          
          
          }  // end if (end of blue team's turn)
         
         
          else if(turn%2==1)  // else if it's red team's turn
          {
              
            // system("cls");
             
             display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
             display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
               
           
           // red team select attacking infantry
           
           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter your attacking infantry. (RG, RFB, RME, RMD, RSS): ";
             cin >> choice;
             
             if(choice=="RG")
                 attacking_infantry = red_Ghost;
             else if(choice=="RFB")
                 attacking_infantry = red_Firebat;
             else if(choice=="RMA")
                 attacking_infantry = red_Marine;
             else if(choice=="RMD")
                 attacking_infantry = red_Medic;
             else if(choice=="RSS")
                 attacking_infantry = red_Super;
             else
             {
                 invalid=true;
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                    

             }  // end if
                      
            } // end while    
         

           // red team decide which infantry to attack

           invalid=true;  // reset bad selection flag
           
           while(invalid)
           {
             invalid = false;
             
        
             cout << "RED Team, Enter the infantry you want to attack. (BG, BFB, BMA, BMD, BSS): ";
             cin >> choice;
             
             if(choice=="BG")
                 infantry_attacked = blue_Ghost;
             else if(choice=="BFB")
                 infantry_attacked = blue_Firebat;
             else if(choice=="BMA")
                 infantry_attacked = blue_Marine;
             else if(choice=="BMD")
                 infantry_attacked = blue_Medic;
             else if(choice=="BSS")
                 infantry_attacked = blue_Super;
             else
             {
                 invalid=true;
                 cout << "Invalid infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                    

             }  // end if
                      
            } // end while            
          
            attacking_infantry->attack(infantry_attacked);         
 
            if(blue_Ghost->getHealth()==0 and blue_Firebat->getHealth()==0 and blue_Marine->getHealth()==0 and blue_Medic->getHealth()==0 and  blue_Super->getHealth()==0 )
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

void display_infantrys(infantry* my_Ghost, infantry* my_Firebat,
                     infantry* my_Marine, infantry* my_Medic,
                     infantry* my_Super)
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
    
    my_Ghost -> display();
    my_Firebat -> display();
    my_Marine -> display();
    my_Medic -> display();    
    my_Super -> display();
     
    cout << endl;
   /* 
    if(my_Ghost -> get_team() == "Blue")
        cout << "Total Blue Ships Remaining: " << infantry::get_total_blue_ships() << endl << endl;
    else if(my_Ghost -> get_team() == "Red")
        cout << "Total Red Ships Remaining: " << infantry::get_total_red_ships() << endl << endl;
    */    

}    



     
