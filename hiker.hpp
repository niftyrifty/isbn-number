#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED
#include <string>
#include <iostream>
using namespace std;

//Helper function: Checks for any special characters in the string
bool any_sp_characters(string test_string);

//Function: Returns last integer digit from the input string 
int last_digit(string num_string);

//Function: Remove Space from the string
string rm_space(string num_string);

//Helper function: Removes "-" characters from string 
string rm_chars(string num_string);

//Helper Function: Returns legal last integer digit for 13 digit number
int last_legal_digit(string num_string);

//Helper Function checking if last digit of 10 digit number is valid for ISBN-10
bool legal_isbn(string num_string);

//Helper Function checking if a number is ISBN-10 
bool is_isbnten(string test_string);

//Function checking for whether something is ISBN-10 or ISBN-13
bool check_thirteenisbn(string tester_string);

#endif
