//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if( x == 1) return 1;
        long long ans = 0;
        long long s = 0;
        long long e = x;
        long long mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(mid*mid > x){
                e = mid - 1;
            } 
            
            if(mid*mid < x){
                ans = mid;
                s = mid + 1;
            }
            
            if(mid*mid == x){
                ans = mid;
                return mid;
            }
            mid = s + (e-s)/2;
                
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends