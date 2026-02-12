#include <stdio.h>

void addElements(int *arr,int n){
	int currSum=0;
	for(int i=0;i<n;i++){
		currSum+=*(arr+i);
	}
	printf("%d",currSum);

}

int rec_add(int *arr,int n){
	
	if(n==0){
		return 0;
	}else{
		return(arr[n-1]+rec_add(arr,n-1));
	}
	

}

int main(){

	int arr[100];
	int n;

	printf("Enter length of array: ");
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	addElements(arr,n);
	printf("\n");
	printf("%d",rec_add(arr,n));
	printf("\n");
	return 0;

	


}
