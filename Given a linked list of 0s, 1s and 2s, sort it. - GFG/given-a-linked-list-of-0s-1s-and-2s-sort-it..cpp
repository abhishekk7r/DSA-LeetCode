//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void sort(vector<int> &v){
        int low = 0;
        int mid = 0;
        int high = v.size() - 1;
        
        while(mid <= high){
            
            //case 1
            switch (v[mid]){
                case 0:
                    swap(v[low++], v[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(v[mid], v[high--]);
                    break;
            }
        }
    }   
    
    Node* segregate(Node *head) {
        
        vector<int> v;
        Node * temp = head;
        
        while(temp != NULL){
            
            v.push_back(temp->data);
            temp = temp -> next; 
        }
        
        sort(v);
        
        Node* ans = new Node(v[0]);
        Node* curr = ans;
        for(int i=1; i<v.size(); i++)
        {
            Node* newNode = new Node(v[i]);
            curr -> next = newNode;
            curr = curr -> next;
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends