class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector <int> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            ans[nums[i]]++;
        }
        int a;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]>1)
                a= i;
        }
        return a;
    }
};