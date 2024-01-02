//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long pref[n];
        pref[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i] = a[i] + pref[i - 1];
        }
        
        long long res = -1e14, minPref = 0;
        for (int i = 0, j = k - 1; j < n; i++, j++) {
            res = max(res, pref[j] - minPref);
            minPref = min(minPref, pref[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends