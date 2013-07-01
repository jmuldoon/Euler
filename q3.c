/*
 *	Question: The prime factors of 13195 are 5, 7, 13 and 29.
 *	What is the largest prime factor of the number 600851475143?
 *	Author: James Muldoon
 */

 // Header declarations
#include <stdio.h>
#include <cmath.h>
#define VAL 600851475143;

// Global variable declarations
int *pf;	// prime factor array

// Function prototype declarations
int IsPrime(int);				// Determines if param is prime or not. returns 1 if prime, else 0
int* PrimeFactorization(int); 	// Determines the prime factors for a give value param: v
int GPF(int*);					// Calculates the greatest prime factor (GPF)

int main(int argc, char **argv){
	v = VAL;
	
	pf = (int*)malloc((sqrt(v)/2)); // Allocates 1/2 the sqrt of v to the array of prime factors.
	pf = PrimeFactorization(v);		// Obtain the prime factors for the value in v.
	printf("Greatest prime factor of %d, is: %d", v, GPF());	// Display solution
	
	return 0;
}

int* PrimeFactorization(int v){
	int ch, *pfArray;
	
	for (ch = 2; ch <= (int)sqrt(v); ch++){	// Checks all possibilities for 2 through sqrt(v)
		if(IsPrime(ch)){			// is the count prime, if so execute the code
			if(v%ch == 0){			// if the count goes in evenly to the current value
				pfArray[cntr++] = ch;
				v = v/ch;
				if (IsPrime(v)){	// if this is prime, then v is fully factored
					pfArray[cntr++] = v;
					return pfArray;
				}
				else				// if not prime, then continue to find the next prime factor
					ch = 1;			// auto increments to 2 at the end of the loop
			}
		}
	}
}

int GPF(int *p){
	int i, max;

	if((sizeof(p)/sizeof(int))<=1) // if the size of the array is !larger than 1 prime factor
		return p[0];
	
	max = p[0];
	for (i = 0; i < sizeof(p)/sizeof(int); i++)	// Checks for all values in the array
		max = fmax(max, p[i+1]);				// keeps only the max value
	return max;
}

int IsPrime(int v){
	int ch;
	for (ch = 2; ch <= (int)sqrt(v); ch++)	// Checks all possibilities for 2 through sqrt(v)
		if(v%ch == 0) return 0;				// Not prime
	if(ch==v) return 1;						// Exhausted all options. Is prime
}