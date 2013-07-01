/*
 *	Question: The prime factors of 13195 are 5, 7, 13 and 29.
 *	What is the largest prime factor of the number 600851475143?
 *	Base_2: 1000 1011 1110 0101 1000 1001 1110 1010 1100 0111
 *	Author: James Muldoon
 */

 // Header declarations
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int val = 13195;

// Function prototype declarations
int IsPrime(int);				// Determines if param is prime or not. returns 1 if prime, else 0
int* PrimeFactorization(int, int *); 	// Determines the prime factors for a give value param: v
int GPF(int *);					// Calculates the greatest prime factor (GPF)

int main(int argc, char **argv){
	int v;	
	v = val;
	int a[4];
	
	PrimeFactorization(v, a);	// Obtain the prime factors for the value in v.
	int i;
	for (i = 0; i<sizeof(a)/sizeof(int); i++)
		printf("%d\n",a[i]);
	
	printf("Greatest prime factor of %d, is: %d\n", v, GPF(a));	// Display solution

	return 0;
}

int* PrimeFactorization(int v, int *array){
	int ch, i;

	for (ch = 2, i = 0; ch <= (int)sqrt(v); ch++){	// Checks all possibilities for 2 through sqrt(v)		
		if(IsPrime(ch) && (v%ch == 0)){	// is the count prime and % == 0, if so execute the code
			array[i++] = ch;
			v = v/ch;
			if (IsPrime(v)){			// if this is prime, then v is fully factored
				array[i] = v;
				break;
			}
			else						// if not prime, then continue to find the next prime factor
				ch = 1;					// auto increments to 2 at the end of the loop
		}
	}
}

int GPF(int *array){
	int i, max;
	for (i = 0; i <= sizeof(array)/sizeof(int); i++)	// Checks for all values in the array
		max = fmax(max, array[i+1]);					// keeps only the max value
	return max;
}

int IsPrime(int v){
	int ch;
	for (ch = 2; ch <= (int)sqrt(v); ch++)	// Checks all possibilities for 2 through sqrt(v)
		if(v%ch == 0) return 0;				// Not prime
	return 1;								// Exhausted all options. Is prime
}