/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Class for casual staff, inherits from staffmember class
File Description:    Class description file
*/// --------------------------------------------------------------------------

class Casual : public StaffMember
{
      public:
             Casual();
             double wage();
             
             void set_hoursWorked(int time);
             void set_hourlyRate(double amount);
             
             int get_hoursWorked();
             double get_hourlyRate();             
      private:       
             int hours;
             double rate;
             double fortnightwage;
};
