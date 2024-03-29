//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    
	    int low = 0;
	    int high = n-1;
	    
	    int mid = low + (high - low)/ 2;
	    int maxi = -1;
	    while(low <= high)
	    {
	   
	        maxi = max(arr[mid], maxi);
	        
	        if(arr[mid] <= arr[mid+1]){
	            low = mid+1;
	        } else {
	            high = mid -1;
	        }
	        mid = low + (high - low)/ 2;
	    }
	    
	    return maxi;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends