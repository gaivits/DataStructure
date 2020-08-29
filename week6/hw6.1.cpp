#include <iostream>
using namespace std;

struct graph
{
    int node;
    struct graph *next;
};


void DGM(int n)
{
    int m[n][n];
    cout<<"Please input Graph"<<endl;
    int i = 0;
    while(i<n)
    {
        int h = 0;
        while(h<n)
        {
            m[i][h] = 0;
            h++;
        }
        i++;
    }
    int j = 0;
    while(j<n)
    {
        int k;
        cout<<"#"<<j<<" : ";
        cin>>k;
        while(k!=99)
        {
            m[j][k] = 1;
            cin>>k;
        }
        j++;
    }
    int z=0;
    int x=0;
    cout<<"Output"<<endl<<endl;
    cout<<"  ";
    while(x<n)
    {
        cout<<x<<" ";
        x++;
    }
    cout<<endl;
    cout<<"========================="<<endl;
    while(z<n)
    {
        cout<<z<<" ";
        int y=0;
        while(y<n)
        {
            cout<<m[z][y]<<" ";
            y++;
        }
        cout<<endl;
        z++;
    }
}
void DGL(int n)
{
    struct graph *arr[n];
    struct graph *tail = new graph;
    int i = 0;
    while(i<n)
    {
        arr[i] = NULL;
        i++;
    }
    cout<<"Please input Graph"<<endl;
    int j = 0;
    while(j<n)
    {
        struct graph *head = NULL;
        int k;
        cout<<"#"<<j<<" : ";
        cin>>k;
        while(k != 99)
        {
            if(head == NULL)
            {
                head = new graph;
                head->node = k;
                head->next = NULL;
                arr[j] = head;
                tail = head;
            }
            else
            {
                struct graph *tmp = new graph;
                tmp->node = k;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
            }
            cin>>k;
        }
        j++;
    }
    cout<<"Output"<<endl<<endl;
    int x = 0;
    while(x<n)
    {
        cout<<x<<" : ";
        struct graph *pnt = arr[x];
        while(pnt != NULL)
        {
            cout<<pnt->node<<" ";
            pnt = pnt->next;
        }
        cout<<endl;
        x++;
    }
}
void UGM(int n)
{
    int m[n][n];
    cout<<"Please input Graph"<<endl;
    int i = 0;
    while(i<n)
    {
        int h = 0;
        while(h<n)
        {
            m[i][h] = 0;
            h++;
        }
        i++;
    }
    int j = 0;
    while(j<n)
    {
        int k;
        cout<<"#"<<j<<" : ";
        cin>>k;
        while(k!=99)
        {
            m[j][k] = 1;
            cin>>k;
        }
        j++;
    }
    int z=0;
    int x=0;
    cout<<"Output"<<endl<<endl;
    cout<<"  ";
    while(x<n)
    {
        cout<<x<<" ";
        x++;
    }
    cout<<endl;
    cout<<"========================="<<endl;
    while(z<n)
    {
        cout<<z<<" ";
        int y=0;
        while(y<n)
        {
            cout<<m[z][y]<<" ";
            y++;
        }
        cout<<endl;
        z++;
    }
}
void UGL(int n)
{
    struct graph *arr[n];
    struct graph *tail = new graph;
    int i = 0;
    while(i<n)
    {
        arr[i] = NULL;
        i++;
    }
    cout<<"Please input Graph"<<endl;
    int j = 0;
    while(j<n)
    {
        struct graph *head = NULL;
        int k;
        cout<<"#"<<j<<" : ";
        cin>>k;
        while(k != 99)
        {
            if(head == NULL)
            {
                head = new graph;
                head->node = k;
                head->next = NULL;
                arr[j] = head;
                tail = head;
            }
            else
            {
                struct graph *tmp = new graph;
                tmp->node = k;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
            }
            cin>>k;
        }
        j++;
    }
    cout<<"Output"<<endl<<endl;
    int x = 0;
    while(x<n)
    {
        cout<<x<<" : ";
        struct graph *pnt = arr[x];
        while(pnt != NULL)
        {
            cout<<pnt->node<<" ";
            pnt = pnt->next;
        }
        cout<<endl;
        x++;
    }
}
int main()
{
    int number,n;
    while(true)
    {
        cout<<"=============MENU============="<<endl;
        cout<<"[1]Directed Graph  Matrix"<<endl;
        cout<<"[2]Directed Graph Linked List"<<endl;
        cout<<"[3]Undirected Graph Matrix"<<endl;
        cout<<"[4]Undirected Graph Linked List"<<endl;
        cout<<"[5]EXIT"<<endl;
        cout<<"=============================="<<endl;
        cout<<"Please choose : ";
        cin>>number;
        switch(number)
        {
            case 1:
            {
                cout<<"Please input node : ";
                cin>>n;
                DGM(n);
                break;
            }
            case 2:
            {
                cout<<"Please input node : ";
                cin>>n;
                DGL(n);
                break;
            }
            case 3:
            {
                cout<<"Please input node : ";
                cin>>n;
                UGM(n);
                break;
            }
            case 4:
            {
                cout<<"Please input node : ";
                cin>>n;
                UGL(n);
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                cout<<"NOT HAVE FUNCTION!!"<<endl;
            }
        }

    }
}
