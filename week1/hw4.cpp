//Chaiwit Chowchainit
//5630300245
#include <iostream>
using namespace std;
struct Std
{
    char name[30];

    float grade;

    int age;
};
int main()
{
    Std s[5];
    Std *sptr;
    for(int i=0 ; i<=4 ; i++)
    {
        sptr = &s[i] ;
        cout<<"name : ";
        cin>>sptr->name;
        cout<<"grade : ";
        cin>>sptr->grade;
        cout<<"age : ";
        cin>>sptr->age;
    }
    for(int j=0 ; j<=4 ; j++)
    {
        sptr = &s[j] ;
        cout<<sptr->name;
        cout<<(" ");
        cout<<sptr->grade;
        cout<<(" ");
        cout<<sptr->age<<endl ;
    }
}
