#include<iostream>
using namespace std;

struct box
{
    int base;
    int power;
    struct box *next;
};
struct box *head = NULL;
int main()
{
    cout<<"INPUT : ";
    head = new box;
    cin>>head->base;
    cin>>head->power;
    head->next = NULL;
    struct box *tmp = head;
    struct box *run = head;
    struct box *run0 = head;
    if(head->base != -1 && head->power != -1)
    {
        while(head)
        {
            tmp = new box;
            cin>>tmp->base;
            cin>>tmp->power;
            run->next = tmp;
            run = run->next;
            if(tmp->base == -1 && tmp->power == -1)
            {
                cout<<"OUTPUT"<<endl;
                while(run0!=NULL)
                {
                    if(run0->base == 0)
                    {
                        run0 = run0->next;
                    }
                    if(run0->power == 0)
                    {

                        if(run0->next->base == -1 && run0->next->power == -1)
                        {
                            cout<<run0->base;
                            break;
                        }
                        else{
                           cout<<run0->base<<"+";
                        }

                    }
                    else
                    {
                        if(run0->next->base == -1 && run0->next->power == -1) // ถ้าค่า base และ power เป็น -1 ทั้งคู่
                        {
                            cout<<run0->base<<"X^"<<run0->power;
                            break;
                        }
                        else{
                            cout<<run0->base<<"X^"<<run0->power<<"+";
                        }
                    }
                    run0 = run0->next;
                }
            }
        }
    }
}
