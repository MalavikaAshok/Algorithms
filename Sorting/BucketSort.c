// #define Max 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct list
{
	int data;
	struct list *next;
} LIST;

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

LIST *InsertList(LIST *head,int num)
{
	LIST *temp = (LIST*)malloc(sizeof(LIST));
	temp->data = num;
	temp->next = NULL;
	
	if(head == NULL)
		return temp;
	if(head->next == NULL)
	{
		if(head->data > temp->data)
		{
			temp->next = head;
			return temp;
		}
		else
		{
			head->next = temp;
			return head;
		}
	}
	if(head->data > temp->data)
	{
		temp->next = head;
		return temp;
	}
	LIST* current = head;
	while(current->next != NULL && current->next->data < temp->data)
		current = current->next;
	temp->next = current->next;
	current->next = temp;
	return head;
	
}

void PrintList(LIST* head)
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

int main()
{
	int Max;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&Max);

	srand((unsigned int)time(NULL));
	int arr[Max];
	GenData(arr,Max);
	
	printf("\nArray before sorting: ");
	PrintArr(arr,Max);
	
	LIST* buckets[10];
	int i;
	for(i=0;i<10;++i)
		buckets[i] = NULL;
	for(i=0;i<Max;++i)
		buckets[(arr[i])/100] = InsertList(buckets[(arr[i])/100],arr[i]);
	
	int j = 0;
	LIST* temp;
	for(i=0;i<10;++i)
	{
		temp = buckets[i];
		while(temp!=NULL)
		{
			arr[j] = temp->data;
			temp = temp->next;
			++j;
		}
	}
	printf("\nArray after sorting: ");
	PrintArr(arr,Max);
}