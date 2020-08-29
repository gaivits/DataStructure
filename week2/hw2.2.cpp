#include<iostream>
using namespace std;
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *tail = NULL;
struct node *insert(struct node *head,int value)
{
    if(head == NULL && tail == NULL)
    {
        head = new node ;
        head->value = value;
        head->next = NULL;
        head->prev = NULL;
        tail = head ;
    }
    else
    {
        struct node *tmp = head;
        struct node *tmp0 = tail;
        if(tmp->value > value)
        {
            struct node *tmp2 = new node ;
            tmp2->value = value;
            tmp2->next = head;
            tmp2->prev = NULL;
            tmp->prev = tmp2;
            head = tmp2;
        }
        else if(tmp0->value < value)
        {
            struct node *tmp3 = new node;
            tmp3->value = value;
            tmp3->prev = tail;
            tmp0->next = tmp3;
            tmp3->next = NULL;
            tail = tmp3;
        }
        else
        {
            struct node *tmp = head;
            while(tmp != NULL)
            {
                struct node *tmp2 = new node ;
                tmp2->value = value;
                tmp2->next = NULL;
                if(tmp->value < tmp2->value && tmp->next->value > tmp2->value)
                {
                    tmp2->next = tmp->next;
                    tmp->next=tmp2;
                }
                tmp = tmp->next;
            }
        }
    }
    return head;
}
void print(struct node *head)
{
    struct node *tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
struct node *Delete(struct node *head,int x)
{
    struct node *tmp = head;
    struct node *tmp0 = tail;
    if(x == tmp->value)
    {
        head = tmp->next;
        head->prev = NULL;
        delete(tmp);
    }
    else if(x == tmp0->value)
    {
        tail = tmp0->prev;
        tail->next = NULL;
        delete(tmp0);
    }
    else
    {
        while(tmp != NULL)
        {
            if(x == tmp->value)
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }
            tmp = tmp->next;
        }
    }
    return head;
}
void find(struct node *head,int y)
{
    struct node *tmp = head;
    while(tmp != NULL)
    {
        if(y == tmp->value)
        {
            cout<<"Found !!"<<endl;
            break;
        }
        tmp = tmp->next;
    }
    if(tmp == NULL)
    {
        cout<<"Not Found !!"<<endl;
    }
    cout<<endl;
}
int count(struct node *head)
{
    struct node *tmp = head ;
    int c=0;
    while(tmp != NULL)
    {
        c=c+1;
        tmp = tmp->next;
    }
    return c;
}
void peinttailtohead()
{
    struct node *tmp0 = tail;
    while(tmp0 != NULL)
    {
        cout<<tmp0->value<<" ";
        tmp0 = tmp0->prev;
    }
    cout<<endl;
}
int main()
{
    struct node *head = NULL;
    int number ;
    int value;
    while(true)
    {
        cout<<"++++++++++ MENU +++++++++++++"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Print"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Find"<<endl;
        cout<<"5. Count number of link list"<<endl;
        cout<<"6. Print Tail To head"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Please Choose > ";
        cin>>number;

        switch(number)
        {
            case 1 :
            {
                cout<<"Please enter value :";
                cin>>value;
                cout<<endl;
                head = insert(head,value);
                break;
            }
            case 2:
            {
                if(head != NULL)
                {
                    cout<<endl;
                    print(head);
                    cout<<endl;
                    break;
                }
                else
                {
                    cout<<endl<<"NOT HAVE DATA"<<endl<<endl;
                    break;
                }
            }
            case 3:
            {
                int x;
                if(head != NULL)
                {
                    cout<<"Enter number :";
                    cin>>x;
                    head = Delete(head,x);
                    break;
                }
                else
                {
                    cout<<endl<<"NOT HAVE DATA"<<endl<<endl;
                    break;
                }
            }
            case 4:
            {
                if(head != NULL)
                {
                    int y;
                    cout<<"Enter number :";
                    cin>>y;
                    cout<<endl;
                    find(head,y);
                    break;
                }
                else
                {
                    cout<<endl<<"NOT HAVE DATA"<<endl<<endl;
                    break;
                }
            }
            case 5:
            {
                if(head != NULL)
                {
                    int c = count(head);
                    cout<<endl;
                    cout<<"link list have a "<<c<<" number"<<endl<<endl;
                    break;
                }
                else
                {
                    cout<<endl<<"NOT HAVE DATA"<<endl<<endl;
                    break;
                }
            }
            case 6 :
            {
                if(head != NULL)
                {
                    cout<<endl;
                    peinttailtohead();
                    cout<<endl<<endl;
                    break;
                }
                else
                {
                    cout<<endl<<"NOT HAVE DATA"<<endl<<endl;
                    break;
                }
            }
                 case 7:
            {
                return 0;
                break;
            }
            default:
            {
                cout<<endl<<"NOT HAVE FUNCTION" ;
                cout<<endl<<endl;
            }
        }

    }

}
