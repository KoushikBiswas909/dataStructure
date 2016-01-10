#include <stdio.h>
#include <stdlib.h>


int sumOfNumbers(int n){
	if(n==0) return 0;
	return n + sumOfNumbers(n-1);
}

int main(){
	printf("Enter a number :");
	int n;
	scanf ("%d",&n);
	printf("%d",n);
	int sum = sumOfNumbers(n);
	printf("\nSum is %d",sum);
	return 0;
}
