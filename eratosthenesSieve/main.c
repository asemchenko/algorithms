/*
 *  by asem, 2018
 *
 *  Utility for getting list of prime numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void *checkAllocatedMemory(void *p) {
	if(!p) {
		fprintf(stderr,"Error: out of memory.\n");
		exit(1);	
	}
	return p;
}
typedef unsigned long long ull;
typedef uint8_t byte;
ull* getPrimeNumbers(ull n, ull *count) {
	if(n < 2) {
		*count = 0;
		return 0;
	}
	// if nonprimes[i] == false then number i is prime
	// i use false instead of true because calloc returns
	// zero-initialized array, so if we use true as indicator
	// of prime number we should firstly initialize array
	// by true after memory allocation
	byte *nonprime = (byte*)checkAllocatedMemory(calloc(n+1, sizeof(byte)));
	// searching prime numbers
	ull countPrime = 0; 
	for(ull i = 2; i <= n; ++i) {
		if(!nonprime[i]) {
			++countPrime;
			for(ull j = i*i; j <= n; j+=i) {
				nonprime[j] = 1;
			}
		}
	}
	// getting prime numbers and putting it to array
	ull *primeNumbers = (ull*)checkAllocatedMemory(calloc(countPrime, sizeof(ull)));
	ull curPos = 0;
	for(ull i = 2; i <=n; ++i) {
		if(!nonprime[i]) {
			primeNumbers[curPos++] = i;
		}
	}
	*count = countPrime;
	free(nonprime);
	return primeNumbers;
}

int main(int argc, char **argv) {
	// reading arguments
	ull n;
	FILE *outputStream = stdout;
	switch(argc) {
		case 3:
			outputStream = fopen(argv[2], "w");
			if(0 == outputStream) {
				fprintf(stderr, "Can not open file %s\n", argv[2]);
				exit(1);
			}
		case 2:
			n = atoll(argv[1]);
			break;
		default:
			fprintf(stderr, "Expected one or two arguments, get: %d\n. Usage: primes N [filename]\n", argc - 1);
			exit(1);
	}
	// calculation prime numbers which <= n
	ull count;
	ull *primes = getPrimeNumbers(n, &count);
	// pretty printing result
	if(count) {
		fprintf(outputStream, "%llu", primes[0]);
	}
	for(ull i = 1; i < count; ++i) {
		fprintf(outputStream, ",%llu", primes[i]);
	}
	fprintf(outputStream, "\nTotal: %llu", count);
	if(stdout == outputStream) fprintf(outputStream, "\n");
	// programm epilog(release of resources)
	free(primes);
	fclose(outputStream);
	return 0;
}
