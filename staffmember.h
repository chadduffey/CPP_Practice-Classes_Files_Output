/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Class for staffmembers
File Description:    Class description file
*/// --------------------------------------------------------------------------

class StaffMember
{
      public:
             StaffMember();

             double wage();

             string get_firstName();
             string get_lastName();
             int get_id();

             void set_firstName(string name);
             void set_lastName(string name);
             void set_id(int number);
      private:
             int id;
             string firstName;
             string lastName;      
};
