class Solution {
public:
    void dfs(int index, int sum, int target, vector<vector<int>>& ans, vector<int> &path, vector<int>& candidates){

        if(target == sum){
            ans.push_back(path);
            return;
        }

        if(sum > target || index == candidates.size()) return;
        path.push_back(candidates[index]);
        dfs(index, sum + candidates[index], target, ans, path, candidates);

        path.pop_back();
        dfs(index + 1, sum, target, ans, path, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, 0, target, ans, path, candidates);
        return ans;
    }
};