//Author: Ashish Verma
//D/T: 21-Aug-2014, 10:23PM
// Transpose of a matrix using return function

#include <iostream>
using namespace std;

#define ROW 3
#define COL 2

int **transpose(int **m);

int main()
{
    int **m = new int*[ROW];
    
    for(int i=0; i<ROW; i++)
    {
        m[i] = new int[COL];
    }
    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            cin>>m[i][j];
        }
    }
    
    int **t = transpose(m);
    
    for(int i=0; i<COL; i++)
    {
        for(int j=0; j<ROW; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

int **transpose(int **m)
{
    int **t = new int*[COL];
    
    for(int i=0; i<COL; i++)
    {
        t[i] = new int[ROW];
    }
    
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            t[j][i] = m[i][j];
        }
    }
    
    return t;
}
