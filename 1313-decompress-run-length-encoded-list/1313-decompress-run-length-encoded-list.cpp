class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i+=2){
            int it = nums[i];
            while(it!=0){
                ans.push_back(nums[i+1]);
                it--;
            }
        }
        return ans;
    }
};