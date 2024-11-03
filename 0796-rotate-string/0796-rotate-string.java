class Solution {
    public boolean rotateString(String s, String goal) {
        String ans = s+s;
        if(goal.length() < s.length()) return false;

        return ans.contains(goal);
    }
}