#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];

void spiral(int m,int n) 
{ 
    int i,k=0,l=0,j;
    while (k<m&&l<n) 
    {
        for (i=l;i<n;i++) 
        {
           cout<<a[k][i]<<" ";
        } 
        k++; 
        for (i=k;i<m;i++) 
        {
            cout<<a[i][n-1]<<" ";
        }  
	n--;
        if (k<m) 
        { 
            for (j=n-1;j>=l;j--) 
            {
                cout<<a[m-1][j]<<" ";
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
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    spiral(m,n); 
	cout<<"\n";
    return 0; 
}
