class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());

        for(int i=1; i<=n; i++){
            if(!st.contains(i)) return i;
        }
        
        return n + 1;
    }
};