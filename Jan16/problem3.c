//Name: Yashvardhan Rai
//Roll: 2025CSB106
//Problem 3

#include <stdio.h>

float powd(float base, int exp){

	float result=base;

	for(int i=1;i<exp;i++){
		result*=base;
	}
	return result;
}

long long series(float x1,float x2,int n){
	long long res=0;
	
	for(int i=i;i<=n;i++){
		if(i%2==0){
			res-=3*(powd(x1,i)-powd(x2,2*i-1));
		}else{
			res+=2*(powd(x1,i)+powd(x2,(2*i)-1));
		}
	}

	return res;

}

int main(){
	int x1,x2,n;
	printf("Enter the number of terms to calculate: ");
	scanf("%d",&n);
	printf("Enter the value of x1: ");
	scanf("%d",&x1);
	printf("Enter the value of x2: ");
	scanf("%d",&x2);

	printf("Value of Series Sum is: %lld\n",series(x1,x2,n));
	return 0;
}

//TIME COMPLEXITY : O(n)
