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
    int mysql_library_init(0, NULL, NULL);

    // Initializes and allocates memoery to a MYSQL object
    MYSQL connection = mysql_init(NULL);
    if(connection == NULL)
    {
        cerr << "Can't connect to DB." << endl;
        exit(1);
    }

    // Establish connection
    if(mysql_real_connect(connection,"courses","z1732715","1996Apr23","z1732715",0,NULL,0) == NULL);
    {
        cerr << "Real connect is broken." << endl;
        exit(1);
    }

    // Execute SQL statement stored in string
    int mysql_query(MYSQL *mysql, const char* stmt_str);
    // The only difference between this command and the one above
    // is the use of length as opposed to a terminating null character.
    // THis allows binary data which may contain null characters as valid data to be sent.
    int mysql_real_query(MYSQL *mysql,
            const char *stmt_str,
            unsigned long length);

    // mysql_num_rows()
    // unsigned int mysql_field_count(MYSWL *mysql)
    // my_ulonglong mysql_insert_id(MYSWL *mysql)
    // How many rows were affected
    // my_ulonglong mysql_affected_rows(MYSQL *mysql)
    //
    // Retreive data from a result set
    // mysql_store_result() is same as PDOStatement::fetchAll()
    // mysql_use_result() is same as PDOStatement::fetch()
    //
    // After using the above two commands I have to use
    // mysql_fetch_row()
    //
    // After all that, free up memory with mysql_free_result()
    // Can also download all rows of result set
    MYSQL_RES *mysql_store_result(MYSQL *mysql);
    // MYSQL_RES *mysql_fetch_row(MYSQL_RES *result)
    // mysql_row_seek()
    // MYSQL *mysql_use_result(MYSQL *mysql)
    //
    // Get byte lengths for field in row
    // unsigned long *mysql_fetch_lengths(MYSQL_RES *result)

    // Close previously opened connection
    void mysql_close(MYSQL, *mysql);

    // Call to clean up memory after use of MySQL library
    void mysql_library_end(void);

    return 0;
}
