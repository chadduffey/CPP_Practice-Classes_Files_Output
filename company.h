/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Class for company
File Description:    Class description file
*/// --------------------------------------------------------------------------

class Company
{
      public:
             Company();
             string getCompanyName();
             string getDatabaseName();
             void setCompanyName(string newName);             
      private:       
             string name;
             string database;        
};
