class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxRows = 0;
        for(auto &i:nums){
            mp[i]++;
            maxRows = max(maxRows, mp[i]);
        }

        vector<vector<int>> ans;
        for(int i=0; i<maxRows; i++){
            vector<int> temp;
            for(auto &i:mp){
                if(i.second){
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};