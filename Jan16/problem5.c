//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 5
#include <stdio.h>

int main(){

	int n;
	printf("Enter the number of lines: ");
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		
		for(int j=0;j<i;j++){

			printf("%c",j+65);

		}
		printf("\n");

	}
	return 0;
	

}

//Time Complexity O(n^2)
