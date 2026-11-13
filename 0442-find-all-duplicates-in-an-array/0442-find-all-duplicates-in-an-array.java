class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        var ans = new ArrayList<Integer>();

        for(int i=0; i<nums.length; i++){
            int index = Math.abs(nums[i]);


            if(nums[index - 1] < 0){
                ans.add(Math.abs(nums[i]));
            } else {
                nums[index - 1] *= (-1);
            }
        }

        return ans;
    }
}