#include <stdio.h>

int findMax(int *arr,int n){
	int currMax=*arr;
	for(int i=0;i<n;i++){
		if(*(arr+i)>currMax){
			currMax=*(arr+i);
		}
	}
	return(currMax);
}

int recMax(int *arr,int n){
	if(n==1){
		return arr[0];
	}

	int prevMax = recMax(arr,n-1);

	if(arr[n-1]>prevMax){
		return arr[n-1];
	}else{
		return prevMax;
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
	printf("Iteration max: %d",findMax(arr,n));
	printf("\n");
	printf("Recursive max: %d",recMax(arr,n));
	printf("\n");
	return 0;

	


}
