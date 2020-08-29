//Chaiwit Chowchainit
//5630300245
#include <iostream>
using namespace std;
struct Std{
  char name[30];
  float grade;
  int age;
} ;


int main ()
{
    struct Std engineer;
    struct Std *engptr;
    engptr =&engineer;
    cout<<"name : ";
    cin>>engptr->name;
    cout<<"grade : ";
    cin>>engptr->grade;
    cout<<"age : ";
    cin>>engptr->age;

    cout<<engptr->name<<" ";
    cout<<engptr->grade<<" ";
    cout<<engptr->age;
}
