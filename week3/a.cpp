#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{   char data[30];
    char blank;
    int x = 0;
    int ans = NULL ;
    cout<<"INPUT : ";
    while(true)
    {
        cin>>data;
        if(data[0] != '+' and data[0] != '-' and data[0] != '*' and data[0] != '/')
        {
            if(ans == NULL)
            {
                ans=atoi(data);
            }
            else
            {
                x = atoi(data);
            }
        }

        else if(data[0] == '+' or data[0] == '-' or data[0] == '*' or data[0] == '/')
        {
                if (data[0] == '+')
                {
                    ans = ans+x;
                }
                else if(data[0] == '-')
                {
                    ans = ans-x;
                }
                else if(data[0] == '*')
                {
                    ans = ans*x;
                }
                else if(data[0] == '/')
                {
                    ans = ans/x;
                }
        }
        blank = getchar();
        if(blank == '\n')
        {
            cout<<"OUTPUT : "<<ans<<endl;
            break;
        }

    }
}


