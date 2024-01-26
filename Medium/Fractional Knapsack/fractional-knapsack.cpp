//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> v;
        for(int i = 0; i < n; i++)
        {
            double val = (((1.0)*arr[i].value)/((1.0)*arr[i].weight));
            v.push_back({val,i});
        }
        
        sort(v.begin(), v.end(), [&](const pair<double, int>& a, const pair<double, int>& b) {
            if(a.first == b.first) {
                return arr[a.second].value < arr[b.second].value;
            }
            return a.first < b.first;
        });

        double ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(W <= 0) break;
            int ind = v[i].second;
            if(arr[ind].weight <= W)
            {
                ans += arr[ind].value;
            }
            else{
                ans += (1.0*W)*((1.0)*(v[i].first));
            }
            W -= min(arr[ind].weight,W);
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends