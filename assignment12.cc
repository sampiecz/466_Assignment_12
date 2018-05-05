/***********************************************************
 CSCI 466 - Assignment 12 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 3
 TA: Raj 
 Date Due: May 04, 2018 
 Purpose: Use mysql & c++. 
 ************************************************************/
#include <iostream>
#include <mysql.h>
using namespace std;

int main( int argc, char** argv )
{
    // Initialize MySQL library
    mysql_library_init(0, NULL, NULL);

    // Initializes and allocates memoery to a MYSQL object
    MYSQL *connection = mysql_init(NULL);
    if(connection == NULL)
    {
        cerr << "Can't connect to DB." << endl;
        exit(1);
    }

    // Establish connection
    if( mysql_real_connect(connection, "courses", "z1732715", "1996Apr23", "z1732715", 0, NULL, 0) == NULL )
    {
        cerr << "Real connect is broken." << endl;
        exit(1);
    }

    // Execute SQL statement stored in string
    if( mysql_query(connection, "SELECT m.Name, o.LastName, o.FirstName, o.city, ms.BoatName, sr.Description, sr.Status FROM Marina m JOIN MarinaSlip ms JOIN Owner o JOIN ServiceRequest sr ON m.MarinaNum=ms.MarinaNum AND ms.OwnerNum=o.OwnerNum AND ms.SlipID=sr.SlipID") != 0 )
    {
        cerr << "Query did not work." << endl;    
        exit(1);
    }

    // Create result object and store result from connection in it 
    MYSQL_RES *result = mysql_store_result(connection);
    if( result == NULL )
    {
        cerr << "Couldn't store result." << endl;
        exit(1);
    }

    // Create a MYSQL_ROW object to store each row
    // for when I iterate over the result set
    MYSQL_ROW row;

    // While I can keep grabbing a new row
    // from my result set keep outputting
    // each row's column. Make sure to indent
    // the data so it can be read easily.
    while( (row = mysql_fetch_row(result)) )
    {
        cout << "Marina Name: " << row[0] << endl;
        cout << "Owner LastName: " << row[1] << endl;
        cout << "Owner FirstName: " << row[2] << endl; 
        cout << "\tOwner City: " << row[3] << endl; 
        cout << "\tMarina Slip BoatName: " << row[4] << endl;
        cout << "\t\tService Request Description: " << row[5] << endl;
        cout << "\t\tService Request Status" << row[6] << endl;
        cout << endl;
    }

    // Free up memory
    mysql_free_result(result);

    // Close previously opened connection
    mysql_close(connection);

    // Call to clean up memory after use of MySQL library
    mysql_library_end();

    return 0;
}
