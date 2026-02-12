//Name: Yashavardhan Rai
//Roll: 2025CSB106
//Problem 4
#include <stdio.h>

int main(){
	int n;
	printf("Enter the number of lines: ");
	scanf("%d",&n);
	//pattern
	int width;
	width=2*n-1;
	for(int i=1;i<n;i++){

		for(int j=width/2-i+1;j>0;j--){
			printf(" ");
		}
		for(int k=0;k<i;k++){
			if(k==0 || k==i-1){
				printf("* ");
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}
	for(int i=0;i<n;i++){
		printf("* ");
	}
	printf("\n");
	return 0;
}
//Time Complexity O(n^2)
