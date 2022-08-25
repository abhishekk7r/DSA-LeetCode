class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
    int arrSum = 0; int ans=0;
        int n = nums.size();
        int sum = n*(n+1)/2;
    for(int i=0; i<n; i++){
        arrSum += nums[i];
    }
    ans = sum-arrSum;
    return ans;
    }
};