//jeerayoot senpanich 5630300164
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
    cout<<j<<" : ";
    cin>>k;
    while(cin.get()!= '\n')
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

int main()
{
    int number;
    struct graph **adj;
    while(true)
    {	cout<<"===================="<<endl;
        cout<<"       MENU        "<<endl;
        cout<<"===================="<<endl;
        cout<<"1) Insert Graph"<<endl;
        cout<<"2) DFS"<<endl;
        cout<<"3) Exit"<<endl;
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
                return 0;
            }
            default :
            {
                cout<<"NOT HAVE FUNCTION!!!"<<endl;
                break;
            }
        }
    }
}
