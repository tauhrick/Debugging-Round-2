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
 
			if(k && !st.empty() && st.top() > x){
				st.pop();
				k--;
			}
			
 
		else if(k && !st.empty()){
			st.pop();
			k--;
		}
 
		else if(!st.empty()){
			st2.push(st.top());
			st.pop();
		}
 
		if(!st2.empty()){
			cout << st2.top() <<" ";
			st2.pop();
		}
		
		else
		{
			st.push(x);
		}
		if(!st2.empty()){
			cout << st2.top() <<" ";
			st2.pop();
		}
	
		
		}
	}
	
	cout<<endl;
	return 0;
}
