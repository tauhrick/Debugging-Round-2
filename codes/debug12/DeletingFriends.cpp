//DELETING FRIENDS

//namisha goyal, 17mi550, 8847615253
//parul, 17mi559, 8352065425 

#include <bits/stdc++.h>
#include <stack>
using namespace std;
 
int main()
{
	int t, n, k, x;
	cin >> t;
	while(t--)
	{
		stack<int> st;
		stack<int> st2;
		cin>>n>>k;
		for(int i = 0; i<n; i++)
		{
			cin>>x;
 
			if(k && !st.empty() && st.top() < x){
				st.pop();
				k--;
			}
			st.push(x);
		}
 
		while(!st.empty()){
			st2.push(st.top());
			st.pop();
		}
 
		while(!st2.empty() && (n-k)>=0){
			cout << st2.top() <<" ";
			st2.pop();
			n--;
		}
		cout<<"\n";
	}

	return 0;
}

