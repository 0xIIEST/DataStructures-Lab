

//Name: Yashvardhan Rai
//Roll: 2025CSB106
//Problem 2
#include <stdio.h>
int GP(int x){
	if(x>=40){
		return((x/10)+1);
	}else{
		return 0;
	}
}
void askSGP(int i, float *numerator, float *denominator) {
    int tempM = 0;
    int tempC = 0;
    if (i > 3)
        return;

    printf("Enter percentage in paper %d: ", i);
    scanf("%d", &tempM);

    printf("Enter credit of paper %d: ", i);
    scanf("%d", &tempC);

    *numerator += GP(tempM) * tempC;
    *denominator += tempC;

    // recursive call (i++)
    askSGP(i + 1, numerator, denominator);
}


int main(){
	int n;
	printf("Enter the number of semesters: ");
	scanf("%d",&n);
	
	float preCgpa=0;
	float preCredits=0;
	if(n!=1){
		printf("Enter CGPA upto %d semester: ",n-1);
		scanf("%f",&preCgpa);
		printf("Enter Credits cleared upto %d semester: ",n-1);
		scanf("%f",&preCredits);
	}
	
	printf("---For Current semester---  \n\n");

	float numerator=0,denominator=0;
	float SGPA=0;

	askSGP(1, &numerator, &denominator);//no need, forced recursion :(

	
	SGPA=(float)numerator/(float)denominator;
	float CGPA;
	CGPA=((preCgpa * preCredits) + (SGPA * denominator))/(float)(preCredits+denominator);

	printf("Calculated CGPA= %f\n",CGPA);

	return 0;

}

//TIME COMPLEXITY: O(1)
