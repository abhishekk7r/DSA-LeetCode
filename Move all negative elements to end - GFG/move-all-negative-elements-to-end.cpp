//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> p;
        vector<int> nv;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > 0){
                p.push_back(arr[i]);
            } else {
                nv.push_back(arr[i]);
            }
        }
        
        int i=0;
        while(i<p.size())
        {
            arr[i] = p[i++];
        }
        
        int j=0;
        while(j<nv.size())
        {
            arr[i++] = nv[j++];
        }
        
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends