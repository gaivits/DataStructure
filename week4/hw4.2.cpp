#include<iostream>

using namespace std;
struct jo
{
    int value ;
    struct jo *next;
    struct jo *prev;
};
int main()
{
    int m,n,o;
    while(m != 0)
    {
        cout<<"INPUT M : ";
        cin>>m;
        if(m != 0)
        {
            cout<<"INPUT N : ";
            cin>>n;
            struct jo *head = NULL ;
            struct jo *tail = NULL ;
            struct jo *tmp ;
            o = m;
            while(o > 0)
            {
                if(head == NULL)
                {
                tmp = new jo;
                tmp->value = o;
                tmp->next = NULL;
                tmp->prev = NULL;
                head = tmp;
                tail = head;
                o--;
                }
                else
                {
                    tmp = new jo;
                    tmp->value = o;
                    tmp->prev = NULL;
                    head->prev = tmp;
                    tmp->next = head;
                    head = tmp;
                    o--;
                }
            }
            tail->next=head;
            head->prev=tail;
            int i=1;
            int c=0;
            tmp = head;
            while(tmp->next != NULL)
            {
                struct jo *free = tmp;
                if(i == n)
                {
                    cout<<"PLAYER "<<tmp->value<<" DIE."<<endl;
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                    tmp = tmp->next;
                    delete(free);
                    c=c+1;
                    i=1;
                    if(c == m-1)
                    {
                        break;
                    }
                }
                else
                {
                    tmp = tmp->next;
                    i=i+1;
                }
            }
            cout<<"OUTPUT : "<<tmp->value <<endl<<endl;
        }
        else
        {
            return 0;
        }
    }
}

