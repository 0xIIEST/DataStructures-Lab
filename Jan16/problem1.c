//Name: Yashvardhan Rai
//Roll: 2025CSB106
//Problem 1

#include <stdio.h>

long long polynomial(int x,int y){
	long long result;
	result=(11*y*y*y*y*y)-(14*x*x*y*y*y)+(5*x*x*x*y*y)-(6*x*x*x*x*y)+(7*x*x*x*x*x);
	return result;
}

int main(){
	int x,y;
	printf("Enter the value of x: ");
	scanf("%d",&x);
	printf("Enter the value of y: ");
	scanf("%d",&y);

	printf("Evaluated function value is: %lld\n",polynomial(x,y));
	return 0;
}

//Time Complexity O(1)
