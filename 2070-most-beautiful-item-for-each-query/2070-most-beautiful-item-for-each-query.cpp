class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> mp;

        for(auto &i:items){
            mp[i[0]] = max(mp[i[0]], i[1]);
        }

        vector<int> ans;

        for(auto &i:queries)
        {
            if(mp.find(i) != mp.end()){
                ans.push_back(mp[i]);
            } else {
                auto it = mp.lower_bound(i);
                if (it == mp.begin()) {
                    ans.push_back(0);
                } else {
                    it--;
                    ans.push_back(it->second);
                }
            }
        }


        return ans;


    }
};