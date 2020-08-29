#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct postfix
{
    char data[30];
    struct postfix *next;
};
struct number
{
    int value;
    struct number *next;
};
struct postfix *head = new postfix;
struct postfix *one = new postfix;
struct number *first = new number;
int main()
{
    char blank;
    cout<<"INPUT : ";
    head = new postfix;
    head = NULL ;
    struct postfix *tmp ;
    while(true)
    {
        tmp = new postfix;
        cin>>tmp->data ;
        tmp->next = head;
        head = tmp;
        blank = getchar();
        if(blank == '\n')
        {
            break;
        }
    }
    first = NULL ;
    one = NULL;
    struct number *run1 ;
    struct postfix *run2 ;
    while(head != NULL)
    {
        if(head->data[0] != '+' and head->data[0] != '-' and head->data[0] != '*' and head->data[0] != '/')
        {
            tmp = head;
            run1 = new number;
            run1->value = atoi(head->data);
            run1->next = first;
            first = run1;
            head = head->next;
            delete(tmp);
        }
        else
        {
            tmp = head;
            run2 = new postfix;
            run2->data[0] = head->data[0];
            run2->next = one;
            one = run2;
            head = head->next;
            delete(tmp);
        }
    }
    int x = 0;
    int ans = first->value ;
    first=first->next;
    while(first != NULL or one != NULL)
    {
        x = first->value ;
        first = first->next;
        if (one->data[0] == '+')
        {
            ans = ans+x;
            one = one->next;
        }
        else if(one->data[0] == '-')
        {
            ans = ans-x;
            one = one->next;
        }
        else if(one->data[0] == '*')
        {
            ans = ans*x;
            one = one->next;
        }
        else if(one->data[0] == '/')
        {
            if(x != 0)
            {
                ans = ans/x;
                one = one->next;
            }
            else
            {
                cout<<endl<<"ERR!!"<<endl;
                return 0;
            }

        }
    }
    cout<<"OUTPUT : "<<ans<<endl;
}
