//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    public:

    vector<int> a1,a2;
    
    twoStacks()
    {
        
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        a1.push_back(x);
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        a2.push_back(x);
       
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(a1.size()==0)return -1;
        int t = a1.back();
        a1.pop_back();
        return t;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(a2.size()==0)return -1;
       int t = a2.back();
        a2.pop_back();
        return t;
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends