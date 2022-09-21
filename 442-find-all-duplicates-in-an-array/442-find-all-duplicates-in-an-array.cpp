class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
//         vector <int> ans();
//         vector <int> v;
//         for(int i=0; i<nums.size(); i++){
//             ans[nums[i]]++;
//         }
        
//         for(int i=0; i<ans.size(); i++){
//             if(ans[i]>1){
//                 v.push_back(i);
//             }
//         }
//         return v;
        
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for(auto & i:m){
            if(i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};