//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 6
#include <stdio.h>
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
	for(int i=0;i<=midIndex;i++){
		printf("%c",i+'A');
	}
	for(int i=midIndex-1;i>=0;i--){

		printf("%c",i+'A');

	}
	printf("\n");
	return 0;
}

//Time Complexity: O(n)
