class Solution {
public:
    
   long long int binarySearch(int n){
        int s = 0; long long int ans=-1;
        int e = n;
        long long int mid = s + (e-s)/2;
        while(s<=e){
            
             long long int sqaure = mid*mid;
            
            if(sqaure>n){
                e = mid-1;
            }else{
                ans = mid;
                s = mid+1;
            }
            
            if (sqaure==n){
                ans = mid;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return  binarySearch(x);
    }
};