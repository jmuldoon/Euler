/*
 *	Question: Add all the natural numbers below one 
 *  thousand that are multiples of 3 or 5.
 *	Author: James Muldoon
 */
#include <stdio.h>

int function();

int main(int argc, char **argv){
	printf("%d\n", function());
	return 0;
}

int function(){
	int sum = 0, i;
	
	for (i=1; i<1000; i++){
		if(i%3 == 0 || i%5 == 0){
			sum += i;
		}
	}
	return sum;
}