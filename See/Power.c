#include <stdio.h>
#include <stdlib.h>


int power(int n, int p){
	if(p==0) return 1;
	if(p%2 ==0){
		int y = power(n, p/2);
		return y*y;
	}
	else{
		return n*power(n,p-1);
	}
	return 0;
}

int main(){
	printf("Enter a number :");
	int n;
	scanf ("%d",&n);
	printf("Enter a power :");
	int p;
	scanf ("%d",&p);
	int sum = power(n,p);
	printf("\nPower is %d",sum);
	return 0;
}
