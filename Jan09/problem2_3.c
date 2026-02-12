#include <stdio.h>

//funcs

void verify(int *arr,int n){
	int flag=1;
	for(int i=0;i<n/2;i++){
		if(arr[i]!=arr[n-i-1]){
			flag=-1;
		}
	}
	if(flag==-1){
		printf("Is palindromic");
	}else{
		printf("Is not a palindrome");
	}
}
void rec_verify(int *arr,int n,int current_index){
	if(current_index==n/2){
		if(arr[current_index]!=arr[n-current_index-1]){
			printf("Not palindrome\n");
			return;
		}
	}
	rec_verify(arr,n-2,current_index+1);
}

int main(){
	int arr[254];
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	rec_verify(arr,n,0);
	return 0;
}

