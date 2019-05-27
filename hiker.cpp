#include "hiker.hpp"
#include <string>
#include <vector>
#include <cstring>


//Helper function: Checks for any special characters in the string
bool any_sp_characters(string test_string){
    if((test_string.find_first_of(" ") != string::npos)||(test_string.find_first_of("-") != string::npos))  {
        return true;
    }
    return false;
}   

//Function: Returns last integer digit from the input string 
int last_digit(string num_string){
    //Access last digit of string
    char last_num = num_string.back(); 
    if(any_sp_characters(num_string)){
        int index = num_string.find_first_of('\0');
        
        last_num = num_string[index - 1];
    }
    
    //If last_char is X, then digit is 10:
    int digit = 0;
    //Convert num_string to number 
    if(last_num == 'X'){
        digit = 10;
        return digit;
    }
    digit = (int(last_num) - 48);
    return digit;
}

//Function: Remove Space from the string
string rm_space(string num_string){
  if(num_string.length() != 13) {
    int count = 0;
    for(int i = 0; i < int(num_string.length()) ; i++){
        if(num_string[i] != ' '){
           num_string[count++] = num_string[i];
        }
    }
    
    num_string[count] = '\0';
    
  } 
  return num_string;
}

//Helper function: Removes "-" characters from string 
string rm_chars(string num_string){
  if((num_string.length() != 13) || (num_string.length() != 10)) {
    int count = 0;
    for(int i = 0; i < int(num_string.length()) ; i++){
        if(num_string[i] != '-'){
           num_string[count++] = num_string[i];
        }
    }
    
    num_string[count] = '\0';
    
  } 
  return num_string;
}


//Helper Function: Returns legal last integer digit for 13 digit number
int last_legal_digit(string num_string){
    
    //Loop through the vector and calculate the legal last digit, return it
    int num = (int(num_string[0]) - 48) + (int(num_string[2]) - 48) + (int(num_string[4]) - 48) + (int(num_string[6]) - 48) + (int(num_string[8]) - 48) + (int(num_string[10]) - 48); 
    num += 3*((int(num_string[1]) - 48) + (int(num_string[3]) - 48) + (int(num_string[5]) - 48) + (int(num_string[7]) - 48) + (int(num_string[9]) - 48) + (int(num_string[11]) - 48));
    
    int remainder = num % 10;
    return (10 - remainder);
}


//Helper Function checking if last digit of 10 digit number is valid for ISBN-10
bool legal_isbn(string num_string){ 
    int sum = 0;
    for (int i = 0; i < 9; ++i){
        sum += (10-i)*(int(num_string[i]) - 48);
    }
    int legal_last_digit = (11 - (sum % 11))%11;
    int last = last_digit(num_string);

    if(last == legal_last_digit){
        return true;
    }
    
    return false;
}


//Helper Function checking if a number is ISBN-10 
bool is_isbnten(string test_string){
    if(legal_isbn(test_string)){
            return true;
    }
    return false;
}




//Function checking for whether something is ISBN-10 or ISBN-13
bool check_thirteenisbn(string tester_string)
{   
    int str_length = 0;
    
    if(!any_sp_characters(tester_string)){
        str_length = tester_string.length();
    }
    
    if(any_sp_characters(tester_string)){
        //remove the characters
        string num_string = rm_space(tester_string);
        tester_string = rm_chars(num_string);
        str_length = int(tester_string.find_first_of('\0'));
    }
            
    if(str_length == 10){
       //Check if it's a ISBN-10 number 
        if(is_isbnten(tester_string)){
            cout << "Valid ISBN-10 Number. " << endl;
            return true;
        }
        cout << "Not a valid ISBN-10 or ISBN-13 Number. " << endl;
        return false;
    }


    if(str_length == 13){
        if(last_digit(tester_string) == last_legal_digit(tester_string)){
             cout << "Valid ISBN-13 Number. " << endl;
             return true;    
        }
        cout << "Not a valid ISBN-10 or ISBN-13 Number. " << endl;
        return false;
    }
    cout << "Not a valid ISBN-10 or ISBN-13 Number. " << endl;
    return false;
}