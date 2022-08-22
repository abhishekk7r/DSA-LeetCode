class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        long int tSum = 0; int leftSum=0; int rightSum=0;
        int ans=-1;
        
        for(int i =0 ; i<n; i++){
            tSum += nums[i];
        }
        rightSum = tSum; 
        for(int i=0; i<n; i++){
              rightSum = rightSum-nums[i];
            if(leftSum == rightSum){
                ans = i;
                break;
            } else {
                leftSum += nums[i];
                
            } 
        }
        return ans;
    }
};