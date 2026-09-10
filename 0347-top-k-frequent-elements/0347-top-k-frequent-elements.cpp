class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for(auto i:nums){
            mp[i]++;
            maxFreq = max(maxFreq, mp[i]);
        }

        vector<vector<int>> bucket(maxFreq + 1);

        for(auto &[key, v]:mp){
            bucket[v].push_back(key);
        }

        vector<int> ans;

        for(int i=maxFreq; i >= 0; i--){
            if(bucket[i].size() > 0 && k > 0){
                for(auto key:bucket[i]){
                    k--;
                    ans.push_back(key);
                } 
                
            }

        }

        return ans;
    }
};