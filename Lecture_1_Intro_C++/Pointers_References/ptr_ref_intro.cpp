// Pointer and Reference Examples

#include <iostream>

int main() {
	// Create an integer variable and print the value.
	int i_val = 100;

	std::cout << "Integer Value: " << i_val << std::endl;

	// Create an integer pointer and print its value.
	int* i_ptr = &i_val;

	std::cout << "Integer Points to Address: " << i_ptr << std::endl;
	std::cout << "Pointer's Address: " << &i_ptr << std::endl;

	// Print the value pointed to by the pointer.
	std::cout << "Pointer's Value: " << *i_ptr << std::endl;
}