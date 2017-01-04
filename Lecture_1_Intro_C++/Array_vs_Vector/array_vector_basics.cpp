// Array and Vector Examples

#include <iostream>
#include <vector>

int main() {
	
	// Create a integer array of size 10 and initialize it with values.
	// Note: In most cases we do not use array, use vector instead!
	int int_arr[10] = {0,1,2,3,4,5,6,7,8,9};

	// Print the array.
	// Note that we hardcord the length of the array in the for loop.
	// There are ways to get the size, but they are not easy, nor 
	// compatible for all types.
	// THIS IS OLD STYLE!
	std::cout << "int_arr values: ";
	for(int i = 0; i < 10; ++i) {
		std::cout << int_arr[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// Print the array values, and the addresses assoicated with each.
	// C++11 has range based for loops
	std::cout << "Size of integer (bytes): " << sizeof(int) << std::endl;
	std::cout << "int_arr values and addresses: " << std::endl;
	// for(int i = 0; i < 10; ++i) {
	for(const int& i : int_arr) {
		std::cout << i << ": " << &i << std::endl;
	}
	std::cout << std::endl;

	// Create a std::vector and initialize it with values.
	std::vector<int> int_vec = {0,1,2,3,4,5,6,7,8,9};

	// Print the vector values and addresses.
	std::cout << "int_vec values and addresses: " << std::endl;
	for(const auto& i : int_vec) {
		std::cout << i << ": " << &i << std::endl;
	}
	std::cout << std::endl;
}