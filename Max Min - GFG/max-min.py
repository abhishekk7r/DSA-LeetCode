class Solution:
    def findSum(self,A,N): 
        #code here
        m = max(A)
        n = min(A)
        ans = m + n
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3



t=int(input())
for _ in range(0,t):
    n=int(input())
    a=list(map(int,input().split()))
    ob = Solution()
    print(ob.findSum(a,n))
# } Driver Code Ends