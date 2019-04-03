#include <iostream.h>
#include <stack>
Using namespace std;

int main()
{
	int t, n, k, x;
	stack <int> st; st2;
	while(t--)
	{
		cin>>n>>k;
		for(i = 0; i<n; i++)
		{
			cin<<x;

			while(k-- && !st.empty() && st.front() > x){
				st.pop();
				k--;
			}
			st.insert(x);

		while(k-- && !st.empty());{
			st.pop();
		}

		while(st.empty()){
			st2.insert(st.top());
			st.pop();
		}

		while(st2.empty()){
			cout << st2.top() <<" ";
			st2.pop();
		}
	}

	return 0;
}
