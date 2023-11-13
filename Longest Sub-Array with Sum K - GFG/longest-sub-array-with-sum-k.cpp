//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int, int> mp;
        
        int sum = 0;
        int maxLen = 0;
        for(int i=0; i<N; i++)
        {
            sum += A[i];
            //case 1
            if(sum == k) {
                maxLen = max(maxLen, i+1);
            }
            
            if(mp.count(sum-k) > 0){
                maxLen = max(maxLen, i-mp[sum-k]);
            }
            
            if(mp.count(sum) == 0){
                mp[sum] = i;
            }
        }
        
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends