//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;
    while(curr != NULL)
    {
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        /*Node* temp = first;
        long long int digit1 = 0;
        long long int digit2 = 0;
        while(temp!=NULL)
        {
            digit1 = (digit1*10) + temp -> data;
            temp = temp -> next;
        }
         
        temp = second;
        while(temp!=NULL)
        {
            digit2 = (digit2*10) + temp -> data;
            temp = temp -> next;
        }
        
        long long int ans = digit1 + digit2;
        
        //dummy node
        Node* dummy = new Node(-1);
        Node* head = dummy;
        
        while(ans!=0)
        {
            int digit = ans % 10;
            Node* curr = new Node(digit);
            dummy -> next = curr;
            dummy = dummy -> next;
            ans /= 10;
        }
        
        head = head -> next;
        head = reverse(head);
        return head; */
        
        Node* node1 = reverse(first);
        Node* node2 = reverse(second);
        Node* dummy = new Node(-1);
        Node* head = dummy;
        
        int carry = 0;
        while(node1 != NULL && node2 != NULL)
        {
            int sum = (node1->data) + (node2->data) + carry;
            int rem = sum%10;
            Node* curr = new Node(rem);
            dummy -> next = curr;
            dummy = dummy -> next;
            carry = sum/10;
            node1 = node1 -> next;
            node2 = node2 -> next;
        }
        
        while(node1 != NULL){
            int sum = (node1->data) + carry;
            int rem = sum%10;
            Node* curr = new Node(rem);
            dummy -> next = curr;
            dummy = dummy -> next;
            carry = sum/10;
            node1 = node1 -> next;
        }
        
        while(node2 != NULL){
            int sum = (node2->data) + carry;
            int rem = sum%10;
            Node* curr = new Node(rem);
            dummy -> next = curr;
            dummy = dummy -> next;
            carry = sum/10;
            node2 = node2 -> next;
        }
        
        while(carry!=0)
        {
            int sum = carry;
            int rem = sum%10;
            Node* curr = new Node(rem);
            dummy -> next = curr;
            dummy = dummy -> next;
            carry = sum/10;   
        }
        
        head = head -> next;
        return reverse(head);
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends