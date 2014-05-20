/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Implementation of casual class
File Description:    Class implementation file
*/// --------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "staffmember.h"
#include "casual.h"

Casual::Casual()
{
     hours = 1;
     rate = 1.0;
     fortnightwage = 0;
}

double Casual::wage()
{
      fortnightwage = rate * hours;
      return fortnightwage;              
}

void Casual::set_hoursWorked(int time)
{
     hours = time;
}

void Casual::set_hourlyRate(double amount)
{
     rate = amount;
}
            
int Casual::get_hoursWorked()
{
    return hours;
}

double Casual::get_hourlyRate()
{
    return rate;
}
