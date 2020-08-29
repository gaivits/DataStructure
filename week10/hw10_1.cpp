// 5630300164 jeerayoot senpanich

#include <stdio.h>
#include <Iostream>
//#include <string.h>
using namespace std;
int a[30];
int heapsize = 0;
int lengrh = 30;

int parents(int i)
{
	return i;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}

void input_Array()
{
	int data;
	for(int i= 1;i<=10;i++)
	{
		heapsize++;
		cin>>data;
		a[i] = data;
	}
}

void print()
{
	for(int i=1;i<=heapsize;i++)
	{
		cout<<a[i]<<" "; 
	}
}
void printSort(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" "; 
	}
}
void printAll()
{
	for(int i=0;i<=heapsize;i++)
	{
		cout<<a[i]<<" "; 
	}
	cout<<endl;
}

void exchange(int i,int largest)
{
	int tmp = a[i];
	a[i] = a[largest];
	a[largest] = tmp;
}
void heapify(int i)
{
	int largest;
	int l=left(i);
	int r=right(i);
	
	if(l<=heapsize && a[l]>a[i])
		largest = l;
	else
		largest = i;
	if(r<=heapsize && a[r]>a[largest])
		largest = r;

	if(largest != i)
	{
		exchange(i,largest);
		heapify(largest);
	}
}

void build_heap()
{
	int largest = heapsize/2;
	for(int i=largest;i>=1;i--)
	{
		heapify(i);	
	}
}

void heapsort()
{
	int n = heapsize,n2=1;
	cout<<"#1)"<<endl;
	build_heap();
	cout<<"Heap : ";
	printSort(n);
	cout<<endl;
	for(int i = heapsize;i>0&&heapsize!=1;i--)
	{
		exchange(1,i);
		cout<<"Sort : ";
		printSort(n);
		cout<<endl;
		heapsize--;
		heapify(1);
		cout<<"#"<<++n2<<")"<<endl;
		cout<<"Heap : ";
		printSort(n);
		cout<<endl;
	}
	cout<<"Sort : ";
	printSort(n);
	cout<<endl;
	heapsize = n;
	
	
}

void heap_insert(int key)
{
	heapsize++;
	int i = heapsize;
	while(i>1 && a[parents(i)]<key)
	{
		a[i] = a[parents(i)];
		i = parents(i);
		a[i] = key;
	}
	cout<<"Insert data = ";
	print();
	cout<<endl;
	build_heap();
	cout<<"Heap        = ";
	print();
	cout<<endl;
}
int heap_exact_max()
{
	if(heapsize<1)
		cout<<"Heap underflow";
	int max = a[1];
	a[1] = a[heapsize];
	heapsize--;
	heapify(1);
	return max;
	
}
int main()
{
	int i;
	int data;
	while(1)
	{
		cout<<"==================="<<endl;
		cout<<"        Menu       "<<endl;
		cout<<"==================="<<endl;
		cout<<"1) Input Array "<<endl;
		cout<<"2) Build Heap "<<endl;
		cout<<"3) Print Heap "<<endl;
		cout<<"4) Heap Sort "<<endl;
		cout<<"5) Insert "<<endl;
		cout<<"6) Priority Queue "<<endl;
		cout<<"7) Exit "<<endl;
		cout<<"Please choose > "<<endl;
		cin>>i;
		switch(i)
		{
			case 1:
			{
				cout<<"Please input : ";
				input_Array();
				break;
			}	
			case 2:
			{
				build_heap();	
				cout<<"Heap = ";
				print();
				cout<<endl;
			break;
			}
			case 3:
			{
				printAll();
				break;
			}
			case 4:
			{
				heapsort();
				break;
			}
			case 5:
			{
				int data;
				cout<<"Enter data : ";
				cin>>data;
				heap_insert(data);		
				break;
			}
			case 6:
			{
				cout<<"Dequeue : "<<heap_exact_max()<<endl;
				break;
			}
			case 7:
			{
				return 0;
				break;
			}
		}
	}
}

