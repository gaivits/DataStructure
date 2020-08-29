//Chaiwit Chowchainit
//5630300245
#include <iostream>
using namespace std;
char crossword[4][4]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=j;k<4;k++)
            {
                for(int l=j;l<=k;l++)
                {
                    cout<<crossword[i][l];
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }
  for(int i=0;i<4;i++)
        {
                for(int l=0;l<=i;l++)
                {
                        for(int j=0;j<=i-l;j++)
                        {
                                for(int k=0;k<=j;k++)
                                {
                                        cout<<crossword[i-k-l][0+k+l];
                                }
                                cout<<" ";
                        }
                        cout<<endl;
                }
        }
        for(int i=0;i<3;i++)
        {
                for(int l=0;l<3-i;l++)
                {
                        for(int j=0;j<3-l-i;j++)
                        {
                                for(int k=0;k<j+1;k++)
                                {
                                        cout<<crossword[3-k-l][1+i+k+l];
                                }
                                cout<<" ";
                        }
                        cout<<endl;
                }
        }
}

