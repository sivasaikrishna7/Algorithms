// #define MAX 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArr(int arr[],int Max)
{
	int i;
	for(i=0;i<Max;i++)
		printf("%d ",arr[i]);
}

void GenArr(int arr[],int Max)
{
	int i;
	for(i=0;i<Max;i++)
		scanf("%d",&arr[i]);
}

/*void Swap(int arr[],int i, int j)
{
	arr[i] = arr[j] ^ arr[i];
	arr[j] = arr[j] ^ arr[i];
	arr[i] = arr[j] ^ arr[i];
}*/

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[],int start,int end)
{
	int pivot = arr[end];
	int i = start - 1;
	int j;
	for(j = start;j<=end-1;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			// Swap(arr,i,j);
			Swap(&(arr[i]),&(arr[j]));
		}
	}
	// Swap(arr,i+1,end);
	Swap(&(arr[i+1]),&(arr[end]));
	return i+1;
}

void QuickSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int pivot = Partition(arr,start,end);
		
		QuickSort(arr,start,pivot-1);
		QuickSort(arr,pivot+1,end);
	}
}

int main()
{
	int MAX;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&MAX);

	int arr[MAX];
	srand((unsigned int)time(NULL));
	
	GenArr(arr,MAX);
	
	PrintArr(arr,MAX);
	printf("\n\n\n\n");
	QuickSort(arr,0,MAX-1);
	PrintArr(arr,MAX);
	printf("\n\n\n\n");
}