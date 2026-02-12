//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 6
#include <stdio.h>

void fwd(int i, int n){
	if(i>n){
		return;
	}

	printf("%c",i+'A');
	fwd(i+1,n);
}

void bck(int i){
	if(i<0){return;}
	printf("%c",i+'A');
	bck(i-1);
}

int main(){
	char c;
	printf("Enter the charecter upto print: ");
	scanf("%c",&c);
	getchar();

	//lower -> upper
	if((int)c>=97 && (int)c <=122){
		c-=32;
	}

	int midIndex;
	midIndex=(int)(c-'A');
	
	fwd(0,midIndex);
	bck(midIndex-1);
	printf("\n");
	return 0;
}

//Time Complexity: O(n)
