#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
ull fastPowInMod(ull n, ull p, ull m) {
	// this function calculates pow(n,p)%m
	n %= m;
	ull result = 1;
	while(0 != p) {
		result *= (p&1?n:1); // <-- this line probably can be rewritten without conditional statement
		p >>= 1;
		n *= n;
		result %= m;
		n %= m;
	}
	return result;
}


int main(int argc, char ** argv) {
	if( 4 != argc ) {
		printf("[ ERROR ] expected 3 integer parameters\n");
		return 1;
	}
	ull n = atoll(argv[1]);
	ull p = atoll(argv[2]);
	ull m = atoll(argv[3]);
	printf("%llu\n", fastPowInMod(n, p, m));
	return 0;
}
