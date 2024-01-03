//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        
        int n = S.length();
        
        int ans = n+1;
        
        for(int i = 0; i < n; i++)
        {
            int count[3] = {0};
            for(int j = i; j < n; j++)
            {
                count[S[j]-'0']++;
                
                if(count[0] > 0 && count[1] > 0 && count[2] > 0)
                {
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }
        
        return (ans == n+1) ? -1 : ans; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends