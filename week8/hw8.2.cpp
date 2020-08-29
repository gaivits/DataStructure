#include<iostream>
#include<fstream>
#include<assert.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<stdlib.h>
using namespace std;
int size=30;
int heap_size=0;
int *dataIn=new int[size];
int *elementdata=new int[size];

void swap(int i,int j)
{
    int t=elementdata[i];
    elementdata[i]=elementdata[j];
    elementdata[j]=t;
}
void print ()
{
    int a=heap_size;
    a+1;
    for(int i=0;i<a;i++)
        cout<<elementdata[i]<<"  ";
}
void fixup(int k)
{
    while(k>0)
    {
         int p=(k-1)/2;
        if(elementdata[p]>elementdata[k]){; break;}
        swap(k,p);
        k=p;
    }
}

void heapInsert(int i)
{
    elementdata[heap_size]=i;
     fixup(heap_size);
     ++heap_size;
}
void input()
{
    cout<<"input data: ";
    for(int i=0;i<10;i++)
    {
        cin>>dataIn[i];
    }
}
void  creat()
{
    for(int i=0;i<10;i++)
    heapInsert(dataIn[i]);
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"==========MENU=========="<<endl;
        cout<<"[1]Input10data"<<endl;
        cout<<"[2]Create heap"<<endl;
        cout<<"[3]Insert"<<endl;
        cout<<"[4]Exit"<<endl;
        cout<<"Please choose >  ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                input();
                break;
            case 2:
                creat();
                print();
                break;
            case 3:
                int a;
                cin>>a;
                heapInsert(a);
                print();
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }
}




