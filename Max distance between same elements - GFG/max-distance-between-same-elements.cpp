//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    //Code here
     int maxDistance = 0;
     unordered_map<int, int> umap;
     
     for(int i=0; i<n; i++){
         
        int t = arr[i]; //1
        
        if(umap.find(t)!=umap.end()){
            int temp = i - umap[t];
            maxDistance = max(temp, maxDistance);
        } else {
            umap[t] = i;
        }
     }
     return maxDistance;
    }
    
    // 1 - 0
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends