#include <stdio.h>

//utils
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");
}

//funcs

int bin_search(int *arr,int n,int k){
	int high=n-1,low=0,mid;
	while(arr[low]<=arr[high]){
		mid=(low+high)/2;
		if(k>arr[mid]){
			low=mid;
		}else if(k<arr[mid]){
			high=mid;
		}else{
			return mid;
		}
	}
	return -1;

}

int rec_search(int *arr,int n, int low, int high, int k){

	int mid=(low+high)/2;
	if(arr[mid]==k){
		return mid;
	}
	if(arr[mid]>k){
		return(rec_search(arr,n,low,mid,k);
	}else if(arr[mid]<k){
		return(rec_search(arr,n,mid,high,k);
	}

}

int main(){
	int arr[254];
	int n,k;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter integer K to find: ");
	scanf("%d",&k);
	
	printf("%d\n",rec_search(arr,n,0,n-1,k));
	return 0;
}

