#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];

void spiral(int n,int m) 
{ 
    int i,k=0,l=0,j;
    while (k<n&&l<m) 
    { 
        for (i=l;i<m;i++) 
        { 
           cout<<a[k][i]<<" ";
        } 
        k++; 
        for (i=k;i<n;i++) 
        { 
            cout<<a[i][m-1]<<" ";
        } 
        m--; 
        if (k<n) 
        { 
            for (j=m-1;j>=l;j--) 
            { 
                cout<<a[n-1][j]<<" ";
            } 
            n--; 
        } 
        if (l<m) 
        { 
            for (i=n-1;i>=k;i--) 
            { 
                cout<<a[i][l]<<" ";
            } 
            l++;
        }         
    } 
} 
int main() 
{ 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    spiral(n,m);
    cout<<endl;
    return 0; 
}
