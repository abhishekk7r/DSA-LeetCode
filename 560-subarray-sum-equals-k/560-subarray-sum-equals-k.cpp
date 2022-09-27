class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum == k)
                count++;
            
            if(m.find(sum - k) != m.end())
                count = m[sum-k] + count;
            
            if(m.find(sum) != m.end()){
                m[sum]++;
            }else{
                m[sum]=1;
            }
            
        }
        return count;
    }
};