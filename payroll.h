/*Author:            Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        25th May 2010
Last Modification:

Program Description: Payroll application
File Description:    Main function implemenations
*/// --------------------------------------------------------------------------

//PROGRAM CONSTANTS
const int LICENCENUMBER = 100; //how many users the application is licenced for
                               //Limitations are imposed in the program for this 
                               //number

//PROGRAM PROTOTYPES

void FormatEntryScreen();
//set up the entry screen

void FormatMainScreen();
//Set up the main menu, called when switching between menus

int validSelection (int selection);
//check if a valid selection has been entered. Returns 0 if valid and 1 if invalid.
//valid selections match those from the main menu: 1, 2, 3, 4, 5.
//takes the user menu selection as a param to check it

bool file_exists(const string& s);
//checks if the database requested exists, allows user to create

void reportValidSelections();
//displays valid company databases that could be loaded as a hint

void createDatabase(string name, string company);
//create a new database for new company

int savefile(string file);
//on exit, user is given the oppertunity to save the applicaton

bool validchoice(string c);
//simple check on y/n data entry to make sure we dont get junk

bool validMorC (string mc);
//check for M or C in the manager or casual selection

void createStaffMember(int num, string db);
//main function for creating staff members

int getnextid(string filename);
//return the next availible id number for the given database

int GetIntVal(string strConvert);
//convert string higest number to int

void copyfile(string filename1, string filename2);
//make copy of a file (backup)

void writeToDatabase(int id, string firstname, string lastname, string type,
                         double salary, double rate, int hoursworked, string database);
//function to handle writes to the database

void reportAllStaff(string name);
//produce on screen report of all staff

double GetDoubleVal(string strConvert);
//return double value for string containing numbers

string intToString(int num);
//convert int to string

string doubleToString(double num);
//convert double to string

void writeToCsv(string entry);
//write data to csv file for user

void clearFiles();
//clear the csv file for later use if user requests it

void writeToHtml(double total);
//write output to a HTML file for web display

void writeToTemp(string entry);
//write to a temp file in case of problems

int displayStaffMember(string dbname);
//display a staff member from the database

int validate_id(int staffnum, string dbname);
//check if staff id is valid

void fetchStaffMember(int number, string dbname);
//display the staff member.

void editStaffMember (int staffid, string dbname);
//function to edit staff members

void sliceIntoDb(string details, string db, int id);
//slice the modified record back into the database

void removeStaffMember(string db);
//remove staff member from database.
