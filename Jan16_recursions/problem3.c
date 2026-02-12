//Name: Yashvardhan Rai
//Roll: 2025CSB106
//Problem 3

#include <stdio.h>

float powd(int base, int exp) {
    if (exp == 0)
        return 1;              // base case
    return base * powd(base, exp - 1);
}

long long series(float x1,float x2,int i,int n){
	if(i>n){
		return 0;
	}

	if(i%2==0){
		return -3 * (powd(x1,i)- powd(x2,2*i-1)) + series(x1,x2,i+1,n);
	}else{
		return 2*(powd(x1,i)+powd(x2,2*i-1))+series(x1,x2,i+1,n);
	}

}

int main(){
	int x1,x2,n;
	printf("Enter the number of terms to calculate: ");
	scanf("%d",&n);
	printf("Enter the value of x1: ");
	scanf("%d",&x1);
	printf("Enter the value of x2: ");
	scanf("%d",&x2);

	printf("Value of Series Sum is: %lld\n",series(x1,x2,1,n));
	return 0;
}

//TIME COMPLEXITY : O(n)
