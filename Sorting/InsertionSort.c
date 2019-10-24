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

void InsertionSort(int arr[],int size_arr)
{
	int i,j,key;
	for (i=1;i<size_arr;i++)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	
	int Max;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&Max);
	
	
	int arr[Max];
	GenData(arr,Max);
	
	PrintArr(arr,Max);
	
	InsertionSort(arr,Max);
	
	PrintArr(arr,Max);
}