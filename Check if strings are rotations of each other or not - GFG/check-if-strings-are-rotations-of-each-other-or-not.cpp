//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n1 != n2)
            return 0;
        
        if(s1 == s2)
            return 1;
        
        while(n1 != 0){
            s1 = s1 + s1[0];
            s1.erase(0, 1);
            if(s1 == s2)
                return 1;
            
            n1--;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends