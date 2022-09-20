class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        // for(int i=0; i<nums.size(); i++)
        // {
        //     ans.push_back(nums[i]*nums[i]);
        // }
        // sort(ans.begin(), ans.end());
        
        
        int start = 0;
        int end = nums.size()-1;
        
        for(int i=end; i>=0; i--){
            if(abs(nums[end]) > abs(nums[start]))
                ans[i] = nums[end]*nums[end--];
            else 
                ans[i] = nums[start]*nums[start++];
        }
        return ans;
    }
};