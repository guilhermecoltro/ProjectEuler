/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <time.h>

const int MAX = 1000;
int multiples();

int main(){
	int begin = clock();
	printf("Result: %d\nRuntime: %dms\n", multiples(), (int) clock()-begin);
	return 0;
}

int multiples(){
	int sum = 0;
	for(int i=0; i<MAX-1 ; i++ && ((i%3 == 0 || i%5 == 0) ? sum += i : sum ) );
	return sum;
}
