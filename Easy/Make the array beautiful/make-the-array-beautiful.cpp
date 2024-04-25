//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isNegative(int n)
    {
        if(n<0)return true;
        else return false;
    }
  
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> st;
        for(int i = 0 ;  i < arr.size() ;i++)
        {
            if(i==0)st.push(arr[i]);
            else if(st.empty())st.push(arr[i]);
            else{
                if(isNegative(arr[i]) and !isNegative(st.top()))
                {
                    st.pop();
                }
                else if(!isNegative(arr[i]) and isNegative(st.top()))
                {
                    st.pop();
                }
                else st.push(arr[i]);
            }
        }
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends