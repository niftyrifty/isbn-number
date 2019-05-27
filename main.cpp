#include "hiker.hpp"
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	string number;
	cout << "Please enter a number you would want to test for ISBN Validity " << endl;
	cin >> number; 
	check_thirteenisbn(number);

}