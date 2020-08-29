#include<iostream>
using namespace std;
struct graph
{
    int node;
    struct graph *next;
};
int n;
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
void pnt(int p[],int x,int l)
{
    if(p[l] != x)
    {
        pnt(p,x,p[l]);
        cout<<p[l]<<"->";
    }
    else
    {
        cout<<x<<"->";
    }
}
void bfs(struct graph *adj[],int x)
{
    int u[n];
    int p[n];
    int i = 0;
    while(i<n)
    {
        u[i]=0;
        p[i]=-1;
        i++;
    }
    p[x]=x;
    struct graph *head = NULL;
    struct graph *pn = adj[x];
    while(pn != NULL)
    {
        head = Enqueue(head,pn->node);
        u[pn->node]++;
        p[pn->node] = x;
        pn = pn->next;
    }
    struct graph *tmp = head;
    while(tmp != NULL)
    {
        pn = adj[tmp->node];
        while(pn != NULL)
        {
            if(u[pn->node] == 0 && pn->node != x)
            {
                head = Enqueue(head,pn->node);
                p[pn->node] = tmp->node;
                u[pn->node] = u[tmp->node]+1;
            }
            pn = pn->next;
        }
        tmp = tmp->next;
    }
    cout<<endl<<"Distace : "<<endl;
    int b = 0;
    while(b<n)
    {
        cout<<x<<"->"<<b<<"   =   "<<u[b]<<endl;
        b++;
    }
    cout<<endl<<"Output Path : "<<endl;
    int l = 0;
    while(l<n)
    {
        cout<<x<<"->"<<l<<"   =   ";
        if(p[l]==-1)
        {
            cout<<"can't go"<<endl;
            l++;
        }
        else
        {
            pnt(p,x,l);
            cout<<l;
            cout<<endl;
            l++;
        }

    }
    cout<<endl<<endl;
}
int main()
{
    int number;
    struct graph *adj[n];
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
                cout<<"Please input node : ";
                cin>>n;
                struct graph *head = new graph;
                int j=0;
                while(j<n)
                {
                    head = NULL;
                    adj[j] = Insert_Graph(j,head);
                    j++;
                }
                cout<<endl;
                break;
            }
            case 2:
            {
                int x;
                cout<<"Please input start Vertex : ";
                cin>>x;
                bfs(adj,x);
                break;
            }
            case 3:
            {
                return 0;
            }
        }
    }
}
