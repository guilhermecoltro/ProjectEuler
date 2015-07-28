/**
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */
#include <stdio.h>
#include <time.h>

const int MAX = 4000000;
int fibo();

int main(){
	int begin = clock();
	printf("Result: %i\nRuntime: %ims\n", fibo(), (int) clock()-begin);
	return 0;
}

int fibo(){
	int sum=0;
	for( int a=1,b=2; (a<MAX && b<MAX);  ( (a > b) ? ((a%2 == 0) ? sum+=a : sum) : ((b%2 == 0) ? sum+=b : sum) ) && ((b > a) ? (a+=b) : (b+=a)) );
	return sum;
}
