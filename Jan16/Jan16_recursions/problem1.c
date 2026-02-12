//Name: Yashvardhan Rai
//Roll: 2025CSB106
//Problem 1

#include <stdio.h>

float power(float base,int exp){ //recursive power

	if(exp==0){
		return 1;
	}
	return base*power(base,exp-1);

}

long long polynomial(int x,int y){
	long long result;
	result=(11*power(y,5))-(14*power(x,2)*power(y,3))+(5*power(x,3)*power(y,2))-(6*power(x,4)*y)+(7*power(x,5));
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
