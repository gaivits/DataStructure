#include<iostream>
using namespace std;

struct Stack
{
    int value ;
    struct Stack *next;
};
struct Stack *create(struct Stack *head)
{
    if(head == NULL)
    {
        head = new Stack ;
        head->next = NULL ;
        return(head);
    }
    else
    {
        cout<<endl<<"YOU HAVE OTHER STACK."<<endl;
    }
    return head ;
}
struct Stack *Push(struct Stack *head,int value)
{
    struct Stack *tmp = new Stack;
    tmp->value = value;
    tmp->next = head ;
    head = tmp;
    return head;
}

struct Stack *Pop(struct Stack *head)
{
        if (head->next == NULL)
        {
            cout<<endl<<"NOT HAVE VALUE IN STACK!!!"<<endl<<endl;
        }
        else
        {
            struct Stack *tmp = head ;
            cout<<endl<<head->value<<endl<<endl;
            head = head->next ;
            delete(tmp);
        }
    return head;
}
int main()
{

    struct Stack *head = NULL;
    int value;
    int num;
    while(true)
    {
        cout<<"====menu===="<<endl;
        cout<<"[1]Create Stack"<<endl;
        cout<<"[2]Push"<<endl;
        cout<<"[3]Pop"<<endl;
        cout<<"[4]Exit"<<endl;
        cout<<"Chose number :";
        cin>>num;

        switch(num)
            {
                case 1:
                {
                    head = create(head);
                    cout<<endl;
                    break;
                }
                case 2:
                {
                    if(head == NULL)
                    {
                        cout<<endl<<"PLEASE CREATE STACK FIRST."<<endl<<endl;
                    }
                    else
                    {
                        cout<<"Push number :";
                        cin>>value;
                        head = Push(head,value);
                        cout<<endl;
                    }

                    break;
                }
                case 3:
                {

                    if(head == NULL)
                    {
                        cout<<endl<<"PLEASE CREATE STACK FIRST."<<endl<<endl;
                    }
                    else
                    {
                        head = Pop(head);
                    }

                    break;
                }
                case 4:
                {
                    return 0;

                }
                default :
                {
                    cout<<endl<<"NOT HAVE FUNCTION."<<endl<<endl;
                }
        }
    }
}
