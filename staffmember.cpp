/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Implentation for staffmembers
File Description:    Class implementation file
*/// --------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "staffmember.h"

StaffMember::StaffMember()
{
     firstName = "default";
     lastName = "default";
     id = 100;             
}

double StaffMember::wage()
//returns the wage of the staff member
{
              
}

string StaffMember::get_firstName()
{
     return firstName;
}


void StaffMember::set_firstName(string name)
{
     firstName = name;
}

string StaffMember::get_lastName()
{
     return lastName;
}

void StaffMember::set_lastName(string name)
{
     lastName = name;
}

int StaffMember::get_id()
{
     return id;
}

void StaffMember::set_id(int number)
{
     id = number;     
} 

