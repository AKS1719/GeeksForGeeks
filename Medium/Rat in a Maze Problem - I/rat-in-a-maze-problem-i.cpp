//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void rat(int i,int j,vector<vector<int>> &m, vector<string>& res, string s,int n){
        if(i<0 or j<0 or i>n-1 or j>n-1 or m[i][j]==0)return;
        if(i==n-1 and j==n-1)
        {
            res.push_back(s);
            return;
        }
        m[i][j]=0;
        rat(i+1,j,m,res,s+"D",n);
        rat(i-1,j,m,res,s+"U",n);
        rat(i,j+1,m,res,s+"R",n);
        rat(i,j-1,m,res,s+"L",n);
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<bool>> visited(n,vector<bool> (n,0)) ;
        rat(0,0,m,res,"",n);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends