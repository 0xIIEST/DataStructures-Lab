#include <stdio.h>

int countK(int *arr,int n,int k){
	int counter=0;
	for(int i=0;i<n;i++){
		if(arr[i]==k){
			counter++;
		}
	}
	return counter;
}

int rec_countK(int *arr,int n,int k){
	
	if(n==0){
		return 0;
	}
	if(arr[n-1]==k){
		return(1+rec_countK(arr,n-1,k));
	}else{
		return(rec_countK(arr,n-1,k));
	}

}

int main(){

	int arr[100];
	int n,k;

	printf("Enter length of array: ");
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Enter the number K to find: ");
	scanf("%d",&k);

	printf("Iteration search: %d",countK(arr,n,k));
	printf("\n");
	printf("Recursive search: %d",rec_countK(arr,n,k));
	printf("\n");
	return 0;

	


}
