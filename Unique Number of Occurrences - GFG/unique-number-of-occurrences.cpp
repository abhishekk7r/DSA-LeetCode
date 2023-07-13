//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> temp;
        
        for(auto i:mp){
            temp.push_back(i.second);
        }
        
        unordered_map<int, int> mp2;
        
        for(int i=0; i<temp.size(); i++)
        {
            mp2[temp[i]]++;
        }
        
        for(auto i:mp2){
            if(i.second != 1){
                return false;
            }
        }
        
        return true;
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends