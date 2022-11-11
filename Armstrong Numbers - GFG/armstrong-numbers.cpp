//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int sum = 0;
        int a=n;
        while(n!=0){
            int temp = n%10;
            sum += pow(temp, 3);
            n /= 10;
        }
        string str = "No";
        
        if( a == sum){
            str = "Yes";
            return str;
        }
        
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends