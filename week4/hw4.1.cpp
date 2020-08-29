#include<iostream>
#include<string>

using namespace std;
struct q
{
    string data;
    struct q *next;
};
struct q *tail = NULL ;
struct q *Enqueue(struct q *head,string data)
{
    if(head == NULL)
    {
        struct q *head = new q;
        head->data = data;
        head->next = NULL;
        tail = head;
        return head;
    }
    else
    {
        struct q *tmp = new q;
        tmp->data = data;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
        return head;
    }
}
struct q *Dequeue(struct q *head)
{
    if(head == NULL)
    {
        cout<<"NOT HAVE DATA!! "<<endl;
    }
    else
    {
        struct q *first = head;
        cout<<first->data<<endl;
        head = head->next;
        delete(first);
    }
    return head;
}

int main()
{
    struct q *head = NULL;
    int number;
    string data ;
    while(true)
    {
        cout<<"========MANU========"<<endl;
        cout<<"[1]Enqueue"<<endl;
        cout<<"[2]Dequeue"<<endl;
        cout<<"[3]Exit"<<endl;
        cout<<"PLESE CHOOSE NUMBER : ";
        cin>>number;
        switch(number)
        {
            case 1:
            {
                cout<<"INPUT DATA : ";
                cin>>data;
                head = Enqueue(head,data);
                break;
            }
            case 2:
            {
                head = Dequeue(head);
                break;
            }
            case 3:
            {
                return 0;
            }
            default :
            {
                cout<<"NOT HAVE FUNCTION"<<endl;
            }
        }
    }
}
