// #define MAX 15

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void GenData(int arr[],int Max)
{
	int i;
	for(i=0;i<Max;i++)
		scanf("%d",&arr[i]);
}

void PrintArr(int arr[],int size)
{
	int i;
	printf("Array: ");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


void ShellSort(int arr[],int size_arr)
{
	int gap = size_arr/2;
	while(gap > 0)
	{
		int i,j;
		for(i=gap;i<size_arr;i+=1)
		{
			int temp = arr[i];
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
		}
		gap /= 2;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	
	int MAX;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&MAX);
	
	
	int arr[MAX];
	GenData(arr,MAX);
	
	PrintArr(arr,MAX);
	
	ShellSort(arr,MAX);
	
	PrintArr(arr,MAX);
}