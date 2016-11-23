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

infantry* chooseBlueUnit(infantry* my_Ghost, infantry* my_Firebat,
                     infantry* my_Marine, infantry* my_Medic,
                     infantry* my_Super );

infantry* chooseRedUnit(infantry* my_Ghost, infantry* my_Firebat,
                     infantry* my_Marine, infantry* my_Medic,
                     infantry* my_Super );
                     
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
       				cout << "Enter your attacking infantry. (BG, BFB, BMA, BMD, BSS): ";
       				
       				attacking_infantry = chooseBlueUnit(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);
       				
       				cout << "Blue Team, Enter the infantry you want to attack. (RG, RFB, RMA, RMD, RSS): ";
       				
		           	infantry_attacked = chooseRedUnit(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);

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
		       		
		       	else if(decision == "heal")
		       		{
			           
			        	cout << "Enter your healing unit. (BG, BFB, BMA, BMD, BSS): ";
			        	infantry_healer = chooseBlueUnit(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);
			           
			        	cout << "Enter your unit to be healed. (BG, BFB, BMA, BMD, BSS): ";
			        	healed_infantry = chooseBlueUnit(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);
					  
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
              
            display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
     display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                
		invalid2=true;
		while(invalid2)
		{
			invalid2 = false;
			cout << "Red Team, Would you like to (Attack, Heal, Other):";
	             cin >> decision;
	             for(int i = 0; i< decision.length();i++)
	             {
	             	decision[i] = tolower(decision[i]);
				 }
				if(decision =="attack")
	        		{
		        				
	       // red team select attacking infantry
       				cout << "Enter your attacking infantry. (RG, RFB, RMA, RMD, RSS): ";
       				
       				attacking_infantry = chooseRedUnit(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);
       				
       				cout << "Red Team, Enter the infantry you want to attack. (BG, BFB, BMA, BMD, BSS): ";
       				
		           	infantry_attacked = chooseBlueUnit(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);

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
		       		}
		       	else if(decision == "heal")
		       		{
			           
			        	cout << "Enter your healing unit. (RG, RFB, RMA, RMD, RSS): ";
			        	infantry_healer = chooseRedUnit(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);
			           
			        	cout << "Enter your unit to be healed. (RG, RFB, RMA, RMD, RSS): ";
			        	healed_infantry = chooseRedUnit(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);
					  
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
	    
	    
    		
      
      
      }  // end if (end of red team's turn)
          
                          
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


infantry* chooseBlueUnit(infantry* my_Ghost, infantry* my_Firebat,
                     infantry* my_Marine, infantry* my_Medic,
                     infantry* my_Super )
{
   infantry* chosenunit;
   bool invalid = true;
   string choice;
   while(invalid)
   {
     invalid = false;
     
     
     
     cin >> choice;
     
     if(choice=="BG")
     	{
			chosenunit = my_Ghost;
	        return chosenunit;
     	}
     else if(choice=="BFB")
     	{
			chosenunit = my_Firebat;
	        return chosenunit;
     	}
     else if(choice=="BMA")
         {
         	chosenunit = my_Marine;
         	return chosenunit;
		 }
     else if(choice=="BMD")
	     {
	     	chosenunit = my_Medic;
	        return chosenunit;
		 }
         
     else if(choice=="BSS")
         {
         	chosenunit = my_Super;
         	return chosenunit;
		 }
     else
     {
         invalid=true;
         cout << "Invalid infantry: Please try again." << endl;
         system("pause");
                      
         //system("cls");
     
//					                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
//					                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                            
     }  // end if
              
    } // end while
}

infantry* chooseRedUnit(infantry* my_Ghost, infantry* my_Firebat,
         infantry* my_Marine, infantry* my_Medic,
         infantry* my_Super )
{
       infantry* chosenunit;
	   bool invalid = true;
	   string choice;
	   while(invalid)
       {
         invalid = false;
         
         
         
         cin >> choice;
         
         if(choice=="RG")
     	{
			chosenunit = my_Ghost;
	        return chosenunit;
     	}
     else if(choice=="RFB")
     	{
			chosenunit = my_Firebat;
	        return chosenunit;
     	}
     else if(choice=="RMA")
         {
         	chosenunit = my_Marine;
         	return chosenunit;
		 }
     else if(choice=="RMD")
	     {
	     	chosenunit = my_Medic;
	        return chosenunit;
		 }
         
     else if(choice=="RSS")
         {
         	chosenunit = my_Super;
         	return chosenunit;
		 }
     else
     {
         invalid=true;
         cout << "Invalid infantry: Please try again." << endl;
         system("pause");
                      
         //system("cls");
     
//					                 display_infantrys(blue_Ghost, blue_Firebat, blue_Marine, blue_Medic, blue_Super);  
//					                 display_infantrys(red_Ghost, red_Firebat, red_Marine, red_Medic, red_Super);  
                            
     }  // end if
              
    } // end while
		
}

     
