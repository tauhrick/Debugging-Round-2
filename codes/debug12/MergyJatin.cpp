
//mergy jatin

//namisha goyal, 17mi550, 8847615253
//parul, 17mi559, 8352065425 


#include<bits/stdc++.h>
using namespace std;
int n,i,arr[100003],j,k;
void merge(int l,int m,int r) 
{ 
	int s1=m-l,s2=r-m+1, i, j, k; 
	int a1[s1+2],a2[s2+2];
	for(j=0;j<s2;j++) 
		a2[j]=arr[m+j];  
	for(i=0;i<s1;i++) 
		a1[i]=arr[l+i];
	i = 0;  
	j = 0;
	k = l;  
	while(i<s1&&j<s2) 
	{ 
		if(a1[i]<=a2[j]) 
		{ 
			arr[k]=a1[i]; 
			i++; 
		} 
		else
		{ 
			arr[k]=a2[j]; 
			j++; 
		} 
		k++;
	} 
	if (j>=s2) {
	while(i<s1) 
	{ 
		arr[k]=a1[i];  
		k++; 
		i++;
	} 
	}
	else if (i >= s1) {
	while(j<s2) 
	{ 
		arr[k]=a2[j];  
		k++; 
		j++;
	} 
	}
}
void msort(int l,int r) 
{ 
	if(l<r) 
	{ 
		int m=(l+r+1)/2; 
		//merge(l,m,r); 
		msort(l,m-1); 
		msort(m,r); 
		merge(l, m, r);
	} 
} 
int main() {
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	msort(0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" "; 
	cout<<"\n";
	return 0;
}
