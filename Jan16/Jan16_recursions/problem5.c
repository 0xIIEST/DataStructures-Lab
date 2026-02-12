//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 5
#include <stdio.h>

void prnt(int j,int lim){
	if(j==lim){
		return;
	}

	printf("%c",j+65);
	prnt(j+1,lim);
}

void pattern(int i,int n){
    if (i>n){
        return;
	}
    prnt(0,i);
    printf("\n");
    pattern(i+1,n);
}

int main(){

	int n;
	printf("Enter the number of lines: ");
	scanf("%d",&n);

	pattern(1,n);
	return 0;
}

//Time Complexity O(n^2)
