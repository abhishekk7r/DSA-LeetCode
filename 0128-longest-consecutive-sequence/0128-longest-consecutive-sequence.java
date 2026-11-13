class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> st = new HashSet<>();

        for(int x : nums){
            st.add(x);
        }

        int maxLen = 0;

        for(int x : st){
            if(!st.contains(x-1)) {
                int count = 1;
                int temp = x;
                while(st.contains(temp+1)){
                    count++;
                    temp++;
                }

                maxLen = Math.max(maxLen, count);
            }
        }

        return maxLen;
    }
}