class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        vector <int> v(nums.size(), 0);
        
        for(int i=0; i<nums.size(); i++){
            
            for(int j = 0; j<nums.size(); j++){
                
                int ans = nums[i];
                if(ans>nums[j])
                    v[i]++;
                
            }
            
        }
        return v;
    }
};