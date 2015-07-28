/**
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

int largest(int digits);
int * eleven_multiples(int from, int to);
int is_palindrome(int n);
int q_multiples(int n, int from, int to);

int main(){
	int begin = clock();
	int digits = 3;
	printf("Result: %d\nRuntime: %dms\n", largest(digits), (int) clock()-begin);
	return 0;
}

int largest(int dig){
	int start = (pow(10, dig-1));
	int stop  = (pow(10, dig)-1);
	int *x;
	int big = -1;
	x = eleven_multiples(start, stop);
	for(int i=0; i<q_multiples(11, start, stop); i++){
		int element = x[i];
		for(int j=start; j<=stop; j++){
			if(is_palindrome(element*j) && element*j > big){
				big = element*j;
			}
		}
	}
	return big;
}

int * eleven_multiples(int from, int to){
	int* x = malloc(256);
	int count = 0;
	for(int i=from, count=0; i<=to; (i%11==0) ? (x[count] = i) && i++ && count++ : i++);
	return x;
}

int is_palindrome(int n){
	if(n%11 != 0) return 0;
	char s[15];
	sprintf(s, "%d", n);
	int str_size = strlen(s);
	int size = (str_size%2==0) ? str_size/2 : (str_size-1)/2 ;
	int retorno = 1;
	for(int i=0;i<size; i++) { 
		if((s[i]!=s[(str_size-1)-i])){
			retorno=0;
			break;
		}
	}
	return retorno;
}

int q_multiples(int n, int from, int to){
	int count = 0;
	for (int i=from; i<=to; (i%n==0) ? i++ && count++ : i++ );
	return count;
}