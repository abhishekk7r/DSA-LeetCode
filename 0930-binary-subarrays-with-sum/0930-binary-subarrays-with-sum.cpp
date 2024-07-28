class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int i = 0, j = 0, sum = 0, count = 0;
        int n = nums.size();

        if(goal < 0) return 0;

        while(j<n){
            
            sum += nums[j];

            while(sum > goal && i < j){
                sum -= nums[i];
                i++;
            }

            if(sum <= goal) count += j - i +1;

            j++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int first = helper(nums,goal);
        int second = helper(nums,goal-1);

        return first - second;
    }
};