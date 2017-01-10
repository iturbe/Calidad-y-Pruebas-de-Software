#include <iostream>

int factorial(int input) {

	if(input < 0) {return 0;}

	if(input == 0) {return 1;}

	return input * factorial(input - 1);
}
