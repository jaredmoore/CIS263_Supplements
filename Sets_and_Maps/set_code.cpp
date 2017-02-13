#include<iostream>
#include<set>
#include<string>

class CaseInsensitiveCompare {
	public:
	bool operator( )( const std::string & lhs, const std::string & rhs ) const { 
		return strcasecmp( lhs.c_str( ), rhs.c_str( ) ) < 0; 
	}
};

int main() {
	// Using the default < comparator.
	std::set<std::string> s;

	// Using the custom CaseInsenstiveCompare comparitor.
	//std::set<std::string,CaseInsensitiveCompare> s;

	s.insert( "Hello" ); 
	s.insert( "HeLLo" );

	std::cout << "The size is: " << s.size( ) << std::endl;

	return 0;
}