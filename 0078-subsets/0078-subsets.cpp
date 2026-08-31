class Solution {
public:
    void backtrack(int index, vector<int> &path, vector<vector<int>> &ans, vector<int>& nums){
        //base case
        if(index == nums.size()){
            ans.push_back(path);
            return;
        }

        //Choice 1: We included the element
        path.push_back(nums[index]);
        backtrack(index + 1, path, ans, nums);
        
        //Choice 2: We excluded that element
        path.pop_back();
        backtrack(index + 1, path, ans, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, path, ans, nums);
        return ans;
    }
};