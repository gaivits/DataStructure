#include<iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &v, int i);
int main()
{
int Arr[10]={2,4,5,8,10,47,9,23,44,6};
 vector<int> A(Arr, Arr+10);
 heapify(A, 0);
 for(int i=0; i<9; i++)
 cout<<A[i]<<" ";
 cout<<endl;
}
void heapify(vector<int> &v, int i)
{
	int left=2*i+1, right=2*i+2, largest=i, temp;

	 if(left < v.size() && v[largest] < v[left])
	 largest = left;
	if(right < v.size() && v[largest] < v[right])
	 largest = right;
	if( i != largest)
 	{
	 temp = v[i];
	 v[i] = v[largest];
	 v[largest] = temp;
	 heapify(v, largest);
	}
}
