//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
    
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    
        return prev; // New head after reversal
    }
    
    // Function to merge two sorted linked lists in ascending order
    Node* mergeAscending(Node* list1, Node* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
    
        Node* merged = nullptr;
    
        if (list1->data <= list2->data) {
            merged = list1;
            merged->next = mergeAscending(list1->next, list2);
        } else {
            merged = list2;
            merged->next = mergeAscending(list1, list2->next);
        }
    
        return merged;
    }
    
public:
    // Function to merge two sorted linked lists in non-increasing order
    struct Node* mergeResult(Node* node1, Node* node2) {
        // Merge the lists in ascending order
        Node* mergedAsc = mergeAscending(node1, node2);
    
        // Reverse the merged list to get the non-increasing order
        Node* mergedResult = reverseList(mergedAsc);
    
        return mergedResult;
    } 
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends