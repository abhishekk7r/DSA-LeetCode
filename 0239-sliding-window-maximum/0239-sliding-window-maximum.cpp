class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        map<int, int, greater<int>> mp;

        int start = 0, end = 0;

        while(end < k){
            mp[nums[end]]++;
            end++;
        }

        ans.push_back(mp.begin()->first);

        while(end < nums.size()){
            //Remove the element at start
            mp[nums[start]]--;
            if(mp[nums[start]] == 0) mp.erase(nums[start]);

            //Move Start Ahead
            start++;

            mp[nums[end]]++;
            end++;
            //get the maximum & add to answer
            ans.push_back(mp.begin()->first);
        }

        return ans;
    }
};