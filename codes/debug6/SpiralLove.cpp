#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];

void spiral(int n,int m) 
{ 
    int i,k=0,l=0,j;
    while (k<m&&l<n) 
    { 
        for (i=l;i<m;i++) 
        { 
           cout<<a[l][i]<<" ";
        } 
        l++; 
        for (i=l;i<n;i++) 
        { 
            cout<<a[i][m-1]<<" ";
        } 
        m--; 
	if (l<n) 
        { 
            for (i=m-1;i>=k;i--) 
            { 
                cout<<a[n-1][i]<<" ";
            } 
            n--;     
        }
        if (k<m) 
        { 
            for (j=n-1;j>=l;j--) 
            { 
                cout<<a[j][k]<<" ";
            } 
            k++;               
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
