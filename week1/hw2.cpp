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
struct Std s[5];

int main()
{
    for(int i=0 ; i<=4 ; i++)
    {
        cout<<"name : ";
        cin>>s[i].name;
        cout<<"grade : ";
        cin>>s[i].grade;
        cout<<"age : ";
        cin>>s[i].age;
    }
    for(int j=0 ; j<=4 ; j++)
    {
        cout<<s[j].name;
        cout<<(" ");
        cout<<s[j].grade;
        cout<<(" ");
        cout<<s[j].age<<endl ;
    }

}
