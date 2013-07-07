/*
 *	Question: The prime factors of 13195 are 5, 7, 13 and 29.
 *	What is the largest prime factor of the number 600851475143?
 *	Base_2: 1000 1011 1110 0101 1000 1001 1110 1010 1100 0111
 *	Author: James Muldoon
 */

 // Header declarations
#include "sll.h"
#include <math.h>

int val = 13195;

// Function prototype declarations
int IsPrime(int);						// Determines if param is prime or not. returns 1 if prime, else 0
SLL *PrimeFactorization(SLL *, int); 	// Determines the prime factors for a give value param: v

int main(int argc, char **argv){
	SLL *list=NULL;

	list = PrimeFactorization(list, val);									// Obtain the prime factors for the value in v.	
	printf("Greatest prime factor of %d, is: %d\n", val, MaxValue(list));	// Display solution

	return 0;
}

SLL *PrimeFactorization(SLL *head, int v){
	SLL *tmp;
	int ch;
	
	for (tmp = head, ch = 2; ch <= (int)sqrt(v); ch++){	// Checks all possibilities for 2 through sqrt(v)		
		if(IsPrime(ch) && (v%ch == 0)){					// is the count prime and % == 0, if so execute the code
			tmp = InsertOrdered(tmp, ch);				// appends to the end of the linked list
			v = v/ch;
			if (IsPrime(v)){							// if this is prime, then v is fully factored
				tmp = InsertOrdered(tmp, v);			// appends to the end of the linked list
				break;
			}
			else										// if not prime, then continue to find the next prime factor
				ch = 1;									// auto increments to 2 at the end of the loop
		}
	}
	return tmp;
}

int IsPrime(int v){
	int ch;
	for (ch = 2; ch <= (int)sqrt(v); ch++)			// Checks all possibilities for 2 through sqrt(v)
		if(v%ch == 0) return 0;						// Not prime
	return 1;										// Exhausted all options. Is prime
}