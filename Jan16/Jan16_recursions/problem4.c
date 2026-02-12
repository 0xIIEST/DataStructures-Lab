//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 4
#include <stdio.h>

void spaces(int n){
	if(n==0){
		return;
	}
	printf(" ");
	spaces(n-1);
}

void stars(int n){
	if(n==0){
		return;
	}
	printf("* ");
	stars(n-1);
}

void triangle(int i,int n){
	if(i>n){
		return;
	}

	spaces(n-i);
	stars(i);
	printf("\n");

	triangle(i+1,n);

}

int main(){
	int n;
	printf("Enter the number of lines: ");
	scanf("%d",&n);
	//pattern
	
	triangle(1,n);
	return 0;
}

//Time Complexity O(n^2)
