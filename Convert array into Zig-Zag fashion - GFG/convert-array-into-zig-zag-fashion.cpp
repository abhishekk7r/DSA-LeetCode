//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        vector<int> low;
        vector<int> high;
        
        sort(arr, arr+n);
        
        for(int i=0; i<=n/2; i++)
        {
            low.push_back(arr[i]);
        }
        
        for(int i=n/2; i<n; i++)
        {
            high.push_back(arr[i]);
        }
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<n){
            
            if ( j < low.size()){
                arr[i++] = low[j++];
            }
            
            if ( k < high.size()){
                arr[i++] = high[k++];
            }
        }
    }
};

//{ Driver Code Starts.

bool isZigzag(int arr[], int n){
    int f=1;
    
    for(int i=1; i<n; i++){
        if(f){
            if(arr[i-1]>arr[i]) return 0;
        }
        else{
            if(arr[i-1]<arr[i]) return 0;
        }
        f=f^1;
    }
    
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        bool check=1;
        check=isZigzag(arr,n);
        
        if(check) cout<<"1\n";
        else cout<<"0\n";
        
    }
    return 0;
}

// } Driver Code Ends