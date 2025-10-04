class Solution {
    public int maxArea(int[] height) {
        int answer = 0;
        int i = 0, j = height.length - 1;

        while(i < j){
            
            int left = height[i];
            int right = height[j];
            
            int width = j - i;
            int length = Math.min(left, right);

            answer = Math.max(answer, width*length);

            if(left < right) i++;
            else j--;
        }

        return answer;
    }
}