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
    void merge(int arr[], int s, int m, int e)
    {
        int len1 = m - s + 1;
        int len2 = e - m;
        
        int *first = new int[len1];
        int *second = new int[len2];
        
        int mainArrIdx = s;
        
        //copying the arrays
        for(int i=0; i<len1; i++){
            first[i] = arr[mainArrIdx++];
        }
        
        mainArrIdx = m + 1;
        for(int i=0; i<len2; i++){
            second[i] = arr[mainArrIdx++];
        }
        
        //Merge Two sorted array
        int idx1 = 0;
        int idx2 = 0;
        mainArrIdx = s;
        while(idx1 < len1 && idx2 < len2){
            if(first[idx1] < second[idx2]){
                arr[mainArrIdx++] = first[idx1++];
            } else {
                arr[mainArrIdx++] = second[idx2++];
            }
        }
        
        while(idx1 < len1){
           arr[mainArrIdx++] = first[idx1++]; 
        }
        
        while(idx2 < len2){
           arr[mainArrIdx++] = second[idx2++];
        }
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        if(s>=e){
            return;
        }
        int m = (s+e)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        
        merge(arr, s, m, e);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends