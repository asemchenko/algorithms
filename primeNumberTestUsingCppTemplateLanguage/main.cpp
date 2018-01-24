/* by asem 24.01.18
*  implementation of primality test  
*  written on c++ template language
*  testing is conducted at compile-time
*/

#define NUMBER 5153 // <--- put your number here(number should be greater than 1)


#include <iostream>
using std::cout;
using std::endl;
template<unsigned arg>
bool isZero() {
	return false;
}
template<>
bool isZero<0>() {
	return true;
}
template<unsigned n>
bool isOne() {
	return false;
}
template<>
bool isOne<1>() {
	return true;
}
template<unsigned n, unsigned d>
struct checkPrime {
	static bool m() {
		return !isZero<n%d>() && checkPrime<n,d-1>::m();
	}
};
template<unsigned n>
struct checkPrime<n,1> {
	static bool m() {
		return true;
	}
};
int main() {
#define NUMBER_MINUS_ONE (NUMBER-1)
	cout << "Number "<<NUMBER<< " " << (checkPrime<NUMBER,NUMBER_MINUS_ONE>::m()?"is prime":"is'nt prime") << endl;
}
