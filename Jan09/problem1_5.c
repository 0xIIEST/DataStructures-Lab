#include <stdio.h>

int searchK(int *arr,int n,int k){
	int location=0;
	for(int i=0;i<n;i++){
		if(arr[i]==k){
			location=i;
			break;
		}
	}
	return location;
}

int rec_searchK(int *arr,int n,int k,int current_index){
	
	if(current_index==n){//failiure to find basecase
		return -1;
	}

	if(arr[current_index]==k){//succesfull find
		return current_index;
	}else{
		return(rec_searchK(arr,n,k,current_index+1));
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

	printf("Iteration search: %d",searchK(arr,n,k));
	printf("\n");
	printf("Recursive search: %d",rec_searchK(arr,n,k,0));
	printf("\n");
	return 0;

	


}
