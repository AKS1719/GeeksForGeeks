//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    const int mod = 1e9+7;
    long long helper(int ind,int x, int n,int ans)
    {
        if(ind>n)return ans;
        int res =1;
        for(int i=1;i<=ind;i++)
        {
            res= (res*x++) %mod;
        }
        ans = (ans+res)%mod;
        helper(ind+1,x,n,ans);
    }
    long long sequence(int n){
        // code here
        int mod = 1e9+7;
        long long ans = 0;
        long long val = 1;
        for (int i = 1; i <= n; i++){
            long long curr = 1;
            for (int j = 1; j <= i; j++){
                curr = (curr * val)%mod;
                val++;
            }
            ans = (ans + curr)%mod;
        }
        return ans % mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends