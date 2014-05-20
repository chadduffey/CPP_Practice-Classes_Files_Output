/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Class for managers
File Description:    Class implementation file
*/// --------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "staffmember.h"
#include "manager.h"

void Manager::set_Salary(double amount)
{
     salary = amount;     
}

double Manager::get_Salary()
{
       return salary;
}

double Manager::wage()
{
       fortnightwage = (salary / 26.0);
       return fortnightwage;
}

