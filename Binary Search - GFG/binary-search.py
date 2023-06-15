#User function template for Python

class Solution:	
	def binarysearch(self, arr, n, k):
		s = 0
		e = n-1
		mid = int((s+e) / 2)
		while(s<=e):
		    if(arr[mid] == k):
		        return mid
		    elif arr[mid] < k:
		        s = mid + 1
		    elif arr[mid] > k:
		        e = mid - 1
		    
		    mid = int((s+e) / 2)
		
		return -1


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int, input().strip().split(' ')))
        k=int(input())
        ob = Solution()
        print (ob.binarysearch(arr, n, k))


# } Driver Code Ends