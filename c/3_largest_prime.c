/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <time.h>
#include <math.h>

int largest(long int n);
int isPrime(long int n);

int main(){
	int begin = clock();
	long int n = 600851475143;
	printf("Result: %d\nRuntime: %dms\n", largest(n), (int) (clock()-begin)/1000);
	return 0;
}

int largest(long int n){
	if(isPrime(n) == 1) return n;
	long int root = (long int) sqrt(n);
	long int largest = 1;
	for( long int i=2; (i<=root) ; (( isPrime(i)==1 && n%i==0) ? ((largest=i) && (i++)) : i++) );
	return largest;
}

/**
* Return = 1 - Is Prime
* Return = 0 - Isn't Prime
*/
int isPrime(long int n){
	int result = 1;
	long int v = (long int) sqrt(n);
	for( long int i=2; (i<=v && result!=0) ; ((n%i== 0) ? (result = 0) : i++) );
	return result;
}
