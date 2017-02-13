#include<iostream>
#include<map>
#include<string>

int main() {
	// Create a map of salaries per employee.
	std::map<std::string,double> salaries;

	// Set Pat's salary.
	salaries[ "Pat" ] = 75000.00;
	std::cout << salaries[ "Pat" ] << std::endl;

	// What is Jan's salary?
	std::cout << salaries[ "Jan" ] << std::endl;

	// What happens if we don't have an employee?
	std::map<std::string,double>::const_iterator itr;
	itr = salaries.find( "Chris" );
	if( itr == salaries.end( ) )
		std::cout << "Not an employee of this company!" << std::endl;
	else
		std::cout << itr->second << std::endl;

	// Try salaries as a string.
	std::cout << std::endl << std::endl<< std::endl << std::endl << "String Time!";
	std::cout << std::endl << "Will print out the default for std::string, an empty string " << std::endl;
	std::cout << "if nothing is found in the map.";
	std::cout << std::endl << std::endl << std::endl;
	std::map<std::string,std::string> str_salaries;

	// Set Pat's salary.
	str_salaries[ "Pat" ] = "75000.00";
	std::cout << str_salaries[ "Pat" ] << std::endl;

	// What is Jan's salary?
	std::cout << str_salaries[ "Jan" ] << std::endl;

	// What happens if we don't have an employee?
	std::map<std::string,std::string>::const_iterator str_itr;
	str_itr = str_salaries.find( "Chris" );
	if( str_itr == str_salaries.end( ) )
		std::cout << "Not an employee of this company!" << std::endl;
	else
		std::cout << str_itr->second << std::endl;

	return 0;
}