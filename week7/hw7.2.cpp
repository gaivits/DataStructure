#include <iostream>
using namespace std;

struct graph
{
    int node;
    struct graph *next;
};
struct vs
{
    int pass;
    int f;
};
int time = 0;
int x = 0;
int n;
void visit(int u,struct vs *arr[],graph **adj)
{
    struct graph *pn = adj[u];
    if(pn != NULL)
    {
        while(pn != NULL)
        {
            if(arr[pn->node]->pass == 0)
            {
                arr[pn->node]->pass=1;
                time++;
                visit(pn->node,arr,adj);
            }
            if(pn->next == NULL)
            {
                time++;
                arr[u]->f = time;
            }
            pn = pn->next;
        }
    }
    else if(pn == NULL)
    {
        time++;
        arr[u]->f = time;
    }
    return ;
}
void topological(struct graph **adj)
{
    struct vs *arr[n];
    int i = 0;
    while(i<n)
    {
        struct vs *u = new vs;
        u->pass = 0;
        u->f = -1;
        arr[i] = u;
        i++;
    }
    struct graph *pn = adj[x];
    arr[x]->pass=1;
    while(pn != NULL)
    {
        if(arr[pn->node]->pass==0)
        {
            arr[pn->node]->pass = 1;
            time++;
            visit(pn->node,arr,adj);
        }
        pn = pn->next;
    }
    time++;
    arr[x]->f = time;
    int w = 0;
    while(w<n)
    {
        if(arr[w]->pass==0)
        {
            struct graph *pnn = adj[w];
            arr[w]->pass=1;
            time++;
            while(pnn != NULL)
            {
                if(arr[pnn->node]->pass == 0)
                {
                    time++;
                    arr[pnn->node]->pass=1;
                    visit(pnn->node,arr,adj);
                }
                pnn = pnn->next;
            }
            time ++;
            arr[w]->f = time;
        }
        w++;
    }
    int p = 0;
    while(p<n)
    {
        cout<<" "<<p<<"   |   "<<arr[p]->f<<endl;
        p++;
    }
}
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
void pnt(struct graph **adj)
{
    cout<<"Output"<<endl;
    int x = 0;
    while(x<n)
    {
        cout<<x<<" : ";
        struct graph *pnt = adj[x];
        while(pnt != NULL)
        {
            cout<<(pnt->node)<<" ";
            pnt = pnt->next;
        }
        cout<<endl;
        x++;
    }
}
int main()
{
    struct graph **adj;
    cout<<"Please input Graph"<<endl;
    cout<<"Please input node : ";
    cin>>n;
    adj = new graph *[n];
    int j=0;
    while(j<n)
    {
        adj[j] = NULL;
        j++;
    }
    int i =0;
    while(i<n)
    {
        adj[i]=Insert_Graph(i,adj[i]);
        i++;
    }
    cout<<endl;
    cout<<"NODE | Order"<<endl;
    cout<<"----------------------"<<endl;
    topological(adj);
}
