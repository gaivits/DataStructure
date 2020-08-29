#include <iostream>
using namespace std;

struct graph
{
    int node;
    struct graph *next;
};
struct v_dfs
{
    int f;
    int d;
    int pass;
    int pred;
};
int n;
int x;
int time = 1;
struct graph *tail ;
graph *Insert_Graph(int j,struct graph *head)
{
    tail = NULL;
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
void visit(int u,struct v_dfs *arr[],struct graph **adj)
{
    struct graph *pn = adj[u];
    if(pn!=NULL)
    {
        while(pn != NULL)
        {
            if(arr[pn->node]->pass == 0)
            {
                arr[pn->node]->pass = 1;
                arr[pn->node]->pred = u;
                time++;
                arr[pn->node]->d = time ;
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
}
void dfs(struct graph **adj)
{
    struct v_dfs *arr[n];
    struct graph *head = new graph;
    int i = 0;
    while(i<n)
    {
        struct v_dfs *u = new v_dfs;
        u->pass = 0;
        u->pred = -1;
        u->d = -1;
        u->f = -1;
        arr[i] = u;
        i++;
    }
    struct graph *pn = adj[x];
    arr[x]->pass=1;
    arr[x]->pred = x;
    arr[x]->d = 0;
    while(pn != NULL)
    {
        if(arr[pn->node]->pass==0)
        {
            arr[pn->node]->pass = 1;
            arr[pn->node]->pred = x;
            time++;
            arr[pn->node]->d = time;
            visit(pn->node,arr,adj);
        }
        pn = pn->next;
    }
    time++;
    arr[x]->f = time;
    cout<<"   Pass   D    F    Pred"<<endl;
    cout<<"-----------------------------------"<<endl;
    int b = 0;
    while(b<n)
    {
        if(arr[b]->pass == 0)
        {
            cout<<b<<" | ";
            cout<<arr[b]->pass<<"    ";
            cout<<arr[b]->d<<"   ";
            cout<<arr[b]->f<<"    ";
            cout<<arr[b]->pred<<"    ";
            cout<<endl;
        }
        else
        {
            cout<<b<<" | ";
            cout<<arr[b]->pass<<"     ";
            cout<<arr[b]->d<<"    ";
            cout<<arr[b]->f<<"     ";
            cout<<arr[b]->pred<<"     ";
            cout<<endl;
        }
        b++;;
    }
}
void visit_tree(int u,int pass[],struct graph **adj)
{
    struct graph *pn = adj[u];
    if(pn != NULL)
    {
        while(pn != NULL)
        {
            if(pass[pn->node] == 0)
            {
                cout<<"("<<pn->node;
                pass[pn->node]=1;
                visit_tree(pn->node,pass,adj);
            }
            if(pn->next == NULL)
            {
                cout<<u<<")";
            }
            pn = pn->next;
        }
    }
    else if(pn == NULL)
    {
        cout<<u<<")";
    }
    return ;
}
void tree(struct graph **adj)
{
    int pass[n];
    int i = 0;
    while(i<n)
    {
        pass[i]=0;
        i++;
    }
    struct graph *pn = adj[x];
    pass[x] = 1;
    cout<<"("<<x;
    while(pn != NULL)
    {
        if(pass[pn->node] == 0)
        {
            cout<<"("<<pn->node;
            pass[pn->node]=1;
            visit_tree(pn->node,pass,adj);
        }
        if(pn->next == NULL)
        {
            cout<<x<<")";
        }
        pn = pn->next;
    }
    int j = 0;
    while(j<n)
    {
        if(pass[j]==0)
        {
            struct graph *pnn = adj[j];
            pass[j]=1;
            cout<<"("<<j;
            while(pnn != NULL)
            {
                if(pass[pnn->node] == 0)
                {
                    cout<<"("<<pnn->node;
                    pass[pnn->node]=1;
                    visit_tree(pnn->node,pass,adj);
                }
                if(pnn->next == NULL)
                {
                    cout<<j<<")";
                }
                pnn = pnn->next;
            }
        }
        j++;
    }
    cout<<endl;
}
int main()
{
    int number;
    struct graph **adj;
    while(true)
    {
        cout<<"============MENU============="<<endl;
        cout<<"[1]Insert Graph"<<endl;
        cout<<"[2]DFS"<<endl;
        cout<<"[3]Show Tree"<<endl;
        cout<<"[4]EXIT"<<endl;
        cout<<"============================="<<endl;
        cout<<"Please choose > ";
        cin>>number;
        switch (number)
        {
            case 1:
            {
                cout<<"Please input node : ";
                cin>>n;
                adj = new graph *[n];
                int i = 0;
                while(i<n)
                {
                    adj[i] = NULL;
                    i++;
                }
                int j=0;
                while(j<n)
                {
                    adj[j] = Insert_Graph(j,adj[j]);
                    j++;
                }
                cout<<endl;
                break;
            }
            case 2:
            {
                time = 1;
                cout<<"Please input start Vertex : ";
                cin>>x;
                dfs(adj);
                break;
            }
            case 3:
            {
                cout<<"Please input start Vertex : ";
                cin>>x;
                tree(adj);
                break;
            }
            case 4:
            {
                return 0;
            }
            case 5:
            {
                pnt(adj);
                break;
            }
            default :
            {
                cout<<"NOT HAVE FUNCTION!!!"<<endl;
                break;
            }
        }
    }
}
