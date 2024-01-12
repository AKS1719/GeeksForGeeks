//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here. 
        int n=q.size();
        stack<int>st;
        vector<int>v;
        
        for(int i=0;i<k;i++)
        {
            int x=q.front();
            st.push(x);
            q.pop();
        }
        
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        
        
        for(int i=k;i<n;i++)
        {
            v.push_back(q.front());
            q.pop();
        }
        
        //now add up all the elements
        
        for(int i=0;i<n;i++)
        {
            q.push(v[i]);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends