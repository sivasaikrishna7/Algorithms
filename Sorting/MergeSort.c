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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
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


    mergeSort(arr, 0, MAX-1);
 
    printf("\nSorted array is \n");
    PrintArr(arr,MAX);
	return 0;
	
}