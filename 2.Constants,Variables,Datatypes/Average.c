//Fig 2.9 Average of N numbers
//AVERAGE OF n VALUES
#include<stdio.h>
#define N 10

main() 
{
	int count;
	float sum, average, number;
	sum = 0; 
	count = 0;
	while(count < N)
	{
	scanf("%f",&number);
	sum = sum + number;
	count = count + 1;
	}
	average = sum/N;
	printf("N=%d Sum = %f", N, sum); 
	printf(" Average = %f", average);
}
