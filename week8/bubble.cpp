#include<iostream>
using namespace std;

int main()
{
    int arr[] = {3,5,9,8,4,7,0,1,2,6};
    int w;
    int x = 0;
    while(x<10)
    {
        int y = x+1;
        int z = arr[x];
        while(y<10)
        {
            if(z>arr[y])
            {
                w = y;
                z = arr[y];
            }
            y++;
        }
        if(z!=arr[x])
        {
            arr[w]=arr[x];
            arr[x]=z;
        }
        int c = 0;
        cout<<"[";
        while(c<10)
        {
            cout<<arr[c]<<",";
            c++;
        }
        cout<<"]"<<endl;
        x++;
    }
}

