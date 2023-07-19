//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
        if(i >= s1.size()) return 0;
        if(j >= s2.size()) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = 1 + solve(s1, s2, i+1, j+1, dp);
        } else {
            ans = max(solve(s1,s2,i+1,j,dp), solve(s1, s2, i, j+1, dp));
        }
        
        return dp[i][j] = ans;
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return solve(s1, s2, 0, 0, dp);
    }
    int longestPalinSubseq(string A) {
      string B = A;
      reverse(B.begin(), B.end());
      int n = A.size();
      int ans = lcs(n, n, A, B);
      return ans;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends