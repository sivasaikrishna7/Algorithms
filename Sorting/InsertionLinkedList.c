#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
} LIST;

LIST *InsertList(LIST *head)
{
	LIST *temp = (LIST*)malloc(sizeof(LIST));
	scanf("%d",&(temp->data));
	temp->next = head;
	return temp;
}

void printList(LIST* head)
{
	if(head == NULL)
	{
		printf("\nList is empty.");
		return;
	}
	while(head != NULL)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
}

LIST* Insert(LIST* head,LIST* freelink)
{
	if(freelink == NULL)
		return NULL;
	freelink->next = NULL;
	if(head == NULL)
		return freelink;
	if(head->data > freelink->data)
	{
		freelink->next = head;
		return freelink;
	}
	if(head->next == NULL)
	{
		head->next = freelink;
		return head;
	}
	LIST* current = head;
	while((current->next!=NULL) && (current->next->data < freelink->data))
		current = current->next;
	freelink->next = current->next;
	current->next = freelink;
	return head;
}

LIST* InsertionSort(LIST* head)
{
	LIST* newhead = NULL;
	LIST* next;
	while(head != NULL)
	{
		next = head->next;
		newhead = Insert(newhead,head);
		head = next;
	}
	return newhead;
}

int main()
{
	int size;
	printf("\nEnter the size of the list: ");
	scanf("%d",&size);
	
	
	LIST *head = NULL;
	int i;
	for(i=0;i<size;++i)
		head = InsertList(head);
	
	printf("\nList: ");
	printList(head);
	
	head = InsertionSort(head);
	printf("\nSorted List: ");
	printList(head);
}