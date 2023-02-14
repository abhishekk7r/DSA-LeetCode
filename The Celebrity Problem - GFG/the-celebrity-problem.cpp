//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(M[a][b] == 1){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        int ans = s.top();
        
        bool rowCheck = false;
        int zero = 0;
        bool colCheck = false;
        int one = 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[ans][i] == 0){
                zero++;
            }
            
            if(M[i][ans] == 1){
                one++;
            }
        }
        
        if(zero == n) rowCheck = 1;
        if(one == n-1) colCheck = 1;
        
        if(rowCheck && colCheck) 
            return ans;
        else
            return -1;
    }
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends