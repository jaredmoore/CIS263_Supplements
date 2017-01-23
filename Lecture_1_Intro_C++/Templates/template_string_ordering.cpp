/*
	This code from Figure 1.25 of the book illustrates two ways of using 
	function objects to compare strings.  

	Notice that in the first template, we use the comparator isLessThan to compare
	the strings.  By overloading the operator() in class CaseInsensitiveCompare, we 
	are able to clean up the syntax and make the call isLessThan(arr[maxIndex], arr[i])
	work without any member function calling.  Convenient, but maybe not immediately 
	obvious.  

	In the second template, we use the built-in call to std::less to use the Object's 
	default 'less than' operator.  
*/

#include <iostream>
#include <string>
#include <vector>

// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object & findMax( const std::vector<Object> & arr, Comparator isLessThan )
{
	int maxIndex = 0;

	for( int i = 1; i < arr.size( ); ++i )
		if( isLessThan( arr[ maxIndex ], arr[ i ] ) )
			maxIndex = i;

		return arr[ maxIndex ];
	}

// Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object & findMax( const std::vector<Object> & arr )
{
	return findMax( arr, std::less<Object>{ } );
}

class CaseInsensitiveCompare
{
	public:
	bool operator( )( const std::string & lhs, const std::string & rhs ) const
	{ return strcasecmp( lhs.c_str( ), rhs.c_str( ) ) < 0; }
};

int main( )
{
	std::vector<std::string> arr = { "ZEBRA", "alligator", "crocodile" };

	// Print out the contents of the vector.  Since I know it's a basic type just 
	// const is fine.
	std::cout << "The vector is: ";
	for(const auto i: arr) {
		std::cout << i << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Using the default compare operators, " << arr[0] << " > " << arr[1] << " yields: ";
	std::cout << (arr[0] > arr[1]) << std::endl << std::endl;

	std::cout << "Using the CaseInsensitiveCompare class: ";
	std::cout << findMax( arr, CaseInsensitiveCompare{ } ) << std::endl;

	// The built-in less is the same as using the '>' operator.  
	std::cout << "Using the built-in less: "; 
	std::cout << findMax( arr ) << std::endl;

	return 0;
}