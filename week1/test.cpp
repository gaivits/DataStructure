#include <iostream>

using namespace std;

int main()
{
    char crossword[4][4] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<crossword[i][j];
            if(j==0 or j==1 or j==2)
            {
                cout<<(" ")<<crossword[i][j]<<crossword[i][j+1];
            }
            if(j==0 or j==1)
            {
                cout<<(" ")<<crossword[i][j]<<crossword[i][j+1]<<crossword[i][j+2];
            }
            if(j==0)
            {
                cout<<(" ")<<crossword[i][j]<<crossword[i][j+1]<<crossword[i][j+2]<<crossword[i][j+3];
            }
            cout<<endl;
        }
    }

     for(int j=0;j<4;j++)
    {
        int i = 0;
            cout<<crossword[j][i];
            if(j!=0)
            {
                cout<<(" ")<<crossword[j][i]<<crossword[j-1][i+1];
            }
            if(j==2 or j==3)
            {
                cout<<(" ")<<crossword[j][i]<<crossword[j-1][i+1]<<crossword[j-2][i+2];
            }
            if(j==3)
            {
                cout<<(" ")<<crossword[j][i]<<crossword[j-1][i+1]<<crossword[j-2][i+2]<<crossword[j-3][i+3];
            }
            cout<<endl;

        }

}
