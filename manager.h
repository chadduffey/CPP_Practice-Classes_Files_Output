/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Class for managers, inherits from staffmember class
File Description:    Class description file
*/// --------------------------------------------------------------------------

class Manager : public StaffMember
{
      public:
             double wage();
             void set_Salary(double amount); 
             double get_Salary();            
      private:       
             double salary;
             double fortnightwage;
};
