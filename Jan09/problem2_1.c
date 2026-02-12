#include <stdio.h>

//utils
void swap(int *a,int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");
}

//funcs

void reverse(int *arr,int n){
	for(int i=0;i<n/2;i++){
		swap(arr+i,arr+n-i-1);
	}
}

void rec_reverse(int *arr,int n,int current_index){
	if(current_index==n/2){
		return;
	}else{
		rec_reverse(arr,n,current_index+1);
		swap(arr+current_index,arr+n-current_index-1);
	}
	

}

int main(){
	int arr[254];
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	display(arr,n);
	rec_reverse(arr,n,0);
	printf("Recursive reversed: ");
	display(arr,n);
	rec_reverse(arr,n,0); //re-straighten the array
	reverse(arr,n);
	printf("Iterative reverse: ");
	display(arr,n);
	return 0;
}

