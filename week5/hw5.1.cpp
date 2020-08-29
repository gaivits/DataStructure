#include<iostream>

using namespace std;
struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *Insert(int value,struct tree *head)
{
    struct tree *bug = new tree;
    if(head == NULL)
    {
        bug->value = value;
        bug->left = NULL;
        bug->right = NULL;
        head = bug;
    }
    else
    {
        bug = head;
        if(value < bug->value)
        {
            bug->left = Insert(value,bug->left);
        }
        else if(value > bug->value)
        {
            bug->right = Insert(value,bug->right);
        }
    }
    return head;
}
void print_pre(struct tree *head)
{
    struct tree *bug = head;
    if(bug == NULL)
    {
        return;
    }
    else
    {
        cout<<bug->value<<" ";
        print_pre(bug->left);
        print_pre(bug->right);
    }
}
void Min(struct tree *head)
{
    struct tree *bug = head;
    if(bug == NULL)
    {
        return;
    }
    else
    {
        if(bug->left == NULL )
        {
            cout<<"MIN : "<<bug->value;
        }
        else
        {
            return (Min(bug->left));
        }
    }
}
void Max(struct tree *head)
{
	
    if(head == NULL)
    {
        return;
    }
    else
    {
        if(head->right == NULL)
        {
            cout<<"MAX : "<<head->value;
        }
        else
        {
            return(Max(head->right));
        }
    }
}
void prinf_leave(struct tree *head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        if(head->left == NULL && head->right == NULL)
        {
            cout<<head->value<<" ";
        }
        else
        {
            prinf_leave(head->left);
            prinf_leave(head->right);
        }
    }
}
int count_node(struct tree *head,int c)
{
    if(head == NULL)
    {
        return c;
    }
    else
    {
        c = c+1;
        c = count_node(head->left,c);
        c = count_node(head->right,c);
    }
    return c;
}


int main()
{
    int x;
    struct tree *head = NULL;
    while(true)
    {
        cout<<"========MENU========="<<endl;
        cout<<"[1]Insert"<<endl;
        cout<<"[2]Print Preorder"<<endl;
        cout<<"[3]Find min and FindMax"<<endl;
        cout<<"[4]Print Leave node"<<endl;
        cout<<"[5]EXIT"<<endl;
        cout<<"[6]Count node"<<endl;
        cout<<"PLEASE CHOOSE : ";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                int v;
                cout<<"PLESE INSERT DATA : ";
                cin>>v;
                head = Insert(v,head);
                break;
            }
            case 2:
            {
                if(head == NULL)
                {
                    cout<<"NOT HAVE DATA!!!"<<endl;
                    break;
                }
                else
                {
                    print_pre(head);
                    cout<<endl;
                    break;
                }
            }
            case 3:
            {
                Min(head);
                cout<<" ";
                Max(head);
                cout<<endl;
                break;
            }
            case 4:
            {
                prinf_leave(head);
                cout<<endl;
                break;
            }
            case 5:
            {
                return 0;
            }
            case 6:
            {
                int c = 0;
                c = count_node(head,c);
                cout<<c<<endl;
                break;
            }
            default:
            {
                cout<<"[!] NOT HAVE FUNCTION [!]"<<endl;
            }

        }
    }
}
