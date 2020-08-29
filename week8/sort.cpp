#include<iostream>
#include<fstream>
using namespace std;

void readData(int *arr)
{
    FILE *finput;
    int i=0;
    finput = fopen("data.dat","r");
    if(finput)
    {
        while(!feof(finput))
        {
            fscanf(finput,"%d",&arr[i++]);
        }
        fclose(finput);
    }
    else
    {
        cout<<"[x]Can't open file."<<endl;
    }
}
void writeData(int *arr,char *filename)
{
    FILE *foutput;
    foutput = fopen(filename,"w");
    if(foutput)
    {
        for(int i=0;i<5000000;i++)
        {
            fprintf(foutput,"%d\n",arr[i]);
        }
        fclose(foutput);
    }
    else
    {
        cout<<"[x]Can't open file."<<endl;
    }
}
void bubbleSort(int *arr)
{
    int y = 5000000;
    while(y--)
    {
        int x = 0;
        while(x<4999999)
        {
            if(arr[x]>arr[x+1])
            {
                int i = arr[x];
                int j = arr[x+1];
                arr[x] = j;
                arr[x+1] = i;
            }
            x++;
        }
    }
}
void shellSort(int *arr)
{
    int s = 2500000;
    for(int i=s;i>0;i--)
    {
        for(int j=0;j<5000000;j++)
        {
            int left = j;
            int right = j+i;
            if(right >= 5000000)
            {
                break;
            }
            while(left>=0)
            {
                if(arr[left]>arr[right])
                {
                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                    right = left;
                    left = right-i;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int pickPivot(int *arr,int left,int right){
    int x = arr[left];
    int i = left+1;
    int j = right + 1;
    while(true){
        while(arr[i] < x){
            i++;
            if(i >= right){
                break;
            }
        }
        while(arr[--j] > x){
            if(j <= left){
                break;
            }
        }
        if(i >= j){
            break;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    if(j == left){
        return j;
    }else{
        int temp  = arr[left];
        arr[left] = arr[j];
        arr[j] = temp;
        return j;
    }
}
void quickSort(int *arr,int left,int right){
    if(right > left)
    {
        int p = pickPivot(arr,left,right);
        quickSort(arr,left,p-1);
        quickSort(arr,p+1,right);
    }
}
void mergeSort(int *arr,int *tmparray,int left,int right,int rightend){
    int leftend = right-1;
    int tmppos = left;
    int numberOfElements = rightend - left +1;
    while(left<= leftend && right <= rightend){
        if(arr[left] <= arr[right]){
            tmparray[tmppos++] = arr[left++];
        }else{
            tmparray[tmppos++] = arr[right++];
        }
    }
    while(left <= leftend){
        tmparray[tmppos++] = arr[left++];
    }
    while(right <= rightend){
        tmparray[tmppos++] = arr[right++];
    }
    for(int i=0;i<numberOfElements;i++){
        arr[rightend--] = tmparray[rightend];
    }
}

void mSort(int *arr,int *tmparray,int left,int right){
    if(left < right){
        int center = (left + right)/2;
        mSort(arr,tmparray,left,center);
        mSort(arr,tmparray,center+1,right);
        mergeSort(arr,tmparray,left,center+1,right);
    }
}
void selection(int *arr)
{
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
        x++;
    }
}

int main()
{
    int *arr = new int[5000000];
    int *tmparray;
    int number;
    while(true)
    {
        cout<<"==============MENU=============="<<endl;
        cout<<"[1]Buble Sort"<<endl;
        cout<<"[2]Shell Sort"<<endl;
        cout<<"[3]Quick Sort"<<endl;
        cout<<"[4]Merge Sort"<<endl;
        cout<<"[5]Selection Sort"<<endl;
        cout<<"[6]Radix Sort"<<endl;
        cout<<"[7]Exit"<<endl;
        cout<<"Please choose > ";
        cin>>number;
        switch(number)
        {
            case 1:
            {
                readData(arr);
                bubbleSort(arr);
                writeData(arr,"bubbleSort.dat");
                cout<<endl<<"[!]Bubble Sort... Complete"<<endl;
                break;
            }
            case 2:
            {
                readData(arr);
                shellSort(arr);
                writeData(arr,"shellSort.dat");
                cout<<endl<<"[!]Shell Sort... Complete"<<endl;
                break;
            }
            case 3:
            {
                readData(arr);
                quickSort(arr,0,4999999);
                writeData(arr,"quickSort.dat");
                cout<<endl<<"[!]Quick Sort... Complete"<<endl;
                break;
            }
            case 4:
            {
                readData(arr);
                tmparray = new int[5000000];
                mSort(arr,tmparray,0,4999999);
                writeData(arr,"mergeSort.dat");
                delete[] tmparray;
                cout<<endl<<"[!]Merge Sort... Complete"<<endl;
                break;
            }
            case 5:
            {
                readData(arr);
                selection(arr);
                writeData(arr,"selectionSort.dat");
                cout<<endl<<"[!]Selection Sort... Complete"<<endl;
            }
            case 7:
            {
                return 0;
            }
        }
    }


}

