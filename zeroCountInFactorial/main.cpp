/*
 *  by asem
 *  Copyleft 2018
*/

#include <iostream>
#include <cstdlib>
typedef unsigned long long ull;

ull expCoef(ull n, ull base) {
	ull res = 0;
	while(n) {
		n /= base;
		res += n;
	}
	return res;
}
ull zerosCount(ull n) {
	return std::min(expCoef(n,2), expCoef(n,5));
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
