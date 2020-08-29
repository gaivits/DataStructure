#include<iostream>
#include<fstream>
#include<assert.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int arr[30],c = 0;

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}

void print()
{
	printf("Now Array: \n");
	for(int i=1;i<=c;i++)
	{
		printf("%d ",arr[i]);
	}
}

void input()
{
	printf("Please enter 10 data\n");
	while(c<10)
	{
		++c;
		cin>>arr[c];
	}
}

void heapify(int arr[30],int i)
{
	int largest;
	int l = left(i);
	int r = right(i);
	if(l<=i&&arr[l]>arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r<=i&&arr[r]>arr[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		heapify(arr,largest);
	}
	else
	{
		while(i>1 and arr[parent(i)]<arr[i])
		{
			int tmp = arr[i];
			arr[i] = arr[parent(i)];
			i = parent(i);
			arr[i] = tmp;
		}
	}
	return ;
}

void heapinsert(int arr[30],int key)
{
	++c;
	int i = c;
	while(i>1 and arr[parent(i)]<key)
	{
		arr[i] = arr[parent(i)];
		i = parent(i);
		arr[i] = key;
	}
}

int main()
{
	for(int i=0;i<30;i++)
	{
		arr[i] = 0;
	}
	while(true)
	{
        printf("=============MENU=================\n");
		printf("1.Input 10 data to array\n");
		printf("2.Heapify\n");
		printf("3.Insert\n");
		printf("4.Exit\n");
		printf("Pleade choose among 1 to 4 > ");
		int choose;
        cin >> choose;
        if(choose>4 or choose<1)
		{
			printf("\nYou must choose among 1 to 4.\n");
			cout<<"Please choose among 1 to 4 > ";
			cin>>choose;
		}
        switch(choose)
		{
        	case 1 :
    		{
    			input();
    			print();
        		break;
    		}
        	case 2 :
    		{
    			heapify(arr,c);
    			print();
        		break;
    		}
        	case 3 :
    		{
    			int data;
    			cin>>data;
				heapinsert(arr,data);
    			print();
        		break;
    		}
        	case 4 :
    		{
				printf("\nExit program.");
				return false ;
        		break ;
    		}
        }
        printf("\n\n\n");
    }
}
