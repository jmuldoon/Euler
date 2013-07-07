/*
 *	Question: By considering the terms in the Fibonacci sequence 
 *            whose values do not exceed four million, find the sum of the 
 *            even-valued terms.
 *	Author: James Muldoon
 */
#include <stdio.h>

int i = 2, n = 0, sum = 0;

void fibonacci(int n1, int n2);

int main(int argc, char **argv){
	int n1 = 2, n2 = 1;
	fibonacci(n1,n2);
	//add in 2 for the the second term
	printf("Sum of even-valued terms: %d\n", sum+2);
	return 0;
}

void fibonacci(int n1, int n2){	
	if((n1+n2) <= 4000000){
		n = n1+n2;
		printf("f%d: %d = %d + %d\n", ++i, n, n1, n2);
		
		if (n%2 == 0)
			sum+=n;	
			
		fibonacci(n,n1);
	}
}