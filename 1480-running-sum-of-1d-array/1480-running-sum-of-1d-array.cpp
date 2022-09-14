class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> v;
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans += nums[i];
            v.push_back(ans);
        }
        return v;
    }
};