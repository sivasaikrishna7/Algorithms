// #define MAX 100

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

void InsertionSort(int arr[],int start,int end)
{
	int i;
	for(i=start+1;i<=end;i++)
	{
		int j;
		for(j=start;j<i;j++)
		{
			if(arr[j]>arr[i])
			{
				int temp = arr[i];
				int k;
				for(k=i;k>j;k--)
					arr[k] = arr[k-1];
				arr[k] = temp;
				break;
			}
		}
	}
}

void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeByInsertion(int arr[],int left,int right)
{
	if(right-left <= 4)
		InsertionSort(arr,left,right);
	else
	{
		int middle = (right+left)/2;
		
		MergeByInsertion(arr,left,middle);
		MergeByInsertion(arr,middle+1,right);
		
		Merge(arr,left,middle,right);
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
	
	PrintArr(arr,MAX);
	printf("\n\n\n\n");
	
	MergeByInsertion(arr,0,MAX);
	PrintArr(arr,MAX);
}