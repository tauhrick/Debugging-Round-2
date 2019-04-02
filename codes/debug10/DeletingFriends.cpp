#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
	int t, n, k, x;
	cin>>t;
	while(t--)
	{
	stack <int> st, st2;
		cin>>n>>k;
		for(int i = 0; i<n; i++)
		{
			cin>>x;
			 
			while(!st.empty() && st.top() < x and k > 0){
				st.pop();
				k--;
			}
			st.push(x);
		}
 
		while(!st.empty() and k > 0){
			st.pop();
			k--;
		}
 
		while(!st.empty()){
			st2.push(st.top());
			st.pop();
		}
 
		while(!st2.empty()){
			cout << st2.top() <<" ";
			st2.pop();
		}
	}
	cout << endl;

	return 0;
}
