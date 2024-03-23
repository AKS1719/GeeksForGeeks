//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        const int mod = 1000000007;
        vector<int> res;
        if(n==1)return {0,1};
        res.push_back(0);
        res.push_back(1);
        for(int i=2 ;i<=n;i++)
        {
            res.push_back((res[i-1]+ 0ll + res[i-2])%mod);
        }
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends