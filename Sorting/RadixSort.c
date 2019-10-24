// #define Max 10

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

int FindMax(int arr[],int size)
{
	int i;
	int max=arr[0];
	for(i=1;i<size;++i)
		if(arr[i]>max)
			max = arr[i];
	return max;
}

void CountSort(int arr[],int exp,int size_of_array)
{
	int temp_arr[size_of_array];
	int i,count[10];
	for(i=0;i<10;++i)
		count[i] = 0;
	for(i=0;i<size_of_array;++i)
		count[(arr[i]/exp)%10]++;
	for(i=1;i<10;++i)
		count[i] += count[i-1];
	for(i=size_of_array-1;i>=0;--i)
	{
		temp_arr[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i=0;i<size_of_array;++i)
		arr[i] = temp_arr[i];
}

void RadixSort(int arr[],int size)
{
	int max = FindMax(arr,size);
	
	int exp;
	for(exp = 1;(max/exp)>0;exp*=10)
		CountSort(arr,exp,size);
}

int main()
{
	int Max;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&Max);

	srand((unsigned int)time(NULL));
	int arr[Max];
	GenData(arr,Max);
	
	printf("\nUnsorted array: ");
	PrintArr(arr,Max);
	
	RadixSort(arr,Max);
	
	printf("\nSorted array: ");
	PrintArr(arr,Max);
}