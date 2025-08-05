class Solution {
    public boolean isPossible(int n, int [] nums, int sum, int [][] memo){
        if(sum == 0) return true;
        if(n == 0) return nums[0] == sum;
        
        //Return From Cache
        if(memo[n][sum] != -1) return memo[n][sum] == 1 ? true : false;
        //Taking element
        boolean notTake = isPossible(n - 1, nums, sum, memo);
        boolean take = false;

        if(nums[n] <= sum){
            take = isPossible(n - 1, nums, sum - nums[n], memo);
        }

        memo[n][sum] = (take || notTake) ? 1 : 0;
        return (memo[n][sum] == 1);
    }


    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum();

        //if sum is odd it cannot be divided into half
        if(sum%2 != 0) return false;
        int target = sum/2;
        int n = nums.length;

        int [][] memo = new int[n + 1][target + 1];
        for(int[] i:memo) Arrays.fill(i, -1);
        return isPossible(n - 1, nums, target, memo);
    }
}