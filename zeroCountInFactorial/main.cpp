/*
 *  by asem
 *  Copyleft 2018
*/

#include <iostream>
#include <cstdlib>
typedef unsigned long long ull;

ull zerosCount(ull n) {
	ull res = 0;
	while(n) {
		n /= 5;
		res += n;
	}
	return res;
}


int main(int argc, char **argv) {
	if(argc != 2) {
		std::cout << "Error, expected one integer argument, get " << argc - 1 << "arguments" << std::endl;
		return 1;
	}
	char *endptr;
	ull n = strtoll(argv[1], &endptr, 10);
	if(*endptr != '\0') {
		std::cout << "Cannot interpret " << argv[1] << " as positive integer" << std::endl;
		return 1;
	}
	std::cout <<  zerosCount(n) << std::endl;
	return 0;
}
