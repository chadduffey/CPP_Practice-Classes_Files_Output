/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Implementation of company class
File Description:    Class implementation file
*/// --------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
#include "company.h"

Company::Company()
{
       name = "default";
       database = "default.db";                      
}

string Company::getCompanyName()
{
       return name;
}

string Company::getDatabaseName()
{
       return database;
}

void Company::setCompanyName(string newName)
{
     string dbpath;
     name = newName;
     dbpath = newName + ".db";
     database = dbpath;
}
