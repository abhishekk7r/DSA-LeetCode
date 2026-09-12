/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> solve(TreeNode* node){
        if(node == nullptr) return {0, 0};

        auto [leftRobbed, leftSkiped]  = solve(node -> left);
        auto [rightRobbed, rightSkiped] = solve(node -> right);

        int robbed = node -> val + leftSkiped + rightSkiped;
        int skipped = max(leftRobbed, leftSkiped) + max(rightRobbed, rightSkiped);

        return {robbed, skipped};
    }
    int rob(TreeNode* root) {
        auto [robbed, skipped] =  solve(root);

        return max(robbed, skipped);
    }
};