/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	M3.A4
** File: 	Langston_M3_A4.cpp
** Description: This program finds the mode of an array of numbers.
**              The array is stored in a vector, the program is capable
**              of finding the mode even if the vector values are modified.
**
** Author: 	Mark Langston
** Date: 	02/21/2024
** -------------------------------------------------------------------------**/

#include <iostream> //includes input/output stream header
#include <vector> // includes vector header - easier to handle the array
#include <map> // includes map header - allows for containers of key values etc and used on counter
#include <limits.h> // includes climits header - e.g. INT_MIN

void print_number_table(const std::vector<int>& nums) { // function to print the occurrences of each number in the vector/array
	std::map<int, int> counter; // creates a map named counter to count occurrences

	for (auto i : nums) { // loops through each element of the vector
		++counter[i]; // increments the count for each element
	}

	std::cout << "Number\tOccurences\n"; // makes a table header and then goes to the next line
	for (const auto& entry : counter) { // iterates through each key value pair in the map
		std::cout << entry.first << "\t" << entry.second << std::endl; // prints the number and its occurrences and then goes to the next line
	}
}

int mode(std::vector<int> nums) { // declares mode function that takes vector integers
	std::map<int, int> counter; // creates a map named counter

	for (auto i : nums) { // loops through each element of the vector
		++counter[i]; // increments each element
	}

	int mode_count = INT_MIN; // used to store count of mode, lowest possible integer value
	int mode = INT_MIN; // used to store the mode

	for (auto& k : counter) { // iterates through each key value pair in the map
		if (k.second > mode_count) { // checks if the count of the current number is greater than the current mode count
			mode_count = k.second; // updates the mode count
			mode = k.first; // updates the mode
		}
	}
	return mode; // returns mode to called function
}

int main() { // starts main function of program
	std::vector<int> nums = { 5, 1, 25, 25, 25, 1, 10, 10, 5, 5, 5, 5, 1, 5 }; // initializes vector with name nums

	std::cout << "CSC242 Assignment 4: Provide Functions And Arrays To Perform Data-Related Tasks" << std::endl; // when program executes title of program prints to screen.
	std::cout << "This program finds the mode of an array of numbers." << std::endl << std::endl; // program description
	std::cout << "The array of numbers is:" << std::endl; // introduces array

	for (int i : nums) // loops through each element of the array
		std::cout << "[" << i << "] "; // for each element prints to screen with a space after it and surrounded by square brackets
	std::cout << std::endl << std::endl; // ends 2 lines

	std::cout << "Array Table:" << std::endl; // prints a header for the array table
	print_number_table(nums); // calls the function to print the number table

	std::cout << std::endl << std::endl << "The most occurred number(mode) in the array: " << mode(nums) << std::endl; // prints out the mode of the array

	return 0; // returns 0 to main function and ends program
}