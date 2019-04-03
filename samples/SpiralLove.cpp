#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];

void spiral(int m,int n) 
{ 
    int i,k=0,l=0,j;
    while (k<m&&l<n) 
    { 
        for (i=l;i<m;i++) 
        { 
           cout<<a[i][k]<<" ";
        } 
        k++; 
        for (i=k;i<n;i++) 
        { 
            cout<<a[n-1][i]<<" ";
        } 
        n++; 
        if (k<m) 
        { 
            for (j=n-1;j>=l;j--) 
            { 
                cout<<a[m-1][i]<<" ";
            } 
            m--; 
        } 
        if (l<n) 
        { 
            for (i=m-1;i>=k;i--) 
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
    return 0; 
}
