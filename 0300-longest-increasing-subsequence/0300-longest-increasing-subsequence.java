class Solution {
    private int solve(int[] nums, int prev_index, int index, int DP[][]){
        if(index == nums.length){
            return 0;
        }

        if(DP[index][prev_index + 1] != -1) return DP[index][prev_index + 1];

        //Not Pick case : Prev will remain same, next will move
        int notPick = 0 + solve(nums, prev_index, index+1, DP);
        int pick = Integer.MIN_VALUE;
        if(prev_index == -1 || nums[prev_index] < nums[index]){
            pick = 1 + solve(nums, index, index+1, DP);
        }

        DP[index][prev_index + 1] = Math.max(pick, notPick);
        return DP[index][prev_index + 1] ;
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int [][]DP = new int[n + 1][n + 1];

        for(var i : DP) Arrays.fill(i, -1);

        return solve(nums, -1, 0, DP);

    }
}