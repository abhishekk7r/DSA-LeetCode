//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int s, int e)
    {
        if(s >= e)
            return;
        
        int p = partition(arr, s, e);
        quickSort(arr, s, p-1);
        quickSort(arr, p+1, e);
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
         int pivot = arr[s];
         int cnt = 0;
         for(int i=s+1; i<=e; i++){
             if(arr[i] <= pivot)
                 cnt++;
         }
         
         int pvtIndex = s + cnt;
         swap(arr[pvtIndex], arr[s]);
         
         int i = s, j = e;
         while(i < pvtIndex && j > pvtIndex){
             
             while(arr[i] <= pivot)
                i++;
            
            while(arr[j] > pivot)
                j--;
            
            if(i < pvtIndex && j > pvtIndex){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
         }
         return pvtIndex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends