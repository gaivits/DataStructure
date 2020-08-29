#include<iostream>
using namespace std;
struct graph
{
    int node;
    struct graph *next;
};

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
void pnt(struct graph *adj[],int n)
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
int main()
{
    int number,n;
    cout<<"Please input node : ";
    cin>>n;
    struct graph *head = new graph;
    struct graph *adj[n];
    int j=0;
    while(j<n)
    {
        head = NULL;
        adj[j] = Insert_Graph(j,head);
        j++;
    }
    pnt(adj,n);
}


