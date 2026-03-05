class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length/2;

        List<Integer> positives = new ArrayList<>();
        List<Integer> negatives = new ArrayList<>();

        for(int i=0; i<nums.length; i++){
            if(nums[i] < 0) negatives.add(nums[i]);
            else positives.add(nums[i]);
        }

        int j = 0, k = 0;

        for(int i=0; i<nums.length - 1; i+=2){
            nums[i] = positives.get(j);
            j++;
            nums[i+1] = negatives.get(k);
            k++;
        } 

        return nums;
    }
}