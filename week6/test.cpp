#include<iostream>
using namespace std;
struct graph
{
    int node;
    struct graph *next;
};
int n = 8;
struct graph *tail = NULL;
graph *Insert_Graph(int j,struct graph *head)
{
    struct graph *tail = NULL;
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
    return head;
}

void pnt(struct graph *adj[])
{
    int x = 0;
    while(x<n)
    {
        struct graph *pn = adj[x];
        cout<<x<<" : ";
        while(pn != NULL)
        {
            cout<<pn->node<<" ";
            pn = pn->next;
        }
        cout<<endl;
        x++;
    }
}
struct graph *Enqueue(struct graph *head,int data)
{
    if(head == NULL)
    {
        struct graph *head = new graph;
        head->node = data;
        head->next = NULL;
        tail = head;
        return head;
    }
    else
    {
        struct graph *tmp = new graph;
        tmp->node = data;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
        return head;
    }
}
void bfs(struct graph *adj[],int x)
{
    int u[8] = {0};
    struct graph *head = NULL;
    struct graph *pn = adj[x];
    while(pn != NULL)
    {
        head = Enqueue(head,pn->node);
        pn = pn->next;
    }

    //struct graph *tmp = head;
    //tmp = tmp->next;
    //head = tmp;
    while(head != NULL)
    {
        cout<<head->node<<" ";
        head = head->next;
    }
}
int main()
{
    int number;
    struct graph *adj[n] ;
    while(true)
    {
        cout<<"============BFS============="<<endl;
        cout<<"[1]Insert Graph"<<endl;
        cout<<"[2]BFS"<<endl;
        cout<<"[3]EXIT"<<endl;
        cout<<"============================"<<endl;
        cout<<"Please choose > ";
        cin>>number;
        switch (number)
        {
            case 1:
            {
                struct graph *head = new graph;
                int j=0;
                while(j<n)
                {
                    head = NULL;
                    adj[j] = Insert_Graph(j,head);
                    j++;
                }
                break;
            }
            case 2:
            {
                int x;
                cout<<"Pleas input start Vertex : ";
                cin>>x;
                bfs(adj,x);
                break;
            }
            case 3:
            {
                return 0;
            }
            case 4:
            {
                pnt(adj);
            }
        }
    }
}
