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

void GenData(int arr[],int Max)
{
	int i;
	for(i=0;i<Max;i++)
		scanf("%d",&arr[i]);
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void mergeInPlace(int arr[], int l, int m, int r)
{
	int i,j;
	for(i=r;i>m;i--)
	{
		if(arr[i]>arr[m])
			continue;
		Swap(&arr[i],&arr[m]);
		int temp = arr[m];
		for(j=m-1;(j>=l) && (arr[j]>temp);j--)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
	// printf("\n\n");
	// PrintArr(arr);
}
 
void mergeSortInPlace(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        
        mergeSortInPlace(arr, l, m);
        mergeSortInPlace(arr, m+1, r);
 
        mergeInPlace(arr, l, m, r);
    }
}
 
int main()
{
	int MAX;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&MAX);

	int arr[MAX];
	srand((unsigned int)time(NULL));
	GenData(arr,MAX);
	printf("\nUnsorted data: ");
	PrintArr(arr,MAX);


    mergeSortInPlace(arr, 0, MAX-1);
 
    printf("\nSorted array is ");
    PrintArr(arr,MAX);
	return 0;
	
}