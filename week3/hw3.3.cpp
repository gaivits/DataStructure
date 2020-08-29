#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct infix
{
    char data[30];
    struct infix *next;
};
struct infix *head = new infix;
int main()
{
    char data[30] ;
    char blank ;
    int x;
    cout<<"INPUT : ";
    head = new infix;
    head = NULL ;
    struct infix *tmp ;
    while(true)
    {
        cin>>data ;
        if(data[0] != '+' and data[0] != '-' and data[0] != '*' and data[0]!= '/')
        {
            cout<<data<<" ";

        }
        else if((head == NULL) && (data[0] == '+' or data[0] == '-' or data[0] == '*' or data[0]== '/') )
        {
            tmp = new infix ;
            tmp->data[0] = data[0];
            tmp->next = head;
            head = tmp;
        }
        else if((head != NULL) && (head->data[0] == '+' or head->data[0] == '-') && (data[0] == '*' or data[0] == '/'))
        {
            tmp = new infix ;
            tmp->data[0] = data[0];
            tmp->next = head;
            head = tmp;
        }
        else if((head != NULL) && (head->data[0] == '+' or head->data[0] == '-') && (data[0] == '+' or data[0] == '-'))
        {
            cout<<head->data[0]<<" ";
            head->data[0] = data[0];
        }

        else if((head != NULL) && (head->data[0] == '*' or head->data[0] == '/') && (data[0] == '+' or data[0] == '-'))
        {
            cout<<head->data[0]<<" ";
            head->data[0] = data[0];
        }

        else if((head != NULL) && (head->data[0] == '*' or head->data[0] == '/') && (data[0] == '*' or data[0] == '/'))
        {
            cout<<head->data[0]<<" ";
            head->data[0] = data[0];
        }
        blank = getchar();
        if(blank == '\n')
        {
            break;
        }
    }
    if(head != NULL && (head->data[0] == '*' or head->data[0] == '/'))
            {
                cout<<head->data[0]<<" ";
                head = head->next;
                if( head!=NULL && (head->data[0] == '+' or head->data[0] == '-'))
                {
                    cout<<head->data[0]<<" ";
                    head = head->next;
                }
            }
    if(head != NULL)
    {
        cout<<head->data[0]<<" ";
    }
}

