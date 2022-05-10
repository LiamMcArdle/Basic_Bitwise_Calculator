#include <iostream>
#include <algorithm> 
#include <string>

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
		unsigned int val1 = 0;
		unsigned int val2 = 0; 
		std::cout << "Welcome to Bitwise Calculator!\n1.Bitwise AND\n2.Bitwise OR\n3.Bitwise XOR\n4.Display previous result in binary\n5.Display previous result in Hexadecimal\n6.Exit"          		  << std::endl;
		std::cout << "Please input a value : ";
		std::cin >> value; 

		if (value == 1) {
			std::cout << "Please input the first value (non-negative) : ";
			std::cin >> val1;
			std::cout << std::endl;
			std::cout << "Please input the second value (non-negative) : ";
			std::cin >> val2;
			std::cout << std::endl;
			result = AND(val1, val2);
		} else if (value == 2) {
			std::cout << "Please input the first value (non-negative) : ";
			std::cin >> val1;
			std::cout << std::endl;
			std::cout << "Please input the second value (non-negative) : ";
			std::cin >> val2;
			std::cout << std::endl;
			result = OR(val1, val2);
		} else if (value == 3) {
			std::cout << "Please input the first value (non-negative) : ";
                        std::cin >> val1;
                        std::cout << std::endl;
                        std::cout << "Please input the second value (non-negative): ";
			std::cin >> val2;
			std::cout << std::endl;
			result = XOR(val1, val2); 
		} else if (value == 4) {
			std::cout << "The result in binary is : ";
			result_to_bin(result);
		}else if (value == 5) {
			result_to_hex(result);
		} else if (value == 6) {
			std::cout << "Thank you, have a nice day." << std::endl;
			stop++;
		} else {
			std::cout << "Invalid value entered, please try again." << std::endl;
		}																			  
	}	
}

unsigned int AND(unsigned int val1, unsigned int val2) {
	unsigned int result = (val1 & val2);
	std::cout << result << std::endl;
	return result;
}

unsigned int OR(int val1, int val2) {
	unsigned int result = (val1 | val2);
	std::cout << result << std::endl;
	return result;
}

unsigned int XOR(unsigned int val1, unsigned int val2) {
	unsigned int result = (val1 ^ val2);
	std::cout << result << std::endl;
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
		std::cout << "The result in the hexadecimal form is: " << hex_dec << std::endl;
}
