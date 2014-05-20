/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: program functions for payroll application
File Description:    function implementations
*/// --------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
using namespace std;
#include "Payroll.h"
#include "staffmember.h"
#include "Manager.h"
#include "Casual.h"
#include "company.h"


void FormatEntryScreen()
{
     cout << "\n----------- Welcome to Payroll System ------------- "        <<endl;
     cout << "--------------------------------------------------- "        << endl <<endl; 
     cout << "Would you like to load an existing database? (Y\\N): ";     
}

void FormatMainScreen()
{
     cout << " --------- Payroll System ---------   "      << endl;
     cout << "|                                  |"        << endl;  
     cout << "| Main Menu:                       |"        << endl;
     cout << "|                                  |"        << endl;
     cout << "| 1) Add a new staff member        |"        << endl;
     cout << "| 2) Display or Edit Staff Member  |"        << endl;
     cout << "| 3) Remove staff member           |"        << endl;
     cout << "| 4) Report on all staff members   |"        << endl;      
     cout << "|                                  |"        << endl;
     cout << "| 5) Exit the program              |"        << endl;
     cout << "|                                  |"        << endl;
     cout << " ---------------------------------- "        << endl << endl;
     
     cout << "Selection: ";
}


int validSelection (int selection)
//returns a 0 if a valid selection has been made
{
     int result = 1;
      
     if (selection == 1)
          result = 0;
     else if (selection == 2)
          result = 0;
     else if (selection == 3)
          result = 0;
     else if (selection == 4)
          result = 0;
     else if (selection == 5)
          result = 0;
     else if (selection == 6)
          result = 0;
     else
         result = 1;
     return result;
} 


bool file_exists(const string& s) 
{
        ifstream iff(s.c_str());
        return iff.is_open();
}


void reportValidSelections()
{
     string record;
     ifstream in_stream;
     in_stream.open("companies.db");
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
     
     cout << "Possible choices are:" << endl;
         
     while (! in_stream.eof())
     {                     
             getline(in_stream,record);
             cout << " " << record << endl; 
     } 
     
     cout << endl;
     in_stream.close();     
}

void createDatabase(string name, string company)
{
     char * cstr;
     
     //convert the filename to a character string 
     cstr = new char [name.size()+1];
     strcpy (cstr, name.c_str());
     
     //create new database
     ofstream myfile;
     myfile.open (cstr);
     myfile.close(); 
     
     //notify userm and set newcomapny to new database name
     cout << "-----------------------------------------\n";
     cout << "Database created: " << name << endl;
     
     //update companies.db to reflect new option
     ofstream out_stream;
     out_stream.open("companies.db", ios::app);
     out_stream << company << endl; 
     out_stream.close();
}

int savefile(string file)
{
     string choice, loaddb = "x", companyToLoad, fileToCheck, createNew, 
            sure = "x";
     string filename = file + ".db";
     bool exists;
     int cancel = 0;
     
     system("cls");
     cout << "Commit your changes to " 
          << filename << "? (Y\\N): ";
     cin >> choice;
     while (! validchoice(choice))      
     {
           system("cls");
           cout << "Commit changes to " 
                << filename << "? (Y\\N): ";
           cin >> choice;
     }
     
     if ((choice == "y") || (choice == "Y"))
     {
     //we leave the database alone, since we are using the real copy
     //its only if we discard that we need a file operation
     
             if (filename == ".db")
             //use default.db
             {
                     filename = "default.db";
             }
             cout << "\n---> Data saved to " << filename << endl << endl;
     }
     else if ((choice == "n") || (choice == "N"))
          while (! validchoice(sure))
          {
                cout << "\nAre you sure? (ALL CHANGES WILL BE LOST) (Y\\N): ";
                cin >> sure;
          }
          if ((sure == "y") || (sure == "Y"))
          {
             //here we need to discard changes to our database
             //by copying the temp.db to the live database
             //since temp.db is the database condition at system start
             cout << "\n---> Discarding Changes...\n";
             copyfile("temp.db", filename);
             cout << "---> Changes have been discarded...\n\n";
             cancel = 0;
          }
          else if ((sure == "n") || (sure == "N"))
          {
               cancel = 1;
               system("cls");
          }
          
          return cancel;
}

bool validchoice(string c)
{
     bool validchoice = false;
     if ((c == "Y") || (c == "y") || (c == "N") || (c == "n"))
        validchoice = true;
     
     return validchoice;
}

bool validMorC (string mc)
{
     bool validchoice = false;
     if ((mc == "M") || (mc == "m") || (mc == "C") || (mc == "c"))
        validchoice = true;
     
     return validchoice;
}

void createStaffMember(int num, string db)
{
     string choice = "x", firstname, lastname;
     double pay, rate;
     int hours;
     
     system("cls");
     
     //make decision on manager or casual
     while (! validMorC(choice))
     {
           cout << "--- NEW STAFF MEMBER ---" << endl << endl;
           cout << "Choose Manager or Casual (M or C): ";
           cin >> choice;
           if (! validMorC(choice))
              system("cls");
     }
     
     //Manager Code
     if ((choice == "m") || (choice == "M"))
     {
        Manager newmanager;
        cout << "\n---------------------------\n";
        cout << "Creating new manager: \n";
        cout << "---------------------------\n\n";
        cout << "First Name: \t";
        cin >> firstname;
        newmanager.set_firstName(firstname);
        cout << "Last Name: \t";
        cin >> lastname;
        newmanager.set_lastName(lastname);
        cout << "Salary: \t$";
        cin >> pay;
        newmanager.set_Salary(pay);
        newmanager.set_id(num);
        cout << "\n---------------------------\n\n";
        cout << "New Manager Created: \n\n";
        cout << "Staff Id: \t\t" << newmanager.get_id() << endl; 
        cout << "First Name: \t\t" << newmanager.get_firstName() << endl;
        cout << "Last Name: \t\t" << newmanager.get_lastName() << endl;
        cout << "Fortnight Wage: \t$" << newmanager.wage() << endl;
        cout << "\n---------------------------\n\n";
        writeToDatabase(newmanager.get_id(), newmanager.get_firstName(), newmanager.get_lastName(), "manager",
                    newmanager.get_Salary(), 0.00, 0, db);       
     }
     
     //Casual code
     if ((choice == "c") || (choice == "C"))
     {
        Casual newcasual;
        cout << "\n---------------------------\n";
        cout << "Creating new casual: \n";
        cout << "---------------------------\n\n";
        cout << "Firstname: \t";
        cin >> firstname;
        newcasual.set_firstName(firstname);
        cout << "Lastname: \t";
        cin >> lastname;
        newcasual.set_lastName(lastname);
        cout << "Hours worked: \t";
        cin >> hours;
        newcasual.set_hoursWorked(hours);
        cout << "Hourly rate: \t$";
        cin >> rate;
        newcasual.set_hourlyRate(rate);       
        newcasual.set_id(num);
        cout << "\n---------------------------\n\n";
        cout << "New Casual Created: \n\n";
        cout << "Staff Id: \t\t" << newcasual.get_id() << endl; 
        cout << "Firstname: \t\t" << newcasual.get_firstName() << endl;
        cout << "Lastname: \t\t" << newcasual.get_lastName() << endl;
        cout << "Hourly Rate: \t\t$" << newcasual.get_hourlyRate() << endl;
        cout << "Hours Worked: \t\t" << newcasual.get_hoursWorked() << endl;
        cout << "Fortnight Wage: \t$" << newcasual.wage() <<endl;
        cout << "\n---------------------------\n\n";
        writeToDatabase(newcasual.get_id(), newcasual.get_firstName(), 
                        newcasual.get_lastName(), "casual", 0.00, newcasual.get_hourlyRate(),
                        newcasual.get_hoursWorked(), db); 
     }     
     system("pause");     
     system("cls");
}

int getnextid(string filename)
{
    string strhigestnumber, record;
    int highestnumber;
    char * cstr;
     
    //convert the filename to a character string 
    cstr = new char [filename.size()+1];
    strcpy (cstr, filename.c_str());
     
     // Read staff numbers in from the staff database from the company.db file
     ifstream in_stream;
     in_stream.open(cstr);
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }     
     while (! in_stream.eof())
     {
             getline(in_stream,record);
     } 
     
     //drag out the first three characters of the last entry, which will be
     //the highest staff number  
     for (int i = 0; i < 3; i++)
              strhigestnumber = strhigestnumber + record.at(i);
      
     //convert highest number string to an integer to be used as return value
     highestnumber = GetIntVal(strhigestnumber);
     
     in_stream.close(); 
     return highestnumber;
}

int GetIntVal(string strConvert) 
{ 
  int intReturn; 
  intReturn = atoi(strConvert.c_str()); 

  return(intReturn);     
}

double GetDoubleVal(string strConvert) 
{ 
  double doubleReturn; 
  doubleReturn = atof(strConvert.c_str()); 

  return doubleReturn;     
}

void copyfile(string filename1, string filename2)
{

    char * cstr;
    char * cstr2;
         
    //convert the filename to a character string 
    cstr = new char [filename1.size()+1];
    strcpy (cstr, filename1.c_str());

    //convert the filename to a character string 
    cstr2 = new char [filename2.size()+1];
    strcpy (cstr2, filename2.c_str());
    
    ifstream in_stream(cstr,ios::in|ios::binary);
    ofstream out_stream(cstr2,ios::out | ios::binary);
    out_stream << in_stream.rdbuf();
    in_stream.close();
    out_stream.close();    
}

void writeToDatabase(int id, string firstname, string lastname, string type,
                    double salary, double rate, int hoursworked, string database)
{
    char * cstr;
         
    //convert the filename to a character string 
    cstr = new char [database.size()+1];
    strcpy (cstr, database.c_str());
    
    ofstream out_stream;

     out_stream.open(cstr,ios::app);    // open file for appending
     if (out_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }    
     out_stream << endl << id << " " << type << " " << firstname << " " << lastname << " " 
                << salary << " " << rate << " " << hoursworked;
     out_stream.close();
}

void reportAllStaff(string name)
{
     char * cstr;
     string file = name + ".db", record, id, firstname, lastname, type, salary, rate,
            hoursWorked, csvexport = "x", htmlexport = "x", wage, csvString, 
            tempString, htmldisplay; 
     
     int intid, inthoursWorked;
     double dblsalary, dblrate, totalwages = 0;
            
     Manager newmanager;
     Casual newcasual;
         
     //convert the filename to a character string 
     cstr = new char [file.size()+1];
     strcpy (cstr, file.c_str());
     
     system("cls");
     cout << name << " Staff Members Report\n";
     cout << "-------------------------------\n\n";
     cout << "ID\tNAME\t\t\tTYPE\t\tWAGE\n";
     
     // Read in the staff database from the company.db file
     ifstream in_stream;
     in_stream.open(cstr);
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
     
     
     while (! in_stream.eof())
     {
             getline(in_stream,record);
             istringstream iss(record);
             iss >> id >> type >> firstname >> lastname >> 
                 salary >> rate >> hoursWorked;
             //convert to numbers
             intid = GetIntVal(id);
             inthoursWorked = GetIntVal(hoursWorked);
             dblsalary = GetDoubleVal(salary); 
             dblrate = GetDoubleVal(rate);
             
             if (type == "manager")
             {
                newmanager.set_firstName(firstname);
                newmanager.set_lastName(lastname);
                newmanager.set_Salary(dblsalary);
                newmanager.set_id(intid);
                cout << newmanager.get_id() << "\t" << newmanager.get_firstName()
                     << " " << newmanager.get_lastName() << "\t\t" << "Manager"
                     << "\t\t" << "$" << newmanager.wage() << endl;
                totalwages = totalwages + newmanager.wage();
                id = intToString(newmanager.get_id());
                wage = doubleToString(newmanager.wage());
                csvString = id + "," +  newmanager.get_firstName() + "," + 
                            newmanager.get_lastName() + "," + "manager," +  wage;
                tempString = id + " " +  newmanager.get_firstName() + " " + 
                            newmanager.get_lastName() + " " + "manager " +  wage;    
             }
             if (type == "casual")
             {
                newcasual.set_firstName(firstname);
                newcasual.set_lastName(lastname);
                newcasual.set_hoursWorked(inthoursWorked);
                newcasual.set_hourlyRate(dblrate);       
                newcasual.set_id(intid);
                cout << newcasual.get_id() << "\t" << newcasual.get_firstName()
                     << " " << newcasual.get_lastName() << "\t\t" << "Casual"
                     << "\t\t" << "$" << newcasual.wage() << endl;
                totalwages = totalwages + newcasual.wage(); 
                id = intToString(newcasual.get_id());
                wage = doubleToString(newcasual.wage());               
                csvString = id + "," +  newcasual.get_firstName() + "," + 
                            newcasual.get_lastName() + "," + "casual," +  wage;
                tempString = id + " " +  newcasual.get_firstName() + " " + 
                            newcasual.get_lastName() + " " + "casual " +  wage;
             }

             writeToCsv(csvString);
             writeToTemp(tempString);
     } 

     in_stream.close();    
     
     cout << "-------------------------------\n";
     cout << "\nTotal Payroll: $" << totalwages << endl << endl;
     
     while (! validchoice(csvexport))
     {
           cout << "Export to CSV? (Y\\N): ";
           cin >> csvexport;
     }
     
     if ((csvexport == "y") || (csvexport == "Y"))
     {
        //export to csv
        cout << "Exporting to output.csv \n";
        cout << "CSV file written to program directory\n";
        cout << "\nView CSV output now? (Y\\N): ";
        cin >> csvexport;
        if ((csvexport == "y") || (csvexport == "Y"))
        {
           //could use system("output.csv" to display nicer,
           //but limiting system calls.
           cout << "\nContents of output.csv: \n";
           cout << "----------------------------\n";
           system("type output.csv");
           cout << endl << endl;
        }
     }
     
     while (! validchoice(htmlexport))
     {
           cout << "Export to HTML? (Y\\N): ";
           cin >> htmlexport;
     }
     
     //export to HTML
     if ((htmlexport == "y") || (htmlexport == "Y"))
     {
          // you can show the html with system("test.html")
          //in the default browser, but limiting system calls
          writeToHtml(totalwages);          
     }
     
     while (! validchoice(htmldisplay))
     {
           cout << "Display HTML page? (Y\\N): ";
           cin >> htmldisplay;      
     }
     
     //display html page
     if ((htmldisplay == "y") || (htmldisplay == "Y"))
        system("output.html");
            
     system("pause");
     system("cls");
}

string intToString(int num)
{
    string s;
    stringstream out;
    out << num;
    s = out.str();
    return s;
}

string doubleToString(double num)
{
    string s;
    stringstream out;
    out << num;
    s = out.str();
    return s;
}

void writeToCsv(string entry)
{
    ofstream out_stream;
    char * file = "output.csv";

     out_stream.open(file, ios::app);    // open file for appending
     if (out_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
         
     out_stream << entry << endl;
     out_stream.close();
}

void clearFiles()
{
    ofstream out_stream;
    ofstream out_stream2;
    char * file = "output.csv";
    char * file2 = "tempreport.txt";

     out_stream.open(file);    // open file for appending
     out_stream2.open(file2);
     if (out_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
     if (out_stream2.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
     out_stream.close();
     out_stream2.close();
}

void writeToHtml(double total)
{
     string record, id, firstname, lastname, type, wage;
     
     ifstream in_stream;
     ofstream out_stream;
     
     in_stream.open("tempreport.txt");
     out_stream.open("output.html");
     
     if (in_stream.fail())
     {
             cout << "Error opening output.csv\n";
             exit(1);
     }
     
     if (out_stream.fail())
     {
             cout << "Error opening output.html\n";
             exit(1);
     } 
     
     out_stream << "<html>" << endl 
                << "<h2>Payroll Report</h2>" << endl
                << "<body>" << endl;
     out_stream << "<table border=""2"" cellspacing=""0"" cellpadding=""7"">" << endl
                << "<tr><th>Id</th>" << endl 
                << "<th>First Name</th>" << endl
                << "<th>Surname</th>" << endl
                << "<th>Type</th>" << endl
                << "<th>Wage</th></tr>" << endl;
         
     while (! in_stream.eof())
     {                     
             getline(in_stream,record);
             istringstream iss(record);
             iss >> id >> firstname >> lastname >> 
                 type >> wage;
             
             out_stream << "<tr><td>" << id << "</td>" << endl
                        << "<td>" << firstname << "</td>" << endl
                        << "<td>" << lastname << "</td>" << endl
                        << "<td>" << type << "</td>" << endl
                        << "<td>" << "$"<< wage << "</td></tr>" << endl;              
     }
     
     out_stream << "<h4>Total Payroll: $" << total << "</h4>" << endl;
     out_stream << "<p>Details: " << "</p>" << endl;
     out_stream << "</body>" << endl << "</html>";
     //closing html tags
     
     in_stream.close();
     out_stream.close();         
}

void writeToTemp(string entry)
{
    ofstream out_stream;
    char * file = "tempreport.txt";

     out_stream.open(file, ios::app);    // open file for appending
     if (out_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
         
     out_stream << entry << endl;
     out_stream.close();                                      
}

int displayStaffMember(string dbname)
{
    int id, edit = 0;
    string strModify = "x";
    
    system("cls");
    cout << "Display staff member\n";
    cout << "-------------------------\n\n";
    cout << "Enter Staff ID: ";
    cin >> id;

    int valid = validate_id(id, dbname);
    if (valid == 1)
    {
       cout << "\nStaff Member: \t" << id << "\n";
       fetchStaffMember(id, dbname);
       while (! validchoice(strModify))          
       {
             cout << "Edit Staff Member? (Y\\N): ";
             cin >> strModify;
             if ((strModify == "Y")||(strModify == "y"))
                edit = id;
       }
    }
    else if (valid == 0)
        cout << "\nInvalid Staff Id, returning you to main menu\n"; 
    
    if (id == 0)
       system("pause");
    
    system("cls");
    
    return edit; //pass the staff number to edit back if edit requested
}

int validate_id(int staffnum, string dbname)
{
     string record, strId;
     int intId, IdArray[LICENCENUMBER], arrayCount = 0, match = 0;

     char * cstr;
     
    //convert the filename to a character string 
    cstr = new char [dbname.size()+1];
    strcpy (cstr, dbname.c_str());
     
     ifstream in_stream;
     in_stream.open(cstr);
     
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }     

     //read staff numbers into an array
     while (! in_stream.eof())
     {
           strId = "";
           getline(in_stream,record);
           for (int i = 0; i < 3; i++)
           {
               strId = strId + record.at(i);
               intId = GetIntVal(strId);
           }
           
           IdArray[arrayCount] = intId;
           arrayCount++;
     }
 
     //check if the record matches one read into the array
     for (int a = 0; a < arrayCount; a++)
     {
        if (IdArray[a] == staffnum)
                       match = 1;
     }
                    
     in_stream.close(); 
     
     //return 1 if record is found, return 0 if not
     return match;
 }

void fetchStaffMember(int number, string dbname)
{
     string strRecord, strId, strEdit;
     string id, firstname, lastname, type, salary, rate, hoursWorked;
     int intId = 0, intEdit = 0;
     
     char * cstr;
     
     //convert the filename to a character string 
     cstr = new char [dbname.size()+1];
     strcpy (cstr, dbname.c_str());
     
     ifstream in_stream;
     in_stream.open(cstr);
     
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }
     //read in staff members till target is found
     //validation is done in separate function, only valid 
     //staff id's will be passed to this function
     while (! in_stream.eof())
     {
           getline(in_stream,strRecord);
           for (int i = 0; i < 3; i++)
           {
               strId = strId + strRecord.at(i);
               intId = GetIntVal(strId);
           }

           if (intId == number)
           { 
              istringstream iss(strRecord);               
              iss >> id >> type >> firstname >> lastname >>  
                      salary >> rate >> hoursWorked;
              cout << "First Name: \t" << firstname << endl 
                   << "Last Name:  \t" << lastname << endl
                   << "Employee Type: \t" << type << endl
                   << "Salary: \t$" << salary << endl
                   << "Hourly Rate: \t$" << rate << endl
                   << "Hours Worked: \t" << hoursWorked << endl << endl;
           }
           //reset the strId variable;       
           strId = "";
     }
    
     in_stream.close(); 
}

void editStaffMember (int staffid, string dbname)
{
     string firstname, lastname, choice = "x", modifiedDetail, strId, strPay;
     string strRate, strHours;
     double pay, rate;
     int hours;
     
     system("cls");
     cout << "Editing staff member: " << staffid << endl << endl;
     
     strId = intToString(staffid);
     
     while (!validMorC(choice))
     {
          cout << "Manager or Casual? (M\\C): ";
          cin >> choice;
     }
     
//Manager Code
     if ((choice == "m") || (choice == "M"))
     {
        Manager newmanager;
        cout << "First Name: \t";
        cin >> firstname;
        newmanager.set_firstName(firstname);
        cout << "Last Name: \t";
        cin >> lastname;
        newmanager.set_lastName(lastname);
        cout << "Salary: \t$";
        cin >> pay;
        strPay = doubleToString(pay);
        newmanager.set_Salary(pay);
        cout << "\n---------------------------\n\n";
        cout << "Staff Member: " << staffid << " modified \n\n";
        cout << "First Name: \t\t" << newmanager.get_firstName() << endl;
        cout << "Last Name: \t\t" << newmanager.get_lastName() << endl;
        cout << "Fortnight Wage: \t$" << newmanager.wage() << endl;
        cout << "\n---------------------------\n\n";
        modifiedDetail = strId + " " + "manager" + " " + firstname + " " + lastname + " " + strPay + " " + "0" + " " + "0";
     }
//Casual code
     if ((choice == "c") || (choice == "C"))
     {
        Casual newcasual;
        cout << "Firstname: \t";
        cin >> firstname;
        newcasual.set_firstName(firstname);
        cout << "Lastname: \t";
        cin >> lastname;
        newcasual.set_lastName(lastname);
        cout << "Hours worked: \t";
        cin >> hours;
        newcasual.set_hoursWorked(hours);
        cout << "Hourly rate: \t$";
        cin >> rate;
        newcasual.set_hourlyRate(rate); 
        strRate = doubleToString(newcasual.get_hourlyRate());
        strHours = intToString(newcasual.get_hoursWorked());      
        cout << "\n---------------------------\n\n";
        cout << "Staff Member: " << staffid << " modified \n\n";
        cout << "Firstname: \t\t" << newcasual.get_firstName() << endl;
        cout << "Lastname: \t\t" << newcasual.get_lastName() << endl;
        cout << "Hourly Rate: \t\t$" << newcasual.get_hourlyRate() << endl;
        cout << "Hours Worked: \t\t" << newcasual.get_hoursWorked() << endl;
        cout << "Fortnight Wage: \t$" << newcasual.wage() <<endl;
        cout << "\n---------------------------\n\n";
        modifiedDetail = strId + " " + "casual" + " " + newcasual.get_firstName()
                         + newcasual.get_lastName() + " " + "0" + " " 
                         + strRate + " " + strHours;
     }     
     
     sliceIntoDb(modifiedDetail, dbname, staffid);
     
     system("pause");
     system("cls");
}

void sliceIntoDb(string details, string db, int id)
{
     string record, strId;
     int intId;
     ifstream in_stream, instream;
     ofstream out_stream, outstream;
     
     char * cstr;
     
    //convert the filename to a character string 
    cstr = new char [db.size()+1];
    strcpy (cstr, db.c_str());
     
     in_stream.open(cstr);
     out_stream.open("out.tmp");
     
     if (in_stream.fail())
     {
             cout << "Error opening company.db\n";
             exit(1);
     }

     while (! in_stream.eof())
     {                     
             getline(in_stream,record);
             for (int i = 0; i < 3; i++)
             {
                 strId = strId + record.at(i);    
             }
             intId = GetIntVal(strId);
             
             if (intId != id)
                out_stream << record << endl;
             if (intId == id)
             {
                out_stream << details << endl;
                cout << "Record updated\n";
             }              
             strId = "";
     }
     
     in_stream.close();
     out_stream.close();
    
     instream.open("out.tmp");
     outstream.open(cstr);
     
     if (in_stream.fail())
     {
             cout << "Error opening file\n";
             exit(1);
     }
     
     while (! instream.eof())
     {                     
             getline(instream,record);
             outstream << record << endl;
     }
     
     instream.close();
     outstream.close();
}

void removeStaffMember(string db)
{
     int choice, intId;
     string yn, record, strId;
     
     system("cls");
     cout << "Remove staff member:\n\n";
     cout << "Enter the Id of the staff member to remove: ";
     cin >> choice;
     fetchStaffMember(choice, db);
     while (! validchoice(yn))
     {
           cout << "\nAre you sure you want to DELETE this staff member? (Y\\N): ";
           cin >> yn;
     }
     
     if ((yn == "y") || (yn == "Y"))
     {
          char * cstr;
          //convert the filename to a character string 
          cstr = new char [db.size()+1];
          strcpy (cstr, db.c_str());
         
          ifstream in_stream;
          ofstream out_stream;
          in_stream.open(cstr);
          out_stream.open("out.tmp");
            
          while (! in_stream.eof())
          {                       
                 getline(in_stream,record);
                 for (int i = 0; i < 3; i++)
                 {
                     strId = strId + record.at(i);    
                 }
                 intId = GetIntVal(strId);
                 
                 if (intId != choice)
                    out_stream << record << endl;
                 if (intId == choice)
                 {
                    cout << "\nRecord removed\n";
                 }              
                 strId = "";
          }
          
          in_stream.close();
          out_stream.close();
          
          ifstream instream;
          ofstream outstream;      
          instream.open("out.tmp");
          outstream.open(cstr);
          
          while (! instream.eof())
          {                     
               getline(instream,record);
               outstream << record << endl;
          }
         
          instream.close();
          outstream.close();
          
          
          cout << "\nStaff Member " << choice << " deleted.\n\n";
     }
          
     system("pause");
     system("cls");    
}
