#include <stdio.h>

void arr_fwd(int *arr,int n){

	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}

void print_rec_fwd(int *arr,int n){

	if(n==0){
		return;
	}
	printf("%d",*arr);
	print_rec_fwd(arr+1,n-1);
	
}

void print_rec_back(int *arr,int n){
	if(n==0){
		return;
	}
	printf("%d",*(arr+n-1));
	print_rec_back(arr,n-1);
	
}

int main(){
	int arr[254];
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nForward traversal: ");
	arr_fwd(arr,n);
	printf("\nForward recursive: ");
	print_rec_fwd(arr,n);
	printf("\nBackward recursive: ");
	print_rec_back(arr,n);
	printf("\n");
	return 0;
}

