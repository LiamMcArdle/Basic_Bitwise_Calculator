#include <iostream>
#include <algorithm> 
#include <string>
#include <chrono>
#include <thread>

int main();
unsigned int AND(unsigned int val1, unsigned int val2);
unsigned int OR(unsigned int val1, unsigned int val2);
unsigned int XOR(unsigned int val1, unsigned int val2);
void result_to_bin(unsigned int result);
void result_to_hex(unsigned int result);

int main() {

	unsigned int stop = 0;
	unsigned int value = 0;
	unsigned int result = 0;

	while (stop == 0) {
		using namespace std::this_thread; // sleep_for, sleep_unt
		using namespace std::chrono; // nanoseconds, system_clock, seconds
						  
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + seconds(1));

		unsigned int val1 = 0;
		unsigned int val2 = 0; 
		std::cout << "Welcome to Bitwise Calculator!\n1.Bitwise AND\n2.Bitwise OR\n3.Bitwise XOR\n4.Display previous result in binary\n5.Display previous result in hexadecimal\n6.Exit"          		  << std::endl;
		std::cout << "Please input a value : ";
		std::cin >> value; 

		if (value == 1) {
			std::cout << "Please input the first value (non-negative) : ";
			std::cin >> val1;
			std::cout << std::endl;
			std::cout << "Please input the second value (non-negative) : ";
			std::cin >> val2;
			std::cout << std::endl;
			std::cout << "The result is : ";
			result = AND(val1, val2);
		} else if (value == 2) {
			std::cout << "Please input the first value (non-negative) : ";
			std::cin >> val1;
			std::cout << std::endl;
			std::cout << "Please input the second value (non-negative) : ";
			std::cin >> val2;
			std::cout << std::endl;
			std::cout << "The result is : ";
			result = OR(val1, val2);
		} else if (value == 3) {
			std::cout << "Please input the first value (non-negative) : ";
                        std::cin >> val1;
                        std::cout << std::endl;
                        std::cout << "Please input the second value (non-negative): ";
			std::cin >> val2;
			std::cout << std::endl;
			std::cout << "\nThe result is : ";
			result = XOR(val1, val2); 
		} else if (value == 4) {
			std::cout << "The result in binary is : 0b";
			if(result == 1) {
				std::cout << 1 << "\n";
			}
		       	result_to_bin(result);
		}else if (value == 5) {
			result_to_hex(result);
		} else if (value == 6) {
			std::cout << "\nThank you, have a nice day.\n" << std::endl;
			stop++;
		} else {
			std::cout << "\nInvalid value entered, please try again." << std::endl;
		}																			  
	}	
}

unsigned int AND(unsigned int val1, unsigned int val2) {
	unsigned int result = (val1 & val2);
	std::cout << result << std::endl;
	std::cout << std::endl;
	return result;
}

unsigned int OR(unsigned int val1, unsigned int val2) {
	unsigned int result = (val1 | val2);
	std::cout << result << std::endl;
	std::cout <<std::endl;
	return result;
}

unsigned int XOR(unsigned int val1, unsigned int val2) {
	unsigned int result = (val1 ^ val2);
	std::cout << result << std::endl;
	std::cout << std::endl;
	return result;
}

void result_to_bin(unsigned int result) {
	if (result / 2 != 0) {
		result_to_bin(result/2);
		std::cout << result % 2;
	} else {
		std::cout << std::endl;
	}
}

void result_to_hex(unsigned int result) {
	int remainder, product = 1;
	std::string hex_dec = "";
	  
	while (result != 0) {
		remainder = result % 16;
		char ch;
		if (remainder >= 10) {
			ch = remainder + 55;
		} else {
			ch = remainder + 48;
		}

		hex_dec += ch;
					    
		result = result / 16;
		product *= 10;
						    }
		std::reverse(hex_dec.begin(), hex_dec.end());
		std::cout << "\nThe result in the hexadecimal form is: 0x" << hex_dec << "\n" << std::endl;
}
