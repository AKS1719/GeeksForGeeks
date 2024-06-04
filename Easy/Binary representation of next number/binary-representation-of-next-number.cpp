//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int mark =0;
        for(int i = s.size()-1 ;i>=0;i--)
        {
            if(s[i]=='1')
            {
                s[i]='0';
            }
            else{
                mark =1;
                s[i]='1';
                break;
            }
        }
        if(mark==0)
        {
            return "1"+s;
        }
        string t="";
        mark = 0;
        for(int i = 0 ; i < s.size();i++)
        {
            
            if(s[i]=='1' || mark ==1){
                mark =1;
                t.push_back(s[i]);
            }
        }
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends