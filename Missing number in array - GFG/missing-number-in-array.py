#User function Template for python3


class Solution:
    def missingNumber(self,array,n):
        sum = 0
        for i in range(n+1):
            sum += i
        
        temp = 0
        for i in array:
            temp += i
        
        ans = sum - temp
        return ans
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3




t=int(input())
for _ in range(0,t):
    n=int(input())
    a=list(map(int,input().split()))
    s=Solution().missingNumber(a,n)
    print(s)
# } Driver Code Ends