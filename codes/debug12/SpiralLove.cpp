//Spiral love 

//namisha goyal, 17mi550, 8847615253
//parul, 17mi559, 8352065425 




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
       n--; 
        if (k<n) 
        { 
            for (j=m-2;j>=l;j--) 
            { 
                cout<<a[n][j]<<" ";
            } 
            m--; 
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
    cout<<"\n";
    return 0; 
}
