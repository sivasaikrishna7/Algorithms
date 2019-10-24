// #define Max 10

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int MaxLenght(int Max,char arr[][Max])
{
	int l = strlen(arr[0]);
	int i;
	for(i=1;i<Max;++i)
		if(l<strlen(arr[i]))
			l = strlen(arr[i]);
	return l;
}

void RadixSortStrings(int Max,char arr[][Max],int m_len)
{
	int i,j,k;
	for(i=m_len;i>=0;--i)
	{
		for(j=0;j<Max-1;++j)
		{
			int min = j;
			for(k=j+1;k<Max;++k)
			{
				if(arr[j][i]>arr[k][i])
				{
					char temp[Max];
					strcpy(temp,arr[j]);
					strcpy(arr[j],arr[k]);
					strcpy(arr[k],temp);
				}
			}
		}
	}
}

void Print2DArr(int Max,char arr[][Max])
{
	int i;
	for(i=0;i<Max;++i)
		printf("\n%s",arr[i]);
}

int main()
{
	int Max = 7;
	
	char arr[6][7] = {"ryan","game","hello","nigga","abcde","ABCD"};
	int m_len = MaxLenght(Max,arr);
	
	printf("%d\n",m_len);
	
	printf("\nUnsorted strings: ");
	Print2DArr(Max,arr);
	
	RadixSortStrings(Max,arr,m_len);
	printf("\nSorted strings: ");
	Print2DArr(Max,arr);
}