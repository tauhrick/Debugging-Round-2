#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
	int t, n, k, x;
	stack <int> st, st2;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i = 0; i<n; i++)
		{
			cin>>x;
 
			while(k && !st.empty() && st.top() < x){
				st.pop();
				k--;
			}
			st.push(x);
		}

		while(k-- && !st.empty()){
			st.pop();
		}
 
		while(!st.empty()){
			st2.push(st.top());
			st.pop();
		}
 
		while(!st2.empty()){
			cout << st2.top() <<" ";
			st2.pop();
		}
		cout<<"\n";
	}
	return 0;
}
