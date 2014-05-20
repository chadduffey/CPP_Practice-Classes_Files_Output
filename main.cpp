/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Main function for payroll application
File Description:    Main class implementation
Files Required:      Casual.cpp, casual.h, manager.cpp, manager.h, payroll.cpp
                     payroll.h, staffmember.cpp, staffmember.h, company.cpp,
                     company.h
*/// --------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "payroll.h"
#include "company.h"


int main()
{
    int selection, validinput = 2, exitprogram = 1, nextId = 333;
    bool exists = false;
    string badInput, companyToLoad, fileToCheck, createNew, co, 
           entryChoice = "x", dbname;

    Company newcompany;
    clearFiles();
    
    //-------------------------------------------------------LOAD EXISTING DATA
    while (! validchoice(entryChoice))
    {
          FormatEntryScreen();
          cin >> entryChoice;
          system("cls");
    }

    if ((entryChoice == "y") || (entryChoice == "Y"))
    {
        cout << "Enter the name of the company to load: ";
        cin >> companyToLoad;
        fileToCheck = companyToLoad + ".db";
        exists = file_exists(fileToCheck);
        
        if (exists)
        {
               newcompany.setCompanyName(companyToLoad);
               cout << "-------------------------------------\n"
                    << "Success - Loaded Database for: " 
                    << newcompany.getCompanyName()
                    << "\n-------------------------------------\n\n"; 
                          
               system("pause");
               system("cls");
        }
        
        else
        {
               system("cls");
               cout << "Unknown Company Selected\n\n";
               reportValidSelections();
               cout << "Create and load new database for " 
                    << companyToLoad << "? (Y\\N):";
               cin >> createNew;
               if ((createNew == "Y") || (createNew == "y"))
               {  
                     createDatabase(fileToCheck, companyToLoad);
                     newcompany.setCompanyName(companyToLoad);
                     cout << "\nSuccess - Loaded Database for: " 
                          << newcompany.getCompanyName() << endl << endl;              
               }   
               system("pause");
               system("cls");
        }
    }
    //---------------------------------------------END OF LOADING EXISTING DATA
    
    //make copy of db in case user dosnt want to commit changes
    dbname = newcompany.getCompanyName() + ".db";
    copyfile(dbname, "temp.db");    
    
    //-----------------MAIN BLOCK - PROGRAM TERMINATES WHEN MENU ITEM 5 CHOOSEN
    do{
        //---------------LOOP WILL CONTINUE ON MAIN MENU UNLESS VALID SELECTION
        do{
            FormatMainScreen();
            if (!(cin >> selection))
            {
                 system("cls");
                 cout << "Character Input Entered,";
                 cout << " please choose from the menu\n";
                 cin.clear();
                 cin >> badInput;
                 validinput = 1;
                 system("PAUSE");
                 system("cls");
            }
            else 
            {          
                 validinput = 2;
                 while (validSelection(selection)) 
                 {
                       system("cls");
                       FormatMainScreen();
                       cin >> selection;
                 }                 
            }
        }
        while (validinput == 1);
        //--------------------------------------------END OF THE SELECTION LOOP
        
        
        //---------------------------------------------VALID CHOICES TO PROCESS 
        //add staff member
        if (selection == 1)
        {
                      dbname = newcompany.getCompanyName() + ".db";
                      nextId = getnextid(dbname) + 1;
                      createStaffMember(nextId, dbname);
        }
        //Display or Edit Staff Member
        if (selection == 2)
        {
                      int editRequested = displayStaffMember(dbname);
                      if (editRequested != 0)
                         editStaffMember(editRequested, dbname);
        }
        //Remove staff member
        if (selection == 3)
        {
                     removeStaffMember(dbname); 
        }
        //Report on all staff members
        if (selection == 4)
        {
                      reportAllStaff(newcompany.getCompanyName());
        }
        
        //exit program
        if (selection == 5)
        {
                  co = newcompany.getCompanyName();
                  int reallyExit = savefile(co);
                  if (reallyExit == 0)
                                 exitprogram = 5;
        }
        //-------------------------------------------END OF VALID CHOICES BLOCK
    }
    while (exitprogram == 1 );
    //------------------------------PROGRAM TERMINATES WHEN MENU ITEM 5 CHOOSEN
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
