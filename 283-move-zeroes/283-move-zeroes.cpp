class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        //First Approach
        
        /* vector <int> v;
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            } else {
                count++;
            }
        }
        for(int i=0; i<count; i++){
            v.push_back(0);
        }
        
        nums = v; */
        
        int i =0;
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};