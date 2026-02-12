#include <stdio.h>

int main(){
	int m1,n1,m2,n2;	
	printf("For the Image matrix: \n");
	printf("Enter the number of rows: ");
	scanf("%d",&m1);
	printf("Enter the number of columns: ");
	scanf("%d",&n1);

	printf("For the Transform matrix: \n");
	printf("Enter the number of rows: ");
	scanf("%d",&m2);
	printf("Enter the number of columns: ");
	scanf("%d",&n2);

	//Validate Dimensions for multiplication
	
	if(m1==n2 && n1==m2){
		printf("Valid Dimensions.. Proceed\n");
	}else{
		printf("Invalid Dimensions for Multiplication!");
		return 0;
	}

	//INputting the matrice
	
	int image[m1][n1];
	for(int i=0;i<m1;i++){

		for(int j=0;j<n1;j++){

			printf("Enter element at [%d], [%d]: ",i,j);
			scanf("%d",&image[i][j]);

		}

	}

	printf("Image Matrice read sucessfully, now for Transformation Matrice:");

	//Inputting the Transformation matrice
	int transform[m2][n2];
	for(int i=0;i<m2;i++){

		for(int j=0;j<n2;j++){
			printf("Enter element at [%d], [%d]: ",i,j);
			scanf("%d",&transform[i][j]);
		}

	}

	//Multiplying
	
	int outputMatrice[m1][n2];

	for(int i=0;i<m1;i++){

		for(int j=0;j<n2;j++){

			int tempSum=0;
			for(int k=0;k<n1;k++){
				tempSum+=image[i][k] * transform[k][j];
			}

			outputMatrice[i][j]=tempSum;
			
		}

	}

	//Display
	
	for(int i=0;i<m1;i++){

		for(int j=0;j<n2;j++){
			
			printf("%d ",outputMatrice[i][j]);

		}
		printf("\n");

	}
	
	return 0;

}
